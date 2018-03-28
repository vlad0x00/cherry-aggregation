/*
 * Object.h
 *
 *  Created on: May 30, 2017
 *      Author: schutzekatze
 */

#ifndef PHYSICS_OBJECT_H_
#define PHYSICS_OBJECT_H_

#include <Eigen/Dense>
using Eigen::Vector3d;

namespace physics {

class Object {

public:

	static constexpr double DEFAULT_RADIUS = 5.0;

	long id = ++id_counter;
	double radius;
	Vector3d position;
	Vector3d velocity;

	Object(): radius(DEFAULT_RADIUS), position(Vector3d(0, 0, 0)), velocity(Vector3d(0, 0, 0)) {}
	Object(Vector3d position): radius(DEFAULT_RADIUS), position(position), velocity(Vector3d(0, 0, 0)) {}
	Object(Vector3d position, double radius): radius(radius), position(position), velocity(Vector3d(0, 0, 0)) {}
	Object(Vector3d position, double radius, Vector3d velocity):
		radius(radius),
		position(position),
		velocity(velocity) {}

	Object(const Object&) = delete;
	Object(const Object&&) = delete;

	Object& operator=(const Object&) = delete;
	Object& operator=(const Object&&) = delete;

private:

    static long id_counter;

};

} /* namespace physics */

#endif /* PHYSICS_OBJECT_H_ */
