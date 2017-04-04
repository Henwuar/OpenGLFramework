#ifndef TIME_H
#define TIME_H

#include <GLFW\glfw3.h>

class Time
{
 public:
  Time();
  
  float DeltaTime();
  float TimeSinceStart(); 

  void Update();
  
 private:
  float curTime;
  float startTime;
  float deltaTime;
};

#endif
