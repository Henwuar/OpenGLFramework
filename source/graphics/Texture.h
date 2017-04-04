#ifndef _TEXTURE_H
#define _TEXTURE_H

#include <GLFW\glfw3.h>

class Texture
{
public:
	Texture();
	~Texture();

	bool LoadImage(char* filename);

	inline GLuint ID(){return m_textureID;}
	
private:
	GLuint m_textureID;
};

#endif
