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

#include <mutex>
using std::recursive_mutex;
using std::unique_lock;

namespace simulation {

class State {

public:

	static const unsigned BYEKTS_RESERVATION_SIZE = 1024;

	static void initialize();

	static inline void acquire() { state_mutex.lock(); }
	static inline void release() { state_mutex.unlock(); }

	static vector<Byekt*> blob_byekts;
	static Byekt* new_byekt;

private:

	static recursive_mutex state_mutex;

};

} /* namespace physics */

#endif /* SIMULATION_STATE_H_ */
