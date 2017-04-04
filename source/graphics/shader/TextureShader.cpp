#include "TextureShader.h"
#include <iostream>

TextureShader::TextureShader()
{
}

TextureShader::~TextureShader()
{
	glDeleteProgram(m_program);
}

void TextureShader::SendParameters(glm::mat4 mvpMatrix, GLint textureID)
{
	glUniformMatrix4fv(m_u_transform, 1, GL_FALSE, glm::value_ptr(mvpMatrix));
	glActiveTexture(GL_TEXTURE0);
	glUniform1i(m_u_texture, 0);
	glBindTexture(GL_TEXTURE_2D, textureID);
}

bool TextureShader::Init(const char* vs_fName, const char* fs_fName)
{
	Shader::Init(vs_fName, fs_fName);
	
	InitAttributes();
	
	m_u_transform = glGetUniformLocation(m_program, "transform");
	if(m_u_transform == -1)
	{
		std::cerr << "Couldn't bind transform" << std::endl;
		return false;
	}
	return true;	
}

bool TextureShader::InitAttributes()
{
	 m_attributes = new GLuint[3];

	 //3D coordinate
	 m_attributes[ATTRIBUTE_COORD3D] = glGetAttribLocation(m_program, "coord3d");
	 if(m_attributes[ATTRIBUTE_COORD3D] == -1)
	 {
		 std::cerr << "failed to create coord3d" << std::endl;
		 return false;
	 }
   
	 //rgb colour
	 m_attributes[ATTRIBUTE_RGB] = glGetAttribLocation(m_program, "colour_rgb");
	 if(m_attributes[ATTRIBUTE_RGB] == -1)
	 {
		 std::cerr << "failed to create colour_rgb" << std::endl;
     
		 return false;
	 }

        //texture coordinate
	m_attributes[ATTRIBUTE_COORD2D] = glGetAttribLocation(m_program, "texcoord");
	if(m_attributes[ATTRIBUTE_COORD2D] == -1)
	{
		std::cerr << "failed to create texcoord\n";
		return false;
	}
}
