#ifndef SHADER_H
#define SHADER_H

#include <string>

#include <GL/glew.h>
#include <glm/glm.hpp>

using std::string;

class Shader {

private:
	GLuint program;

	string vertexShaderSource;
	string fragmentShaderSource;

	string readFileContent(string file);

	void checkShaderCompileErrors(GLuint shader, string type);
	void checkProgramCompileErrors(GLuint program);

	GLint getUniformLocation(const string& name);

public:
	Shader(string fileVS, string fileFS);

	void use();

	void setVec3(const string& name, glm::vec3& vect);
	void setVec4(const string& name, glm::vec4& vect);

	void setMat4(const string& name, glm::mat4& mat);

};

#endif