#include "Input.h"

Input::Input()
{
	//set up the keys for arbitrary checking
	for (int i = 0; i < 256; i++)
	{
		m_keys[i] = false;
	}
	
}

Input::~Input()
{
}

void Input::Init()
{
	m_deadzone = 0.01f;
	m_values.insert(std::make_pair<string, float>("X_Axis", 0.0f));
	m_values.insert(std::make_pair<string, float>("Y_Axis", 0.0f));
	m_values.insert(std::make_pair<string, float>("Mouse_B1", 0.0f));
	m_values.insert(std::make_pair<string, float>("Mouse_B2", 0.0f));
	m_values.insert(std::make_pair<string, float>("Mouse_X", 0.0f));
	m_values.insert(std::make_pair<string, float>("Mouse_Y", 0.0f));
	m_prevValues.insert(std::make_pair<string, float>("X_Axis", 0.0f));
	m_prevValues.insert(std::make_pair<string, float>("Y_Axis", 0.0f));
	m_prevValues.insert(std::make_pair<string, float>("Mouse_B1", 0.0f));
	m_prevValues.insert(std::make_pair<string, float>("Mouse_B2", 0.0f));
	m_prevValues.insert(std::make_pair<string, float>("Mouse_X", 0.0f));
	m_prevValues.insert(std::make_pair<string, float>("Mouse_Y", 0.0f));
}

void Input::Update()
{
	//update the previous inputs
	unordered_map<string, float>::const_iterator it = m_values.begin();
	while(it != m_values.end())
	{
		m_prevValues.at(it->first) = it->second;
		it++;
	}
}

bool Input::GetPressed(string buttonName)
{
	unordered_map<string, float>::const_iterator find = m_values.find(buttonName);
	if(find != m_values.end())
	{
		float val = find->second;
		//get the previous value
		find = m_prevValues.find(buttonName);
		if(IsDead(find->second) && !IsDead(val))
		{
			return true;
		}
		return false;
	}
	return false;
}

bool Input::GetReleased(string buttonName)
{
	unordered_map<string, float>::const_iterator find = m_values.find(buttonName);
	if(find != m_values.end())
	{
		float val = find->second;
		//get the previous value
		find = m_prevValues.find(buttonName);
		if(!IsDead(find->second) && IsDead(val))
		{
			return true;
		}
		return false;
	}
	return false;
}

bool Input::Get(string buttonName)
{
    unordered_map<string, float>::const_iterator find = m_values.find(buttonName);
	if(find != m_values.end())
	{
		if(IsDead(find->second))
		{
			return false;
		}
		return true;
	}
	return false;
}

float Input::GetValue(string buttonName)
{
    unordered_map<string, float>::const_iterator find = m_values.find(buttonName);
	if(find != m_values.end())
	{
		if(IsDead(find->second))
		{
			return 0;
		}
		return find->second;
	}
	return 0;
}

bool Input::GetPressedDirection(string buttonName, float direction)
{
	unordered_map<string, float>::const_iterator find = m_values.find(buttonName);
	if(find != m_values.end())
	{
		float val = find->second;
		//get the previous value
		find = m_prevValues.find(buttonName);
		
		if(IsDead(find->second) && Direction(val) == Direction(direction))
		{
			return true;
		}
		return false;
	}
	return false;	
}

void Input::SendButton(string button, float value)
{
	m_values.at(button) = value;
}

/*void Input::SendKey(SDL_Scancode key, bool value)
{
	m_keys[key] = value;
}

bool Input::GetKey(SDL_Scancode key)
{
	return m_keys[key];
}*/

bool Input::IsDead(float value)
{
	if(abs(value) < m_deadzone)
	{
		return true;
	}
	return false;
}

int Input::Direction(float value)
{
	if(value > m_deadzone)
	{
		return 1;
	}
	if(value < -m_deadzone)
	{
		return -1;
	}
	return 0;
}
