/*
 * Collision.cpp
 *
 *  Created on: Jun 2, 2017
 *      Author: schutzekatze
 */

#include <src/physics/Collision.h>

#include <vector>
using std::vector;

#include <algorithm>
using std::min_element;

#include <cmath>
using std::sqrt;
using std::fabs;

namespace physics {

bool check_collision(Byekt& projectile, Byekt& obstacle) {
	Vector3d direct(projectile.position - obstacle.position);
	Vector3d line_unit(projectile.velocity / projectile.velocity.norm());

	double projection_length = fabs(direct.dot(line_unit));
	Vector3d projection = line_unit * projection_length;

	Vector3d distance = direct + projection;

	if (distance.norm() < projectile.radius + obstacle.radius) {
		return true;
	}

	return false;
}

Vector3d Collision::find_collision_point(vector<Byekt*>& obstacles, Byekt& projectile) {
	vector<Byekt*> hit_byekts;
	Byekt* first_hit_byekt;

	for(Byekt* obstacle : obstacles) {
		if (check_collision(projectile, *obstacle)) {
			hit_byekts.push_back(obstacle);
		}
	}

	if (hit_byekts.empty()) {
		return Vector3d(0, 0, 0);
	}

	first_hit_byekt = *min_element(hit_byekts.begin(), hit_byekts.end(),
		[&projectile] (Byekt* b1, Byekt* b2) {
			return
					(projectile.position - b1->position).norm()
					<
					(projectile.position - b2->position).norm();
		}
	);

	Byekt& obstacle = *first_hit_byekt;

	Vector3d direct(projectile.position - obstacle.position);
	Vector3d line_unit(projectile.velocity / projectile.velocity.norm());

	double projection_length = fabs(direct.dot(line_unit));

	Vector3d projection = line_unit * projection_length;
	Vector3d distance = direct + projection;

	double radius_sum = projectile.radius + obstacle.radius;
	double collision_displacement = sqrt(radius_sum*radius_sum - distance.norm());

	Vector3d collision_point = projectile.position +
			(projection *
			((projection.norm() - collision_displacement) / projection.norm()));

	return collision_point;
}

} /* namespace physics */
