
#include "Mouse.h"

#include "../math/cgmath.h"

#include <numbers>

Mouse::Mouse() {
	this->x1 = -1;
	this->y1 = -1;
	this->x2 = -1;
	this->y2 = -1;
	this->mousePressed = false;

	this->rotateMouseListener = nullptr;
}

void Mouse::mouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
	if (button == GLFW_MOUSE_BUTTON_LEFT) {
		if (action == GLFW_PRESS) {
			mousePressed = true;
		}
		else if (action == GLFW_RELEASE) {
			mousePressed = false;
		}
	}
}

void Mouse::processMouse(GLFWwindow* window, int screenHeight) {
	if (mousePressed) {
		double xpos, ypos;
		glfwGetCursorPos(window, &xpos, &ypos);

		if (x1 == -1) {
			x1 = xpos;
			y1 = ypos;
		}
		else {
			x2 = xpos;
			y2 = ypos;

			float x = x2 - x1;
			float y = y2 - y1;
			float xfact = x / (float)screenHeight;
			float yfact = y / (float)screenHeight;

			float xRotAngle = yfact * std::numbers::pi;
			float yRotAngle = xfact * std::numbers::pi;

			x1 = xpos;
			y1 = ypos;

			if (rotateMouseListener != nullptr)
				rotateMouseListener->rotate(xRotAngle, yRotAngle);			
		}
	}
	else {
		x1 = -1;
		y1 = -1;
		x2 = -1;
		y2 = -1;
	}
}

void Mouse::setRotateMouseListener(RotateMouseListener* listener) {
	this->rotateMouseListener = listener;
}
