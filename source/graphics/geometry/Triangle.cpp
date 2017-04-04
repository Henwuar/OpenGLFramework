#include "Triangle.h"

Triangle::Triangle() : Mesh::Mesh()
{
}

Triangle::~Triangle()
{
}

bool Triangle::Init()
{
  m_numVertices = 3;
	GLfloat vertices[] =
	{
	  0.0, 1.0, 0.0,
	  -1, -1, 0.0,
	  1, -1, 0.0
	};
	glGenBuffers(1, &m_vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	GLfloat colours[] =
	{
	  0.0, 1.0, 0.0,
	  1.0, 0.0, 0.0,
	  0.0, 0.0, 1.0
	};
	glGenBuffers(1, &m_colourBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, m_colourBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(colours), colours, GL_STATIC_DRAW);
	
	return true;
}
