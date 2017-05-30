/*
 * Simulation.h
 *
 *  Created on: May 30, 2017
 *      Author: schutzekatze
 */

#ifndef PHYSICS_SIMULATION_H_
#define PHYSICS_SIMULATION_H_

#include <thread>
using std::thread;

namespace physics {

class Simulation {

public:

	void start();
	void stop();

private:

	void simulation_main();

	thread *main_thread = nullptr;

};

} /* namespace physics */

#endif /* PHYSICS_SIMULATION_H_ */
