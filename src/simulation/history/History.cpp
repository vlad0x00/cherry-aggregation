/*
 * StepHistory.cpp
 *
 *  Created on: May 31, 2017
 *      Author: schutzekatze
 */

#include "History.h"

#include <fstream>
using std::ofstream;
using std::ios_base;

#include <RapidXML/rapidxml_print.hpp>
using namespace rapidxml;

#include "HistorySnapshot.h"
#include "HistoryStep.h"

#include "src/simulation/State.h"
using simulation::State;

namespace simulation {

namespace history {

xml_document<> History::steps_buffers[2];
unsigned History::buffer_in_use = 0;
unsigned History::total_step_counter = 0;

thread* History::steps_flushing_thread(nullptr);
atomic<bool> History::flush_running(false);

thread* History::snapshot_saving_thread(nullptr);
atomic<bool> History::snapshot_running(false);

void History::initialize() {
	ofstream steps_file(STEPS_FILENAME, ios_base::out);
	steps_file << "<" << STEPS_ROOT << ">\n\n";

	ofstream snapshots_file(SNAPSHOTS_FILENAME, ios_base::out);
	snapshots_file << "<" << SNAPSHOTS_ROOT << ">\n\n";
}

void History::finalize() {
	while (true) {
		flush_steps();

		State::acquire();

		if (steps_buffers[buffer_in_use].first_node() == nullptr) break;

		State::release();
	}

	if (steps_flushing_thread != nullptr) steps_flushing_thread->join();
	delete steps_flushing_thread;
	steps_flushing_thread = nullptr;

	if (snapshot_saving_thread != nullptr) snapshot_saving_thread->join();
	delete snapshot_saving_thread;
	snapshot_saving_thread = nullptr;

	ofstream steps_file(STEPS_FILENAME, ios_base::app);
	steps_file << "</" << STEPS_ROOT << ">";

	ofstream snapshots_file(SNAPSHOTS_FILENAME, ios_base::app);
	snapshots_file << "</" << SNAPSHOTS_ROOT << ">";
}

void History::add_step_new(const Byekt& byekt) {
	State::acquire();

	steps_buffers[buffer_in_use].append_node(
			HistoryStep::generate_step_new(steps_buffers[buffer_in_use], byekt)
	);

	total_step_counter++;

	if (total_step_counter % STEPS_BEFORE_FLUSH == 0) {
		flush_steps();
	}

	if (total_step_counter % STEPS_BEFORE_SNAPSHOT == 0) {
		save_snapshot();
	}

	State::release();
}

void History::add_step_move(const Byekt& byekt) {
	State::acquire();

	steps_buffers[buffer_in_use].append_node(
			HistoryStep::generate_step_move(steps_buffers[buffer_in_use], byekt)
	);

	total_step_counter++;

	if (total_step_counter % STEPS_BEFORE_FLUSH == 0) {
		flush_steps();
	}

	if (total_step_counter % STEPS_BEFORE_SNAPSHOT == 0) {
		save_snapshot();
	}

	State::release();
}

void History::flush_steps() {
	if (!flush_running.exchange(true))
	{
		if (steps_flushing_thread != nullptr) steps_flushing_thread->join();
		delete steps_flushing_thread;

		steps_flushing_thread = new thread(flush_steps_sequence);
	}
}

void History::flush_steps_sequence() {
	State::acquire();

	unsigned old_buffer = buffer_in_use;
	buffer_in_use++;
	buffer_in_use %= 2;

	State::release();

	ofstream output_file(STEPS_FILENAME, ios_base::app);

	output_file << steps_buffers[old_buffer];

	steps_buffers[old_buffer].clear();

	flush_running = false;
}

void History::save_snapshot() {
	if (!snapshot_running.exchange(true))
	{
		if (snapshot_saving_thread != nullptr) snapshot_saving_thread->join();
		delete snapshot_saving_thread;

		snapshot_saving_thread = new thread(save_snapshot_sequence);
	}
}

void History::save_snapshot_sequence() {
	State::acquire();

	xml_document<> *doc = HistorySnapshot::generate_snapshot(total_step_counter);

	State::release();

	ofstream output_file(SNAPSHOTS_FILENAME, ios_base::app);

	output_file << *doc;

    delete doc;

	snapshot_running = false;
}

} /* namespace history */

} /* namespace simulation */
