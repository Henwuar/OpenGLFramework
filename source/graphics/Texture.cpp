#include "Texture.h"
#include <iostream>

Texture::Texture()
{
}

Texture::~Texture()
{
	glDeleteTextures(1, &m_textureID);
}

bool Texture::LoadImage(char* filename)
{
	//load in the image
	int width = 0;
	int height = 0;
	int channels = 4;
	m_textureID = 0;
	/*m_textureID = SOIL_load_OGL_texture(
		filename,
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
		);*/

	if (m_textureID == 0)
	{
		//std::cerr << "SOIL loading error: " << SOIL_last_result() << std::endl;
		return false;
	}
	return true;
}
