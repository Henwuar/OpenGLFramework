#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Mesh.h"

class Triangle : public Mesh
{
public:
	Triangle();
	~Triangle();

	bool Init();

 private:
	int m_numVertices;
	GLfloat* m_vertices;
	GLfloat* m_colours;
};

#endif
