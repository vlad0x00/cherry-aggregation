/*
 * StepHistory.h
 *
 *  Created on: May 31, 2017
 *      Author: schutzekatze
 */

#ifndef SIMULATION_STATEHISTORY_H_
#define SIMULATION_STATEHISTORY_H_

#include <thread>
using std::thread;

#include "src/physics/Object.h"
using physics::Object;

#include <RapidXML/rapidxml.hpp>
using namespace rapidxml;

#include <atomic>
using std::atomic;

namespace simulation {

namespace history {

class History {

public:

	static const unsigned STEPS_BEFORE_FLUSH = 3001;
	static const unsigned STEPS_BEFORE_SNAPSHOT = 5000;

	static constexpr char* STEPS_FILENAME = "steps.xml";
	static constexpr char* STEPS_ROOT = "steps";

	static constexpr char* SNAPSHOTS_FILENAME = "snapshots.xml";
	static constexpr char* SNAPSHOTS_ROOT = "snapshots";

	static void initialize();
    static void finalize();

    static void add_step_new(const Object& object);
    static void add_step_move(const Object& object);

private:

	static void flush_steps();
	static void flush_steps_sequence();

	static void save_snapshot();
    static void save_snapshot_sequence();

    static xml_document<> steps_buffers[2];
    static unsigned buffer_in_use;
    static unsigned total_step_counter;

    static thread* steps_flushing_thread;
    static atomic<bool> flush_running;

    static thread* snapshot_saving_thread;
    static atomic<bool> snapshot_running;

};

} /* namespace history */

} /* namespace simulation */

#endif /* SIMULATION_STATEHISTORY_H_ */
