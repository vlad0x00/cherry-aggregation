/*
 * Collision.h
 *
 *  Created on: Jun 2, 2017
 *      Author: schutzekatze
 */

#ifndef PHYSICS_COLLISION_H_
#define PHYSICS_COLLISION_H_

#include "Object.h"

#include <vector>
using std::vector;

namespace physics {

class Collision {

public:

	static Vector3d find_collision_point(vector<Object*>& obstacles, Object& projectile);

};

} /* namespace physics */

#endif /* PHYSICS_COLLISION_H_ */
