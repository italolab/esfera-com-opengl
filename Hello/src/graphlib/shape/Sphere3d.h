#ifndef SPHERE3D_H
#define SPHERE3D_H

#include "Shape3d.h"

class Sphere3d : public Shape3d {

private:
	GLuint vbo;
	GLuint vao;
	int nVertexes;

public:
	Sphere3d(Shader& shader);
	~Sphere3d();

	void draw();

	void setDims(float radial, int divs);

};

#endif