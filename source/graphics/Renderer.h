#ifndef _RENDERER_H
#define _RENDERER_H

#include <GLFW\glfw3.h>
#include "shader\Shader.h"
#include "geometry\Mesh.h"

class Renderer
{
public:
	Renderer();

	void UseShader();
	void RenderMesh(Mesh* mesh);

	void SendShaderVec3(glm::vec3 value, GLuint shader_attribute);
	void SendShaderVec2(glm::vec2 value, GLuint shader_attribute);

	inline void SetShader(Shader* shader) { m_shader = shader; }
	inline void SetViewMatrix(glm::mat4 view) { m_view = view; }
	inline void SetProjectionMatrix(glm::mat4 projection) { m_projection = projection; }

protected:
	Shader* m_shader;
	glm::mat4 m_view;
	glm::mat4 m_projection;
};

#endif