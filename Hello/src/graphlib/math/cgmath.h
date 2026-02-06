#ifndef MATH_H
#define MATH_H

#include <glm/glm.hpp>

using glm::vec3;

namespace cgmath {

	vec3 sphericToCartesianCoordinates(const vec3& vect);

	vec3 normalVector(const vec3& v1, const vec3& v2, const vec3& v3);

	float radial(const vec3& v);

	float dist2d(float x1, float y1, float x2, float y2);

}

#endif