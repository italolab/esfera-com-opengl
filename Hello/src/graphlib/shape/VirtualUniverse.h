#ifndef VIRTUAL_UNIVERSE_H
#define VIRTUAL_UNIVERSE_H

#include <vector>

#include <glm/glm.hpp>

#include "Shape3d.h"

using std::vector;

class VirtualUniverse {

private:
	int screenWidth;
	int screenHeight;

	vec3 color;

	vector<Shape3d*> shapes;

public:
	VirtualUniverse(int width, int height);
	~VirtualUniverse();

	void init();
	void draw();
	void addShape3d(Shape3d* shape3d);

	void configureViewport();

	void setColor(const vec3& color);

	int getScreenWidth() const;
	int getScreenHeight() const;

};

#endif