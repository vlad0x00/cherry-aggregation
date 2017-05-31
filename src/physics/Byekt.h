/*
 * Byekt.h
 *
 *  Created on: May 30, 2017
 *      Author: schutzekatze
 */

#ifndef PHYSICS_BYEKT_H_
#define PHYSICS_BYEKT_H_

#include <Eigen/Dense>
using Eigen::Vector3d;

namespace physics {

class Byekt {

public:

	static constexpr double DEFAULT_RADIUS = 5.0;

	Byekt(): radius(DEFAULT_RADIUS) {}
	Byekt(double radius): radius(radius) {}

	Vector3d& get_position() { return position; }
	Vector3d& get_velocity() { return velocity; }

	virtual ~Byekt() {}

private:

	double radius;
	Vector3d position;
	Vector3d velocity;

};

} /* namespace physics */

#endif /* PHYSICS_BYEKT_H_ */
