#include "Cube.h"

Cube::Cube() : Mesh::Mesh()
{
}

Cube::~Cube()
{
}

bool Cube::Init()
{
	m_numVertices = 36;
  	GLfloat vertices[] =
	{
		//front
		0.5, 0.5, -0.5,
		-0.5, 0.5, -0.5,
		0.5, -0.5, -0.5,
		-0.5, 0.5, -0.5,
		0.5, -0.5, -0.5,
		-0.5, -0.5, -0.5,
		//left
		-0.5, 0.5, 0.5,
		-0.5, -0.5, 0.5,
		-0.5, 0.5, -0.5,
		-0.5, -0.5, 0.5,
		-0.5, 0.5, -0.5,
		-0.5, -0.5, -0.5,
		//back
		0.5, 0.5, 0.5,
		-0.5, 0.5, 0.5,
		0.5, -0.5, 0.5,
		-0.5, 0.5, 0.5,
		0.5, -0.5, 0.5,
		-0.5, -0.5, 0.5,
		//right
		0.5, 0.5, 0.5,
		0.5, -0.5, 0.5,
		0.5, 0.5, -0.5,
		0.5, -0.5, 0.5,
		0.5, 0.5, -0.5,
		0.5, -0.5, -0.5,
		//top
		0.5, 0.5, 0.5,
		-0.5, 0.5, 0.5,
		0.5, 0.5, -0.5,
		0.5, 0.5, -0.5,
		-0.5, 0.5, -0.5,
		-0.5, 0.5, 0.5,
		//bottom
		0.5, -0.5, 0.5,
		-0.5, -0.5, 0.5,
		0.5, -0.5, -0.5,
		0.5, -0.5, -0.5,
		-0.5, -0.5, -0.5,
		-0.5, -0.5, 0.5,
	};

	glGenBuffers(1, &m_vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	GLfloat colours[108];
	for(int i = 0; i < 108; i++)
	{
		colours[i] = 1.0;
	}
	glGenBuffers(1, &m_colourBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, m_colourBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(colours), colours, GL_STATIC_DRAW);
	
	GLfloat texCoords[72];
	for (int i = 0; i < 72; i += 12)
	{
		texCoords[i] = 1.0f;	texCoords[i + 1] = 1.0f;
		texCoords[i + 2] = 0.0f;	texCoords[i + 3] = 1.0f;
		texCoords[i + 4] = 1.0f;	texCoords[i + 5] = 0.0f;
		texCoords[i + 6] = 0.0f;	texCoords[i + 7] = 1.0f;
		texCoords[i + 8] = 1.0f;	texCoords[i + 9] = 0.0f;
		texCoords[i + 10] = 0.0f;	texCoords[i + 11] = 0.0f;

	};

	glGenBuffers(1, &m_texCoordBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, m_texCoordBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(texCoords), texCoords, GL_STATIC_DRAW);

	return true;
}
