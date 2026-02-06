
#include "Cubo3d.h"

Cubo3d::Cubo3d(Shader& shader) : Shape3d(shader) {
	this->setDims(0.3f, 0.4f, 0.5f);
}

Cubo3d::~Cubo3d() {}

void Cubo3d::draw() {
	this->apply();

	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLES, 0, 36);
}

void Cubo3d::setDims(float x, float y, float z) {
	float vertexes[] = {
		-x, -y, -z,  0.0f,  0.0f, -1.0f,
		 x, -y, -z,  0.0f,  0.0f, -1.0f,
		 x,  y, -z,  0.0f,  0.0f, -1.0f,
		 x,  y, -z,  0.0f,  0.0f, -1.0f,
		-x,  y, -z,  0.0f,  0.0f, -1.0f,
		-x, -y, -z,  0.0f,  0.0f, -1.0f,

		-x, -y,  z,  0.0f,  0.0f,  1.0f,
		 x, -y,  z,  0.0f,  0.0f,  1.0f,
		 x,  y,  z,  0.0f,  0.0f,  1.0f,
		 x,  y,  z,  0.0f,  0.0f,  1.0f,
		-x,  y,  z,  0.0f,  0.0f,  1.0f,
		-x, -y,  z,  0.0f,  0.0f,  1.0f,

		-x,  y,  z, -1.0f,  0.0f,  0.0f,
		-x,  y, -z, -1.0f,  0.0f,  0.0f,
		-x, -y, -z, -1.0f,  0.0f,  0.0f,
		-x, -y, -z, -1.0f,  0.0f,  0.0f,
		-x, -y,  z, -1.0f,  0.0f,  0.0f,
		-x,  y,  z, -1.0f,  0.0f,  0.0f,

		 x,  y,  z,  1.0f,  0.0f,  0.0f,
		 x,  y, -z,  1.0f,  0.0f,  0.0f,
		 x, -y, -z,  1.0f,  0.0f,  0.0f,
		 x, -y, -z,  1.0f,  0.0f,  0.0f,
		 x, -y,  z,  1.0f,  0.0f,  0.0f,
		 x,  y,  z,  1.0f,  0.0f,  0.0f,

		-x, -y, -z,  0.0f, -1.0f,  0.0f,
		 x, -y, -z,  0.0f, -1.0f,  0.0f,
		 x, -y,  z,  0.0f, -1.0f,  0.0f,
		 x, -y,  z,  0.0f, -1.0f,  0.0f,
		-x, -y,  z,  0.0f, -1.0f,  0.0f,
		-x, -y, -z,  0.0f, -1.0f,  0.0f,

		-x,  y, -z,  0.0f,  1.0f,  0.0f,
		 x,  y, -z,  0.0f,  1.0f,  0.0f,
		 x,  y,  z,  0.0f,  1.0f,  0.0f,
		 x,  y,  z,  0.0f,  1.0f,  0.0f,
		-x,  y,  z,  0.0f,  1.0f,  0.0f,
		-x,  y, -z,  0.0f,  1.0f,  0.0f
	};

	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexes), vertexes, GL_STATIC_DRAW);

	glBindVertexArray(vao);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
}