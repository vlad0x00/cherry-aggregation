/*
 * Step.h
 *
 *  Created on: May 31, 2017
 *      Author: schutzekatze
 */

#ifndef SIMULATION_HISTORYSTEP_H_
#define SIMULATION_HISTORYSTEP_H_

#include "src/physics/Object.h"
using physics::Object;

#include <RapidXML/rapidxml.hpp>
using namespace rapidxml;

namespace simulation {

namespace history {

class HistoryStep {

public:

	static constexpr char* STEP_NODE_NAME = "step";
	static constexpr char* MOVE_NODE_NAME = "move";
	static constexpr char* NEW_NODE_NAME = "new";

	static xml_node<>* generate_step_move(xml_document<>& doc, const Object& object);
	static xml_node<>* generate_step_new(xml_document<>& doc, const Object& object);

};

} /* namespace history */

} /* namespace simulation */

#endif /* SIMULATION_HISTORYSTEP_H_ */
