
#include "HandleRotateMouse.h"

HandleRotateMouse::HandleRotateMouse(Shape3d* shape) {
	this->shape = shape;
}

void HandleRotateMouse::rotate(float xRotAngle, float yRotAngle) {
	shape->addRotateX(xRotAngle);
	shape->addRotateY(yRotAngle);
}