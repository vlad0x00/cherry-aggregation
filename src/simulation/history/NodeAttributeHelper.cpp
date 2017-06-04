/*
 * NodeAttributeHelper.cpp
 *
 *  Created on: Jun 1, 2017
 *      Author: schutzekatze
 */

#include <src/simulation/history/NodeAttributeHelper.h>

#include <cstdio>
using std::snprintf;

namespace simulation {

namespace history {

void NodeAttributeHelper::add_step_attribute(xml_document<>& doc, xml_node<>& node, unsigned step) {
	char buffer[64];

	snprintf(buffer, 64, "%u", step);

	node.append_attribute(doc.allocate_attribute(
			STEP_NAME,
			doc.allocate_string(buffer)
	));
}

void NodeAttributeHelper::add_position_attributes(xml_document<>& doc, xml_node<>& node, const Byekt& byekt) {
	char buffer_x[64];
	char buffer_y[64];
	char buffer_z[64];

	snprintf(buffer_x, 64, "%f", byekt.position.x());
	snprintf(buffer_y, 64, "%f", byekt.position.y());
	snprintf(buffer_z, 64, "%f", byekt.position.z());

	node.append_attribute(doc.allocate_attribute(
			BYEKT_X_NAME,
			doc.allocate_string(buffer_x)
	));

	node.append_attribute(doc.allocate_attribute(
			BYEKT_Y_NAME,
			doc.allocate_string(buffer_y)
	));

	node.append_attribute(doc.allocate_attribute(
			BYEKT_Z_NAME,
			doc.allocate_string(buffer_z)
	));
}

void NodeAttributeHelper::add_radius_attribute(xml_document<>& doc, xml_node<>& node, const Byekt& byekt) {
	char buffer[64];

	snprintf(buffer, 64, "%f", byekt.radius);

	node.append_attribute(doc.allocate_attribute(
			BYEKT_R_NAME,
			doc.allocate_string(buffer)
	));
}

void NodeAttributeHelper::add_id_attribute(xml_document<>& doc, xml_node<>& node, const Byekt& byekt) {
	char buffer[64];

	snprintf(buffer, 64, "%d", byekt.id);

	node.append_attribute(doc.allocate_attribute(
			BYEKT_ID_NAME,
			doc.allocate_string(buffer)
	));
}

} /* namespace history */

} /* namespace simulation */
