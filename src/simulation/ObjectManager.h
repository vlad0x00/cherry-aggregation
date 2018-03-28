/*
 * ObjectManager.h
 *
 *  Created on: May 31, 2017
 *      Author: schutzekatze
 */

#ifndef PHYSICS_OBJECTMANAGER_H_
#define PHYSICS_OBJECTMANAGER_H_

#include "src/physics/Object.h"

#include <Eigen/Dense>
using Eigen::Vector3d;

#include "State.h"

#include "history/History.h"
using simulation::history::History;

namespace simulation {

class ObjectManager {

public:

	static inline Object* create() {
		Object* object = new Object();

		State::new_object = object;
		History::add_step_new(*object);

		return object;
	}

	static inline Object* create(Vector3d position) {
		Object* object = new Object(position);

		State::new_object = object;
		History::add_step_new(*object);

		return object;
	}

	static inline Object* create(Vector3d position, double radius) {
		Object* object = new Object(position, radius);

		State::new_object = object;
		History::add_step_new(*object);

		return object;
	}

	static inline Object* create(Vector3d position, double radius, Vector3d velocity) {
		Object* object = new Object(position, radius, velocity);

		State::new_object = object;
		History::add_step_new(*object);

		return object;
	}

	static inline void apply_velocity(Object* object) {
		object->position += object->velocity;
		History::add_step_move(*object);
	}

	static inline void move(Object* object, Vector3d position) {
		object->position = position;
		History::add_step_move(*object);
	}

};

} /* namespace simulation */

#endif /* PHYSICS_OBJECTMANAGER_H_ */
