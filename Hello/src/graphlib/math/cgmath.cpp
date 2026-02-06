
#include "cgmath.h"

#include <cmath>

namespace cgmath {

	vec3 sphericToCartesianCoordinates(const vec3& vect) {
		return vec3(
			vect.x * sin(vect.z) * cos(vect.y),
			vect.x * sin(vect.z) * sin(vect.y),
			vect.x * cos(vect.z)
		);
	}

	vec3 normalVector(const vec3& p1, const vec3& p2, const vec3& p3) {
		vec3 a = p1 - p2;
		vec3 b = p3 - p2;

		return vec3(
			a.y*b.z - a.z*b.y,
			a.z*b.x - a.x*b.z,
			a.x*b.y - a.y*b.x
		);
	}

	float radial(const vec3& v) {
		return sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2));
	}

	float dist2d(float x1, float y1, float x2, float y2) {
		return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
	}

}