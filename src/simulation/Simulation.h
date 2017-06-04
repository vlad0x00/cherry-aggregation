/*
 * Simulation.h
 *
 *  Created on: May 30, 2017
 *      Author: schutzekatze
 */

#ifndef SIMULATION_SIMULATION_H_
#define SIMULATION_SIMULATION_H_

#include <thread>
using std::thread;

#include <atomic>
using std::atomic;

namespace simulation {

class Simulation {

public:

	static void start();
	static void stop();

private:

    static void simulation_main();

	static thread *main_thread;
    static atomic<bool> stop_flag;

};

} /* namespace simulation */

#endif /* SIMULATION_SIMULATION_H_ */
