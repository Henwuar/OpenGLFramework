#include <cstdlib>
#include <iostream>
#include <string>

using std::string;

#include <glad\glad.h>
#include "Time.h"
#include "graphics\shader\Shader.h"
#include "graphics\geometry\Triangle.h"
#include "system\TriangleApp.h"
#include "system\Input.h"

Application* application;
Time* timer;
Input* input;

void MainLoop();
/*void UpdateMouseInput(SDL_Event e);
void UpdateControllerInput(SDL_Event e);
void UpdateJoystickInput(SDL_Event e);
void UpdateTouchInput(SDL_Event e);
void UpdateKeyboardInput(SDL_Event e);*/

int main()
{
    application = new TriangleApp();

	timer = new Time();
	input = new Input();

	input->Init();
	
	if (!application->Init(400, 300))
	{
		return EXIT_FAILURE;
	}

	MainLoop();

	delete application;
	glfwTerminate();
	return EXIT_SUCCESS;
}

void MainLoop()
{
	while (!glfwWindowShouldClose(application->window()))
	{
		timer->Update();
		/*SDL_Event ev;
		while (SDL_PollEvent(&ev))
		{
			switch(ev.type)
			{
			case SDL_QUIT: return;
			case SDL_WINDOWEVENT:
				if(ev.window.event == SDL_WINDOWEVENT_SIZE_CHANGED)
				{
					application->Resize(ev.window.data1, ev.window.data2);
				}
				break;
			case SDL_MOUSEMOTION:
			case SDL_MOUSEBUTTONDOWN:
			case SDL_MOUSEBUTTONUP:
				UpdateMouseInput(ev);
				break;
			case SDL_JOYAXISMOTION:
			case SDL_JOYBUTTONDOWN:
			case SDL_JOYBUTTONUP:
				UpdateJoystickInput(ev);
				break;
			case SDL_CONTROLLERAXISMOTION:
			case SDL_CONTROLLERBUTTONDOWN:
			case SDL_CONTROLLERBUTTONUP:
				UpdateControllerInput(ev);
				break;
			case SDL_KEYDOWN:
			case SDL_KEYUP:
				UpdateKeyboardInput(ev);
				break;
		        /*case SDL_FINGERDOWN:
			case SDL_FINGERUP:
			case SDL_FINGERMOTION:
				UpdateTouchInput(ev);
				break;
			}
		}*/
		glfwPollEvents();
		application->Run();
		input->Update();
	}
}
/*
void UpdateMouseInput(SDL_Event e)
{
	switch(e.type)
	{
	case SDL_MOUSEMOTION:
		input->SendButton("Mouse_X", e.motion.x);
		input->SendButton("Mouse_X", e.motion.y);
		break;
	case SDL_MOUSEBUTTONDOWN:
		if(e.button.button == SDL_BUTTON_LEFT)
		{
			input->SendButton("Mouse_B1", 1);
		}
		else if(e.button.button == SDL_BUTTON_RIGHT)
		{
			input->SendButton("Mouse_B2", 1);
		}
		break;
	case SDL_MOUSEBUTTONUP:
		if(e.button.button == SDL_BUTTON_LEFT)
		{
			input->SendButton("Mouse_B1", 0);
		}
		else if(e.button.button == SDL_BUTTON_RIGHT)
		{
			input->SendButton("Mouse_B2", 0);
		}
		break;	
	}
}

void UpdateJoystickInput(SDL_Event e)
{
	std::cout << "Updating Joystick" << std::endl;
	switch(e.type)
	{
	case SDL_JOYAXISMOTION:
		if(e.jaxis.axis == 0)
		{
			input->SendButton("X_Axis", float(e.jaxis.value)/32768.0f);
		}
		else if(e.jaxis.axis == 1)
		{
			input->SendButton("Y_Axis", float(e.jaxis.value)/32768.0f);
		}
		break;
	case SDL_JOYBUTTONDOWN:
	case SDL_JOYBUTTONUP:
		break;
	}
}

void UpdateControllerInput(SDL_Event e)
{
	std::cout << "Updating Controller" << std::endl;
	switch(e.type)
	{
	case SDL_CONTROLLERAXISMOTION:
		if(e.caxis.axis == 0)
		{
			input->SendButton("X_Axis", float(e.caxis.value)/32768.0f);
		}
		else if(e.jaxis.axis == 1)
		{
			input->SendButton("Y_Axis", float(e.caxis.value)/32768.0f);
		}
		break;
	}
}

void UpdateKeyboardInput(SDL_Event e)
{
	//check wether the key was just pressed or released
	float setVal = 1.0f;
	if(e.type == SDL_KEYUP)
	{
		setVal = 0.0f;
		input->SendKey(e.key.keysym.scancode, false);
	}
	else if(e.type == SDL_KEYDOWN)
	{
		input->SendKey(e.key.keysym.scancode, true);
	}

	//check which key was pressed
	switch(e.key.keysym.scancode)
	{
	case SDL_SCANCODE_W:
		input->SendButton("Y_Axis", -setVal);
		break;
	case SDL_SCANCODE_S:
		input->SendButton("Y_Axis", setVal);
		break;
	case SDL_SCANCODE_A:
		input->SendButton("X_Axis", setVal);
		break;
	case SDL_SCANCODE_D:
		input->SendButton("X_Axis", -setVal);
		break;		
	}

}*/
