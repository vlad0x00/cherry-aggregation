/*
 * HistorySnapshot.cpp
 *
 *  Created on: Jun 1, 2017
 *      Author: schutzekatze
 */

#include "HistorySnapshot.h"

#include "src/physics/Byekt.h"
using physics::Byekt;

#include "src/simulation/State.h"
using simulation::State;

#include "NodeAttributeHelper.h"

namespace simulation {

namespace history {

xml_document<>* HistorySnapshot::generate_snapshot(unsigned total_step_counter) {
	xml_document<> *doc = new xml_document<>();

	xml_node<> *snapshot_node = doc->allocate_node(node_element, SNAPSHOT_NODE_NAME);

	NodeAttributeHelper::add_step_attribute(*doc, *snapshot_node, total_step_counter);

	xml_node<> *byekt_node;

	for(Byekt* byekt : State::blob_byekts) {
		byekt_node = doc->allocate_node(node_element, HistorySnapshot::BYEKT_NODE_NAME);

		NodeAttributeHelper::add_position_attributes(*doc, *byekt_node, *byekt);
		NodeAttributeHelper::add_radius_attribute(*doc, *byekt_node, *byekt);
		NodeAttributeHelper::add_id_attribute(*doc, *byekt_node, *byekt);

		snapshot_node->append_node(byekt_node);
	}

	if (State::new_byekt != nullptr) {
		byekt_node = doc->allocate_node(node_element, HistorySnapshot::BYEKT_NODE_NAME);

		NodeAttributeHelper::add_position_attributes(*doc, *byekt_node, *State::new_byekt);
		NodeAttributeHelper::add_radius_attribute(*doc, *byekt_node, *State::new_byekt);
		NodeAttributeHelper::add_id_attribute(*doc, *byekt_node, *State::new_byekt);

		snapshot_node->append_node(byekt_node);
	}

	doc->append_node(snapshot_node);

	return doc;
}

} /* namespace history */

} /* namespace simulation */
