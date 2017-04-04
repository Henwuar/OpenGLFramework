#ifndef _TEXTURE_SHADER_H
#define _TEXTURE_SHADER_H

#include "Shader.h"

class TextureShader : public Shader
{
public:
	TextureShader();
	~TextureShader();
	
	void SendParameters(glm::mat4 mvpMatrix, GLint textureID);
	bool Init(const char* vs_fName, const char* fs_fName);
	
protected:
	bool InitAttributes();
	
	GLint m_u_texture;
};

#endif
