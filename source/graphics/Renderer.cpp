#include "Renderer.h"

Renderer::Renderer()
{
	m_shader = new Shader();
	m_shader->Init("shaders/triangle_vs.glsl", "shaders/triangle_fs.glsl");

	m_view = glm::mat4(1.0f);
	m_projection = glm::mat4(1.0f);

}

void Renderer::UseShader()
{
	glUseProgram(m_shader->program());
}

void Renderer::RenderMesh(Mesh* mesh)
{
	
	
}