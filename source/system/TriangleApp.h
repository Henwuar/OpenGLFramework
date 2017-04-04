#ifndef TRIANGLE_APP_H
#define TRIANGLE_APP_H

#include "Application.h"
#include "../graphics/geometry/Cube.h"
#include "../graphics/shader/Shader.h"
#include "../graphics/shader/TextureShader.h"
#include "Camera.h"
#include "../graphics/Texture.h"
#include <GLFW\glfw3.h>

class TriangleApp : public Application
{
public:
	TriangleApp();
	~TriangleApp();

	bool Init(int windowWidth, int windowHeight, const char* windowName = "Hengine Application");
	void Run();
	void Resize(int width, int height);

protected:
	void Update();
	void Render();
	void HandleInput();
	void FreeResources();

	TextureShader* m_shader;
	Cube* m_cube;
	Camera* m_camera;
	Texture* m_texture;
};

#endif
