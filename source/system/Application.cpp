#include "Application.h"

Application::Application()
{
	
}

Application::~Application()
{
}

bool Application::Init(int windowWidth, int windowHeight, const char* windowName)
{
	//Initialise SDL and the Window
	if (!glfwInit())
	{
		return false;
	}
	m_window = glfwCreateWindow(windowWidth, windowHeight, windowName, NULL, NULL);
	if (!m_window)
	{
		glfwTerminate();
		return false;
	}

	glfwMakeContextCurrent(m_window);
	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
	
	return true;
}

void Application::Resize(int width, int height)
{
	glViewport(0, 0, width, height);
}

void Application::FreeResources()
{
	//SDL_SetWindowFullscreen(m_window, 0);
}
