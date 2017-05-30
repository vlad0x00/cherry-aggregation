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

	static const double DEFAULT_RADIUS = 5.0;

	Byekt(): radius(DEFAULT_RADIUS) {}
	Byekt(double radius): radius(radius) {}

	void set_position(const Vector3d &position) { this->position = position; }
	Vector3d& get_position() const { return position; }

	void set_velocity(const Vector3d &velocity) { this->velocity = velocity; }
	Vector3d& get_velocity() const { return velocity; }

	virtual ~Byekt() {}

private:

	double radius;
	Vector3d position;
	Vector3d velocity;

};

} /* namespace physics */

#endif /* PHYSICS_BYEKT_H_ */
