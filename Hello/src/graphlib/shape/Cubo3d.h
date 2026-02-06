#ifndef CUBO3D_H
#define CUBO3D_H

#include "Shape3d.h"

class Cubo3d : public Shape3d {

private:
	GLuint vbo;
	GLuint vao;

public:
	Cubo3d(Shader& shader);
	~Cubo3d();

	void draw();

	void setDims(float x, float y, float z);
};

#endif