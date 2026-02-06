
#include "Sphere3d.h"

#include "../math/cgmath.h"

#include <numbers>
#include <vector>

using std::vector;

Sphere3d::Sphere3d(Shader& shader) : Shape3d(shader) {
	this->setDims(0.5, 12);
}

Sphere3d::~Sphere3d() {}
	

void Sphere3d::draw() {
	this->apply();

	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLES, 0, nVertexes);
}

#include <iostream>
using namespace std;

void Sphere3d::setDims(float radial, int divs) {
	vector<Vertex> vertexes;

	float PI_2 = 2 * std::numbers::pi;
	float inc = PI_2 / (float)divs;

	for (float y = 0; y < divs/2.0f; y++) {
		for (float x = 0; x < divs; x++) {
			float phi = y * inc;
			float theta = x * inc;

			vec3 p1 = cgmath::sphericToCartesianCoordinates(vec3(radial, theta, phi));
			vec3 p2 = cgmath::sphericToCartesianCoordinates(vec3(radial, theta + inc, phi));
			vec3 p3 = cgmath::sphericToCartesianCoordinates(vec3(radial, theta + inc, phi + inc));
			vec3 p4 = cgmath::sphericToCartesianCoordinates(vec3(radial, theta, phi + inc));

			vec3 n1 = 10.0f * cgmath::normalVector(p1, p2, p3);
			if (p1 == p2)
				n1 = 10.0f * cgmath::normalVector(p1, p3, p4);
			
			vec3 n2 = -10.0f * n1;

			vec3 n3;
			if (cgmath::radial(n1) > cgmath::radial(n2)) {
				n3 = n1;
			} else {
				n3 = n2;
			}

			vertexes.push_back({ p1.x, p1.y, p1.z, n3.x, n3.y, n3.z });
			vertexes.push_back({ p2.x, p2.y, p2.z, n3.x, n3.y, n3.z });
			vertexes.push_back({ p3.x, p3.y, p3.z, n3.x, n3.y, n3.z });

			vertexes.push_back({ p1.x, p1.y, p1.z, n3.x, n3.y, n3.z });
			vertexes.push_back({ p3.x, p3.y, p3.z, n3.x, n3.y, n3.z });
			vertexes.push_back({ p4.x, p4.y, p4.z, n3.x, n3.y, n3.z });
		}
	}

	nVertexes = vertexes.size();

	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, vertexes.size() * sizeof(Vertex), vertexes.data(), GL_STATIC_DRAW);

	glBindVertexArray(vao);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
}