#ifndef _CAMERA_H
#define _CAMERA_H

#include <cmath>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
using namespace glm;

//#include "VectorMath.h"

class Camera
{
 public:
  Camera();
  ~Camera();

  void Init(vec3 position, vec3 rotation, vec2 screenSize);
  mat4 GetViewMatrix();
  mat4 GetPerspectiveMatrix();
  mat4 GetOrthographicMatrix();
  
  void MoveBy(vec3 amount);
  void MoveBy(float x, float y, float z);
  void MoveTo(vec3 location);
  void MoveTo(float x, float y, float z);
  void RotateBy(vec3 amount);
  void RotateBy(float x, float y, float z);
  void RotateTo(vec3 rotation);
  void RotateTo(float x, float y, float z);

  void LookAt(vec3 targetPos);
  void LookAt(float x, float y, float z);

  void SetFOV(float fov);
  void SetDrawRange(float near, float far);
  void SetScreenSize(int width, int height);
  
  inline vec3 position(){return m_position;}
  inline vec3 rotation(){return m_rotation;}
  inline vec3 forward(){return m_forward;}
  inline vec3 right(){return m_right;}
  inline vec3 up(){return m_up;}

 private:
  void Update();

  vec3 m_position;
  vec3 m_rotation;
  vec3 m_forward;
  vec3 m_right;
  vec3 m_up;
  float m_fov;
  float m_near;
  float m_far;
  vec2 m_screenSize;
};

#endif
