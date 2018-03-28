/*
 * HistoryStep.cpp
 *
 *  Created on: Jun 1, 2017
 *      Author: schutzekatze
 */

#include "HistoryStep.h"

#include "NodeAttributeHelper.h"

namespace simulation {

namespace history {

xml_node<>* HistoryStep::generate_step_move(xml_document<>& doc, const Object& object) {
	xml_node<>* node = doc.allocate_node(node_element, MOVE_NODE_NAME);

	NodeAttributeHelper::add_position_attributes(doc, *node, object);
	NodeAttributeHelper::add_id_attribute(doc, *node, object);

	return node;
}

xml_node<>* HistoryStep::generate_step_new(xml_document<>& doc, const Object& object) {
	xml_node<>* node = doc.allocate_node(node_element, NEW_NODE_NAME);

	NodeAttributeHelper::add_position_attributes(doc, *node, object);
	NodeAttributeHelper::add_radius_attribute(doc, *node, object);
	NodeAttributeHelper::add_id_attribute(doc, *node, object);

	return node;
}

} /* namespace history */

} /* namespace simulation */

