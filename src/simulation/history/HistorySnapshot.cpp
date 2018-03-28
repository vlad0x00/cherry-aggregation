/*
 * HistorySnapshot.cpp
 *
 *  Created on: Jun 1, 2017
 *      Author: schutzekatze
 */

#include "HistorySnapshot.h"

#include "src/physics/Object.h"
using physics::Object;

#include "src/simulation/State.h"
using simulation::State;

#include "NodeAttributeHelper.h"

namespace simulation {

namespace history {

xml_document<>* HistorySnapshot::generate_snapshot(unsigned total_step_counter) {
	xml_document<> *doc = new xml_document<>();

	xml_node<> *snapshot_node = doc->allocate_node(node_element, SNAPSHOT_NODE_NAME);

	NodeAttributeHelper::add_step_attribute(*doc, *snapshot_node, total_step_counter);

	xml_node<> *object_node;

	for(Object* object : State::blob_objects) {
		object_node = doc->allocate_node(node_element, HistorySnapshot::BYEKT_NODE_NAME);

		NodeAttributeHelper::add_position_attributes(*doc, *object_node, *object);
		NodeAttributeHelper::add_radius_attribute(*doc, *object_node, *object);
		NodeAttributeHelper::add_id_attribute(*doc, *object_node, *object);

		snapshot_node->append_node(object_node);
	}

	if (State::new_object != nullptr) {
		object_node = doc->allocate_node(node_element, HistorySnapshot::BYEKT_NODE_NAME);

		NodeAttributeHelper::add_position_attributes(*doc, *object_node, *State::new_object);
		NodeAttributeHelper::add_radius_attribute(*doc, *object_node, *State::new_object);
		NodeAttributeHelper::add_id_attribute(*doc, *object_node, *State::new_object);

		snapshot_node->append_node(object_node);
	}

	doc->append_node(snapshot_node);

	return doc;
}

} /* namespace history */

} /* namespace simulation */
