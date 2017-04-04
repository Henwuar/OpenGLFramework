#ifndef _INPUT_H
#define _INPUT_H

#include <GLFW\glfw3.h>
#include <string.h>
#include <unordered_map>
#include <vector>
using std::string;
using std::unordered_map;
using std::vector;

class Input
{
public:
	Input();
	~Input();

	void Init();
	void Update();
	bool GetPressed(string buttonName);
	bool GetReleased(string buttonName);
	bool Get(string buttonName);
	float GetValue(string buttonName);
	bool GetPressedDirection(string buttonName, float direction);

	void SendButton(string button, float value);
	//void SendKey(SDL_Scancode key, bool value);
	//bool GetKey(SDL_Scancode key);
	
	inline void SetJoystickDeadzone(float value){m_deadzone = value;}
	
private:
	bool IsDead(float value);
	int Direction(float value);
	
	unordered_map<string, float> m_values;
	unordered_map<string, float> m_prevValues;
	
	float m_deadzone;
	bool m_keys[256];
};

#endif
