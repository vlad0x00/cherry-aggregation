/*
 * Simulation.cpp
 *
 *  Created on: May 30, 2017
 *      Author: schutzekatze
 */

#include "Simulation.h"

#include "history/History.h"
using simulation::history::History;

#include "State.h"

#include "src/physics/Object.h"
#include <src/simulation/ObjectManager.h>
using physics::Object;

#include <thread>
using std::this_thread::sleep_for;

#include <Eigen/Dense>
using Eigen::Vector3d;

#include "src/physics/Collision.h"
using physics::Collision;

#include <cstdlib>
using std::rand;

#include <cmath>
using std::cos;
using std::sin;

namespace simulation {

thread *Simulation::main_thread(nullptr);
atomic<bool> Simulation::stop_flag(false);

void Simulation::start() {
	State::initialize();
	History::initialize();

	main_thread = new thread(simulation_main);
}

void Simulation::stop() {
	stop_flag = true;
	main_thread->join();
	delete main_thread;

	History::finalize();
}

void Simulation::simulation_main() {
	Vector3d origin, velocity;
	double phi, theta;
	const double pi = 3.14159265359, distance = 30000, velocity_magnitude = 30000;

	while (!stop_flag) {
		phi = 2 * ((double)rand()) / RAND_MAX * pi;
		theta = 2 * ((double)rand()) / RAND_MAX * pi;

		origin = Vector3d(
				sin(theta) * cos(phi) * distance,
				sin(theta) * sin(phi) * distance,
				cos(theta) * distance
				);

		velocity = Vector3d(Vector3d(0, 0, 0) - origin);
		velocity /= velocity.norm();
		velocity *= velocity_magnitude;

		State::acquire();

		Object* object = ObjectManager::create(
				origin,
				Object::DEFAULT_RADIUS,
				velocity);

		Vector3d collision_point =
				Collision::find_collision_point(State::blob_objects, *State::new_object);

		while (!stop_flag) {
			if ((collision_point - object->position).norm() <= object->velocity.norm()) {
				ObjectManager::move(object, collision_point);
				State::blob_objects.push_back(object);
				State::new_object = nullptr;
				break;
			}
			else {
				ObjectManager::apply_velocity(object);
			}
		}

		State::release();
	}
}

} /* namespace simulation */
