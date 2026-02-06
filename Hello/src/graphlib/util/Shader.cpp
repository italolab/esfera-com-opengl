
#include "Shader.h"

#include <fstream>
#include <sstream>
#include <iostream>

using std::cout;
using std::endl;
using std::stringstream;
using std::ifstream;

Shader::Shader(string fileVS, string fileFS) {
	this->vertexShaderSource = this->readFileContent(fileVS);
	this->fragmentShaderSource = this->readFileContent(fileFS);
		
	const char* vsSource = this->vertexShaderSource.c_str();
	const char* fsSource = this->fragmentShaderSource.c_str();

	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vsSource, NULL);
	glCompileShader(vertexShader);
	checkShaderCompileErrors(vertexShader, "VERTEX");

	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fsSource, NULL);
	glCompileShader(fragmentShader);
	checkShaderCompileErrors(fragmentShader, "FRAGMENT");

	program = glCreateProgram();
	glAttachShader(program, vertexShader);
	glAttachShader(program, fragmentShader);
	glLinkProgram(program);
	checkProgramCompileErrors(program);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

void Shader::use() {
	glUseProgram(program);
}

void Shader::setVec3(const string& name, glm::vec3& vect) {
	GLint loc = getUniformLocation(name);
	glUniform3fv(loc, 1, &vect[0]);
}

void Shader::setVec4(const string& name, glm::vec4& vect) {
	GLint loc = getUniformLocation(name);
	glUniform4fv(loc, 1, &vect[0]);
}

void Shader::setMat4(const string& name, glm::mat4& mat) {
	GLint loc = getUniformLocation(name);
	glUniformMatrix4fv(loc, 1, GL_FALSE, &mat[0][0]);
}

GLint Shader::getUniformLocation(const string& name) {
	GLint loc = glGetUniformLocation(program, name.c_str());
	//if (loc == -1)
	//	cout << "UniformLocation not found: " << name << endl;
	return loc;
}

void Shader::checkShaderCompileErrors(GLuint shader, string type) {
	GLint success;
	GLchar infoLog[1024];
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(shader, 1024, NULL, infoLog);
		cout << "ERROR::SHADER_COMPILATION of type: " << type << "\n" << infoLog << endl;
	}
}

void Shader::checkProgramCompileErrors(GLuint program) {
	GLint success;
	GLchar infoLog[1024];
	glGetProgramiv(program, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(program, 1024, NULL, infoLog);
		cout << "ERROR::PROGRAM_COMPILATION: " << "\n" << infoLog << endl;
	}
}

string Shader::readFileContent(string file) {
	ifstream ifs(file);

	stringstream ss;

	try {
		ifs.open(file);
		if (!ifs.is_open()) {
			cout << "ERROR::SHADER::FILE_NOT_FOUND: " << file << endl;
			return "ERROR";
		}

		ss << ifs.rdbuf();

		ifs.close();

		return ss.str();
	}
	catch (std::ifstream::failure& e) {
		cout << "ERROR::SHADER::FILE_NOT_FOUND: " << e.what() << endl;
		return "ERROR";
	}
}