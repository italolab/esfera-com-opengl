#ifndef SHAPE3D_H
#define SHAPE3D_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "../util/Shader.h"

using glm::vec3;
using glm::vec4;
using glm::mat4;

struct Vertex {
	float x, y, z;
	float nx, ny, nz;
};

class Shape3d {

private:
	vec3 objectColor;
	vec3 lightColor;

	vec3 lightPos;
	vec3 viewPos;

	vec3 cameraPos;
	vec3 cameraTarget;
	vec3 cameraUp;

	vec3 translates;
	vec3 rotates;
	vec3 scales;

	Shader* shader;
	void* vu;

protected:
	void apply();

public:
	Shape3d(Shader& shader);
	~Shape3d();

	virtual void draw() = 0;

	void addRotateX(float xang);
	void addRotateY(float yang);
	void addRotateZ(float zang);

	void addTranslateX(float x);
	void addTranslateY(float y);
	void addTranslateZ(float z);

	void addScaleX(float sx);
	void addScaleY(float sy);
	void addScaleZ(float sz);

	void setRotateX(float xang);
	void setRotateY(float yang);
	void setRotateZ(float zang);

	void setTranslateX(float x);
	void setTranslateY(float y);
	void setTranslateZ(float z);

	void setScaleX(float sx);
	void setScaleY(float sy);
	void setScaleZ(float sz);

	void setObjectColor(vec3& objectColor);

	void setVirtualUniverse(void* vu);
};

#endif