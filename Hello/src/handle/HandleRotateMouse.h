#ifndef HANDLE_ROTATE_MOUSE_H
#define HANDLE_ROTATE_MOUSE_H

#include "../graphlib/input/event/RotateMouseListener.h"
#include "../graphlib/shape/Shape3d.h"

class HandleRotateMouse : public RotateMouseListener {

private:
	Shape3d* shape;

public:
	HandleRotateMouse(Shape3d* shape);

	void rotate(float xRotAngle, float yRotAngle);

};

#endif