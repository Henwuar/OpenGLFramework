#include "Time.h"

Time::Time()
{
  startTime = glfwGetTime();
  curTime = startTime;
  deltaTime = 0;
}

float Time::DeltaTime()
{
  return deltaTime;
}

float Time::TimeSinceStart()
{
  return glfwGetTime() - startTime;
}

void Time::Update()
{
  deltaTime = glfwGetTime() - curTime;
  curTime = glfwGetTime();
}
