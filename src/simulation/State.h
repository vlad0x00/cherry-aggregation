/*
 * State.h
 *
 *  Created on: May 31, 2017
 *      Author: schutzekatze
 */

#ifndef SIMULATION_STATE_H_
#define SIMULATION_STATE_H_

#include <vector>
using std::vector;

#include "src/physics/Byekt.h"
using physics::Byekt;

#include <thread>
using std::thread;

namespace simulation {

class State {

public:

	static const unsigned BYEKTS_RESERVATION_SIZE = 1024;

	static void initialize();
	static void flush_steps_to_file();
	static void save_snapshot_to_file();
    static void finalize();

	static vector<Byekt> blob_byekts;
	static Byekt new_byekt;

	static thread *saving_thread;

};

} /* namespace physics */

#endif /* SIMULATION_STATE_H_ */
