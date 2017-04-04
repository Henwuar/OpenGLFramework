#ifndef APPLICATION_H
#define APPLICATION_H

#include <glad\glad.h>
#include <GLFW\glfw3.h>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>

#include <vector>
using std::vector;
using namespace glm;

#include "Time.h"
#include "Input.h"

extern Time* timer;
extern Input* input;

class Application
{
public:
	Application();
	virtual ~Application();

	virtual bool Init(int windowWidth, int windowHeight, const char*  windowName = "Application");
	virtual void Run() = 0;
	virtual void Resize(int width, int height);

	inline GLFWwindow* window() { return m_window; }

protected:
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void HandleInput() = 0;
	virtual void FreeResources() = 0;

	GLFWwindow* m_window;
};

#endif
