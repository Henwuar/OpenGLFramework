#include "TriangleApp.h"
#include <iostream>
#include <stdio.h>

TriangleApp::TriangleApp()
{

}

TriangleApp::~TriangleApp()
{
	Application::FreeResources();
	FreeResources();
}

bool TriangleApp::Init(int windowWidth, int windowHeight, const char* windowName)
{
    Application::Init(windowWidth, windowHeight, windowName);

	GLint compile_ok = GL_FALSE, link_ok = GL_FALSE;

	m_shader = new TextureShader();
	if (!m_shader->Init("shaders/texture_vs.glsl", "shaders/texture_fs.glsl"))
	{
		return false;
	}

	m_cube = new Cube();
	m_cube->Init();

	m_camera = new Camera();
	m_camera->Init(vec3(0.0f, 0.0f, -10.0f), vec3(), vec2(windowWidth, windowHeight));
	
	m_texture = new Texture();
	if (!m_texture->LoadImage("res/crate.png"))
	{
		return false;
	}

	return true;
}

void TriangleApp::Run()
{
	HandleInput();
	
	Update();
	
	Render();
}

void TriangleApp::Update()
{
}

void TriangleApp::Render()
{
    glEnable(GL_DEPTH_TEST);
	//Clear the background
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	//draw the triangle
	glUseProgram(m_shader->program());
	//send the attributes
	m_cube->SendGeometry(m_shader->attribute(ATTRIBUTE_COORD3D));
	m_cube->SendColours(m_shader->attribute(ATTRIBUTE_RGB));
	m_cube->SendTexCoords(m_shader->attribute(ATTRIBUTE_COORD2D));
	//translate the triangle
	float moveAmount = sinf(timer->TimeSinceStart() * 6.28);
	float rotateAmount = timer->TimeSinceStart() * (3.14 * 0.5);
	mat4 transform = rotate(mat4(1.0f), rotateAmount, vec3(0.0f, 1.0f, 0.0f));

	mat4 projection = m_camera->GetPerspectiveMatrix();
	mat4 view = m_camera->GetViewMatrix();
	
	//send the transform matrix
	m_shader->SendParameters(projection * view * transform, m_texture->ID());
	//Draw the triangles
	glDrawArrays(GL_TRIANGLES, 0, m_cube->numVertices());
	//Disable the vbos
	glDisableVertexAttribArray(m_shader->attribute(ATTRIBUTE_COORD3D));
	glDisableVertexAttribArray(m_shader->attribute(ATTRIBUTE_RGB));
	glDisableVertexAttribArray(m_shader->attribute(ATTRIBUTE_COORD2D));
	
	//Swap the buffers
	glfwSwapBuffers(m_window);
}

void TriangleApp::HandleInput()
{
	float xMove = input->GetValue("X_Axis");
	float yMove = input->GetValue("Y_Axis");
	  
	m_camera->MoveBy(vec3(xMove * timer->DeltaTime(), 0.0f, -yMove * timer->DeltaTime()));
}

void TriangleApp::FreeResources()
{
	delete m_shader;
	m_shader = 0;

	delete m_cube;
	m_cube = 0;

	delete m_camera;
	m_camera = 0;
}

void TriangleApp::Resize(int width, int height)
{
	m_camera->SetScreenSize(width, height);
	glViewport(0, 0, width, height);
}
