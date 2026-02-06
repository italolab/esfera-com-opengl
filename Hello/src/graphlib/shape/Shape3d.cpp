#include "Shape3d.h"

#include "VirtualUniverse.h"

Shape3d::Shape3d(Shader& shader) {
	this->vu = new VirtualUniverse(0, 0);
	this->shader = &shader;

	this->objectColor = vec3(1.0f, 0.0f, 0.0f);
	this->lightColor = vec3(1.0f, 1.0f, 1.0f);

	this->lightPos = vec3(-1.2f, -1.0f, -2.0f);
	this->viewPos = vec3(0.0f, 0.0f, 0.0f);

	this->cameraPos = vec3(0.0f, 0.0f, 3.0f);
	this->cameraTarget = vec3(0.0f, 0.0f, 0.0f);
	this->cameraUp = vec3(0.0f, 1.0f, 0.0f);

	this->rotates = vec3(0.0f, 0.0f, 0.0f);
	this->translates = vec3(0.0f, 0.0f, 0.0f);
	this->scales = vec3(1.0f, 1.0f, 1.0f);
}

Shape3d::~Shape3d() {}

void Shape3d::apply() {
	shader->use();

	int width = ((VirtualUniverse*)vu)->getScreenWidth();
	int height = ((VirtualUniverse*)vu)->getScreenHeight();

	mat4 view = glm::lookAt(this->cameraPos, this->cameraTarget, this->cameraUp);
	mat4 projection = glm::perspective(glm::radians(45.0f), (float)width / (float)height, 0.1f, 100.0f);

	mat4 model = mat4(1.0f);
	model = glm::translate(model, translates);
	model = glm::rotate(model, rotates.x, vec3(1.0f, 0.0f, 0.0f));
	model = glm::rotate(model, rotates.y, vec3(0.0f, 1.0f, 0.0f));
	model = glm::rotate(model, rotates.z, vec3(0.0f, 0.0f, 1.0f));
	model = glm::scale(model, scales);

	shader->setVec3("objectColor", this->objectColor);
	shader->setVec3("lightColor", this->lightColor);

	shader->setVec3("lightPos", this->lightPos);
	shader->setVec3("viewPos", this->viewPos);

	shader->setMat4("model", model);
	shader->setMat4("view", view);
	shader->setMat4("projection", projection);
}

void Shape3d::addRotateX(float xang) {
	this->rotates.x += xang;
}

void Shape3d::addRotateY(float yang) {
	this->rotates.y += yang;
}

void Shape3d::addRotateZ(float zang) {
	this->rotates.z += zang;
}

void Shape3d::addTranslateX(float x) {
	this->translates.x += x;
}

void Shape3d::addTranslateY(float y) {
	this->translates.y += y;
}

void Shape3d::addTranslateZ(float z) {
	this->translates.z += z;
}

void Shape3d::addScaleX(float sx) {
	this->scales.x += sx;
}

void Shape3d::addScaleY(float sy) {
	this->scales.y += sy;
}

void Shape3d::addScaleZ(float sz) {
	this->scales.z += sz;
}

void Shape3d::setRotateX(float xang) {
	this->rotates.x = xang;
}

void Shape3d::setRotateY(float yang) {
	this->rotates.y = yang;
}

void Shape3d::setRotateZ(float zang) {
	this->rotates.z = zang;
}

void Shape3d::setTranslateX(float x) {
	this->translates.x = x;
}

void Shape3d::setTranslateY(float y) {
	this->translates.y = y;
}

void Shape3d::setTranslateZ(float z) {
	this->translates.z = z;
}

void Shape3d::setScaleX(float sx) {
	this->scales.x = sx;
}

void Shape3d::setScaleY(float sy) {
	this->scales.y = sy;
}

void Shape3d::setScaleZ(float sz) {
	this->scales.z = sz;
}

void Shape3d::setObjectColor(vec3& color) {
	this->objectColor = color;
}

void Shape3d::setVirtualUniverse(void* vu) {
	this->vu = vu;
}