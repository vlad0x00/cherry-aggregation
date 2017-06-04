/*
 * HistorySnapshot.h
 *
 *  Created on: May 31, 2017
 *      Author: schutzekatze
 */

#ifndef SIMULATION_HISTORY_HISTORYSNAPSHOT_H_
#define SIMULATION_HISTORY_HISTORYSNAPSHOT_H_

#include <RapidXML/rapidxml.hpp>
using namespace rapidxml;

namespace simulation {

namespace history {

class HistorySnapshot {

public:

	static constexpr char* SNAPSHOT_NODE_NAME = "snapshot";
	static constexpr char* BYEKT_NODE_NAME = "byekt";

	static xml_document<>* generate_snapshot(unsigned total_step_counter);

};

} /* namespace history */

} /* namespace simulation */

#endif /* SIMULATION_HISTORY_HISTORYSNAPSHOT_H_ */
