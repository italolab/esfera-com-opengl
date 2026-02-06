#ifndef MOUSE_H
#define MOUSE_H

#include <GLFW/glfw3.h>

#include "event/RotateMouseListener.h"

class Mouse {

private:
	double x1;
	double y1;
	double x2;
	double y2;
	bool mousePressed;

	RotateMouseListener* rotateMouseListener;

public:
	Mouse();

	void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
	void processMouse(GLFWwindow* window, int screemHeight);

	void setRotateMouseListener(RotateMouseListener* listener);

};

#endif