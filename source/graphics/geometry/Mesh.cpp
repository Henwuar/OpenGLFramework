#include "Mesh.h"

Mesh::Mesh()
{

}

Mesh::~Mesh()
{
	glDeleteBuffers(1, &m_vertexBuffer);
	glDeleteBuffers(1, &m_colourBuffer);
	glDeleteBuffers(1, &m_texCoordBuffer);
}

void Mesh::SendGeometry(GLint vertexAttribute)
{
	//bind the buffer 
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer);
	glEnableVertexAttribArray(vertexAttribute);
	//describe the vertices to OpenGL
	glVertexAttribPointer(
		vertexAttribute,
		3,
		GL_FLOAT,
		GL_FALSE,
		0,
		0); 
}

void Mesh::SendColours(GLint colourAttribute)
{
	//bind the buffer 
	glBindBuffer(GL_ARRAY_BUFFER, m_colourBuffer);
	glEnableVertexAttribArray(colourAttribute);
	//describe the vertices to OpenGL
	glVertexAttribPointer(
		colourAttribute,
		3,
		GL_FLOAT,
		GL_FALSE,
		0,
		0); 
}

void Mesh::SendTexCoords(GLint texCoordAttribute)
{
	//bind the buffer 
	glBindBuffer(GL_ARRAY_BUFFER, m_texCoordBuffer);
	glEnableVertexAttribArray(texCoordAttribute);
	//describe the vertices to OpenGL
	glVertexAttribPointer(
		texCoordAttribute,
		2,
		GL_FLOAT,
		GL_FALSE,
		0,
		0);
}
