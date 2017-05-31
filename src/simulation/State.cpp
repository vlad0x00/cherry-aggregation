/*
 * State.cpp
 *
 *  Created on: May 31, 2017
 *      Author: schutzekatze
 */

#include <src/simulation/State.h>

#include <RapidXML/rapidxml.hpp>
using namespace rapidxml;

namespace simulation {

vector<Byekt> State::blob_byekts;
Byekt State::new_byekt;

thread *State::saving_thread;

void State::initialize() {
	blob_byekts.reserve(BYEKTS_RESERVATION_SIZE);
}

void State::flush_steps_to_file() {

}

void State::save_snapshot_to_file() {

}

void State::finalize() {

}

} /* namespace physics */
