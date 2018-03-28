/*
 * State.cpp
 *
 *  Created on: May 31, 2017
 *      Author: schutzekatze
 */

#include "State.h"

namespace simulation {

vector<Object*> State::blob_objects;
Object* State::new_object;

recursive_mutex State::state_mutex;

void State::initialize() {
	blob_objects.reserve(BYEKTS_RESERVATION_SIZE);
}

} /* namespace physics */
