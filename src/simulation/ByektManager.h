/*
 * ByektManager.h
 *
 *  Created on: May 31, 2017
 *      Author: schutzekatze
 */

#ifndef PHYSICS_BYEKTMANAGER_H_
#define PHYSICS_BYEKTMANAGER_H_

#include "src/physics/Byekt.h"

#include <Eigen/Dense>
using Eigen::Vector3d;

#include "State.h"

#include "history/History.h"
using simulation::history::History;

namespace simulation {

class ByektManager {

public:

	static inline Byekt* create() {
		Byekt* byekt = new Byekt();

		State::new_byekt = byekt;
		History::add_step_new(*byekt);

		return byekt;
	}

	static inline Byekt* create(Vector3d position) {
		Byekt* byekt = new Byekt(position);

		State::new_byekt = byekt;
		History::add_step_new(*byekt);

		return byekt;
	}

	static inline Byekt* create(Vector3d position, double radius) {
		Byekt* byekt = new Byekt(position, radius);

		State::new_byekt = byekt;
		History::add_step_new(*byekt);

		return byekt;
	}

	static inline Byekt* create(Vector3d position, double radius, Vector3d velocity) {
		Byekt* byekt = new Byekt(position, radius, velocity);

		State::new_byekt = byekt;
		History::add_step_new(*byekt);

		return byekt;
	}

	static inline void apply_velocity(Byekt* byekt) {
		byekt->position += byekt->velocity;
		History::add_step_move(*byekt);
	}

	static inline void move(Byekt* byekt, Vector3d position) {
		byekt->position = position;
		History::add_step_move(*byekt);
	}

};

} /* namespace simulation */

#endif /* PHYSICS_BYEKTMANAGER_H_ */
