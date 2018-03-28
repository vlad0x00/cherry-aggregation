/*
 * NodeAttributeHelper.h
 *
 *  Created on: Jun 1, 2017
 *      Author: schutzekatze
 */

#ifndef SIMULATION_HISTORY_NODEATTRIBUTEHELPER_H_
#define SIMULATION_HISTORY_NODEATTRIBUTEHELPER_H_

#include "src/physics/Object.h"
using physics::Object;

#include <RapidXML/rapidxml.hpp>
using namespace rapidxml;

namespace simulation {

namespace history {

class NodeAttributeHelper {

public:

	static constexpr char* STEP_NAME = "step";

	static constexpr char* BYEKT_X_NAME = "x";
	static constexpr char* BYEKT_Y_NAME = "y";
	static constexpr char* BYEKT_Z_NAME = "z";

	static constexpr char* BYEKT_R_NAME = "r";
	static constexpr char* BYEKT_ID_NAME = "id";

	static void add_step_attribute(xml_document<>& doc, xml_node<>& node, unsigned step);

    static void add_position_attributes(xml_document<>& doc, xml_node<>& node, const Object& object);
    static void add_radius_attribute(xml_document<>& doc, xml_node<>& node, const Object& object);
    static void add_id_attribute(xml_document<>& doc, xml_node<>& node, const Object& object);

};

} /* namespace history */

} /* namespace simulation */

#endif /* SIMULATION_HISTORY_NODEATTRIBUTEHELPER_H_ */
