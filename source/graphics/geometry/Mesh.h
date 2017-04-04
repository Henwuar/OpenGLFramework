#ifndef MESH_H
#define MESH_H

#include <glad\glad.h>
#include<GLFW/glfw3.h>

class Mesh
{
public:
	Mesh();
	~Mesh();
	virtual bool Init() = 0;
	void SendGeometry(GLint vertexAttribute);
	void SendColours(GLint colourAttribute);
	void SendTexCoords(GLint texCoordAttributes);
	inline int numVertices(){return m_numVertices;}

protected:
	GLuint m_vertexBuffer;
	GLuint m_colourBuffer;
	GLuint m_texCoordBuffer;
	int m_numVertices;
	GLfloat* m_vertices;
	GLfloat* m_colours;
	GLfloat* m_texCoords;
};

#endif
