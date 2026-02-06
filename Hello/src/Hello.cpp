// Hello.cpp: define o ponto de entrada para o aplicativo.
//

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>
#include <numbers>

#include "graphlib/util/Shader.h"
#include "graphlib/shape/VirtualUniverse.h"
#include "graphlib/shape/Cubo3d.h"
#include "graphlib/shape/Sphere3d.h"

#include "graphlib/input/Mouse.h"

#include "graphlib/math/cgmath.h"

#include "handle/HandleRotateMouse.h"

const int WIDTH = 800;
const int HEIGHT = 600;

Mouse* mouse = new Mouse();
VirtualUniverse* vu = new VirtualUniverse(WIDTH, HEIGHT);

void processInput(GLFWwindow* window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);	
}

void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
	mouse->mouseButtonCallback(window, button, action, mods);
}

void framebufferSizeCallback(GLFWwindow* window, int width, int height) {
	vu->configureViewport();
}

//int WinMain() {
int main() {
	if (!glfwInit())
		return -1;

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Hello!", NULL, NULL);
	if (!window) {
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);
	glfwSetMouseButtonCallback(window, mouseButtonCallback );

	if (glewInit() != GLEW_OK) {
		glfwTerminate();
		std::cout << "Falha ao iniciar o GLEW." << std::endl;
		return -1;
	}

	glEnable(GL_DEPTH_TEST);

	Shader shader("struct/cubo.vs", "struct/cubo.fs");	

	Cubo3d* cubo = new Cubo3d(shader);
	cubo->setDims(0.25f, 0.25f, 0.25f);
	cubo->setTranslateX(0.6f);
	cubo->setTranslateY(0.6f);
	cubo->setRotateX(glm::radians(30.0f));
	cubo->setRotateY(glm::radians(30.0f));

	Sphere3d* sphere = new Sphere3d(shader);
	sphere->setDims(0.5f, 24);

	vu->setColor(glm::vec3(0.2f, 0.2f, 0.2f));
	
	vu->addShape3d(sphere);
	vu->addShape3d(cubo);

	vu->init();

	HandleRotateMouse* handleRotateMouse = new HandleRotateMouse(sphere);
	mouse->setRotateMouseListener(handleRotateMouse);

	while (!glfwWindowShouldClose(window)) {
		processInput(window);		
		
		mouse->processMouse(window, vu->getScreenHeight());
		//std::this_thread::sleep_for(std::chrono::milliseconds(30));
		
		vu->draw();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	
	return 0;
}
