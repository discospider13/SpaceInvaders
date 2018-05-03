#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <gl/glew.h>

using namespace std;

class Shader {
public:
	unsigned int id;

	Shader(const char* vertexPath, const char* fragmentPath, const char* geometryPath = nullptr) {
		string vertexCode;
		string fragmentCode;

		ifstream v_shader_file;
		ifstream f_shader_file;

		try {
			v_shader_file.open(vertexPath);
			f_shader_file.open(fragmentPath);

			stringstream v_shader_stream, f_shader_stream;
			v_shader_stream << v_shader_file.rdbuf();
			f_shader_stream << f_shader_file.rdbuf();

			v_shader_file.close();
			f_shader_file.close();
		}
		catch (ifstream::failure e) {
			cout << "Shader file not read correctly" << endl;
		}

		const char* v_shader_code = vertexCode.c_str();
		const char* f_shader_code = fragmentCode.c_str();

		unsigned int vertex, fragment;
		int success;

		vertex = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertex, 1, &v_shader_code, NULL);
		glCompileShader(vertex);
		
		fragment = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragment, 1, &f_shader_code, NULL);
		glCompileShader(fragment);

		id = glCreateProgram();
		glAttachShader(id, vertex);
		glAttachShader(id, fragment);
		glLinkProgram(id);

		glDeleteShader(vertex);
		glDeleteShader(fragment);
	}

	void useShader() {
		glUseProgram(id);
	}

	/*void setBool(const string &name, bool value) const
	{
		glUniform1i(glGetUniformLocation(id, name.c_str()), (int)value);
	}
	// ------------------------------------------------------------------------
	void setInt(const string &name, int value) const
	{
		glUniform1i(glGetUniformLocation(id, name.c_str()), value);
	}
	// ------------------------------------------------------------------------
	void setFloat(const string &name, float value) const
	{
		glUniform1f(glGetUniformLocation(id, name.c_str()), value);
	}
	// ------------------------------------------------------------------------
	void setVec2(const string &name, const vec2 &value) const
	{
		glUniform2fv(glGetUniformLocation(id, name.c_str()), 1, &value[0]);
	}
	void setVec2(const string &name, float x, float y) const
	{
		glUniform2f(glGetUniformLocation(id, name.c_str()), x, y);
	}
	// ------------------------------------------------------------------------
	void setVec3(const string &name, const vec3 &value) const
	{
		glUniform3fv(glGetUniformLocation(id, name.c_str()), 1, &value[0]);
	}
	void setVec3(const string &name, float x, float y, float z) const
	{
		glUniform3f(glGetUniformLocation(id, name.c_str()), x, y, z);
	}
	// ------------------------------------------------------------------------
	void setVec4(const string &name, const vec4 &value) const
	{
		glUniform4fv(glGetUniformLocation(id, name.c_str()), 1, &value[0]);
	}
	void setVec4(const string &name, float x, float y, float z, float w)
	{
		glUniform4f(glGetUniformLocation(id, name.c_str()), x, y, z, w);
	}
	// ------------------------------------------------------------------------
	void setMat2(const string &name, const mat2 &mat) const
	{
		glUniformMatrix2fv(glGetUniformLocation(id, name.c_str()), 1, GL_FALSE, &mat[0][0]);
	}
	// ------------------------------------------------------------------------
	void setMat3(const string &name, const mat3 &mat) const
	{
		glUniformMatrix3fv(glGetUniformLocation(id, name.c_str()), 1, GL_FALSE, &mat[0][0]);
	}
	// ------------------------------------------------------------------------
	void setMat4(const string &name, const mat4 &mat) const
	{
		glUniformMatrix4fv(glGetUniformLocation(id, name.c_str()), 1, GL_FALSE, &mat[0][0]);
	}*/
};

#endif

