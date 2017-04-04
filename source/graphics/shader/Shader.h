#ifndef SHADER_H
#define SHADER_H

#include <glad\glad.h>
#include <GLFW\glfw3.h>
#include <glm.hpp>
#include <gtc/type_ptr.hpp>
#include <fstream>

#define ATTRIBUTE_COORD2D 0
#define ATTRIBUTE_COORD3D 1
#define ATTRIBUTE_RGB 2
#define ATTRIBUTE_RGBA 3

class Shader
{
public:
	Shader();
	~Shader();

	bool Init(const char* vs_fName, const char* fs_fName);
	virtual void SendParameters(glm::mat4 transformMatrix);
	inline GLuint program() { return m_program; }
	inline GLuint attribute(int index) {return m_attributes[index];}
	
protected:
	GLuint CreateShader(const char* fName, GLenum type);
	const char* LoadShader(const char* fName);
	void PrintError(GLuint object);
	bool InitAttributes();

	GLuint m_vs, m_fs;
	GLuint m_program;
	GLuint* m_attributes;
	GLint m_u_transform;
	GLint m_texture_id;
	GLint m_u_texture;
};

#endif
