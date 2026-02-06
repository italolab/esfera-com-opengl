
#include "VirtualUniverse.h"

VirtualUniverse::VirtualUniverse(int width, int height) {
	this->screenWidth = width;
	this->screenHeight = height;
	this->color = vec3(0.1f, 0.1f, 0.1f);
}

VirtualUniverse::~VirtualUniverse() {}

void VirtualUniverse::init() {
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}

void VirtualUniverse::draw() {
	glClearColor(this->color.x, this->color.y, this->color.z, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	for (Shape3d* shape : shapes)
		shape->draw();
}

void VirtualUniverse::addShape3d(Shape3d* shape3d) {
	shape3d->setVirtualUniverse(this);
	shapes.push_back(shape3d);
}

void VirtualUniverse::configureViewport() {
	glViewport(0, 0, screenWidth, screenHeight);
}

void VirtualUniverse::setColor(const vec3& color) {
	this->color = color;
}

int VirtualUniverse::getScreenWidth() const {
	return screenWidth;
}

int VirtualUniverse::getScreenHeight() const {
	return screenHeight;
}