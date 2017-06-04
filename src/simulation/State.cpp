/*
 * State.cpp
 *
 *  Created on: May 31, 2017
 *      Author: schutzekatze
 */

#include "State.h"

namespace simulation {

vector<Byekt*> State::blob_byekts;
Byekt* State::new_byekt;

recursive_mutex State::state_mutex;

void State::initialize() {
	blob_byekts.reserve(BYEKTS_RESERVATION_SIZE);
}

} /* namespace physics */
