/*
 * Simulation.cpp
 *
 *  Created on: May 30, 2017
 *      Author: schutzekatze
 */

#include "Simulation.h"

#include "State.h"
using simulation::State;

namespace simulation {

thread *Simulation::main_thread = nullptr;
atomic<bool> Simulation::stop_flag(false);

void Simulation::start() {
	State::initialize();

	main_thread = new thread(simulation_main);
}

void Simulation::stop() {
	stop_flag = true;
	main_thread->join();
	delete main_thread;

	State::initialize();
}

void Simulation::simulation_main() {
    // Step executing loop
	unsigned step = 0;
	while (!stop_flag) {


		step++;

		if (step % STEPS_BEFORE_FLUSH == 0)
		{
			State::flush_steps_to_file();
		}

		if (step % STEPS_BEFORE_SNAPSHOT == 0)
		{
			State::save_snapshot_to_file();
		}
	}
}

} /* namespace simulation */
