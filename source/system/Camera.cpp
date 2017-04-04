#include "Camera.h"

Camera::Camera()
{
  m_position = vec3(0, 0, 0);
  m_rotation = vec3(0, 0, 0);
  m_fov = 45.0f;
  m_near = 0.1f;
  m_far = 10.0f;
  m_forward = vec3(0.0f, 0.0f, 1.0f);
  m_up = vec3(0.0f, 1.0f, 0.0f);
  m_right = vec3(1.0f, 0.0f, 0.0f);
      
  Update();
}

Camera::~Camera()
{
}

void Camera::Init(vec3 position, vec3 rotation, vec2 screenSize)
{
  m_position = position;
  m_rotation = rotation;
  m_screenSize = screenSize;
  Update();
}

mat4 Camera::GetViewMatrix()
{
  return glm::lookAt(m_position, m_position + m_forward, m_up);
}

mat4 Camera::GetPerspectiveMatrix()
{
  return glm::perspective(m_fov, float(m_screenSize.x/m_screenSize.y), m_near, m_far);
  //  return mat4(1.0f);
}

mat4 Camera::GetOrthographicMatrix()
{
	float left = (m_position.x - (m_screenSize.x * 0.5))/m_screenSize.x;
	float right = (m_position.x + (m_screenSize.x * 0.5))/m_screenSize.x;
	float top = (m_position.y - (m_screenSize.y * 0.5))/m_screenSize.y;
	float bottom = (m_position.y + (m_screenSize.y * 0.5))/m_screenSize.y;
	return glm::ortho(left, right, bottom, top, 0.1f, 100.0f);
}

void Camera::MoveBy(vec3 amount)
{
  m_position += amount;
}

void Camera::MoveBy(float x, float y, float z)
{
  m_position.x += x;
  m_position.y += y;
  m_position.z += z;
  Update();
}

void Camera::MoveTo(vec3 location)
{
  m_position = location;
   Update();
}

void Camera::MoveTo(float x, float y, float z)
{
  m_position.x = x;
  m_position.y = y;
  m_position.z = z;
  Update();
}

void Camera::RotateBy(vec3 amount)
{
  m_rotation += amount;
  Update();
}

void Camera::RotateBy(float x, float y, float z)
{
  m_rotation.x += x;
  m_rotation.y += y;
  m_rotation.z += z;
  Update();
}

void Camera::RotateTo(vec3 rotation)
{
  m_rotation = rotation;
  Update();
}

void Camera::RotateTo(float x, float y, float z)
{
  m_rotation.x = x;
  m_rotation.y = y;
  m_rotation.z = z;
  Update();
}

void Camera::LookAt(vec3 targetPos)
{
  vec3 diff = targetPos - m_position;
  m_rotation.x = atan2(diff.y, diff.z);
  m_rotation.y = atan2(diff.x, diff.z);
  Update();
}

void Camera::LookAt(float x, float y, float z)
{
  vec3 diff = vec3(x, y, z) - m_position;
  m_rotation.x = atan2(diff.y, diff.z);
  m_rotation.y = atan2(diff.x, diff.z);
  Update();
}

void Camera::SetFOV(float fov)
{
  m_fov = fov;
}

void Camera::SetDrawRange(float near, float far)
{
  m_near = near;
  m_far = far;
}

void Camera::SetScreenSize(int width, int height)
{
  m_screenSize.x = width;
  m_screenSize.y = height;
}

void Camera::Update()
{
  //set up forward
  m_forward.x = sinf(m_rotation.y);
  m_forward.y = sinf(m_rotation.x);
  m_forward.z = cosf(m_rotation.x);

  //set up right
  m_right.x = cosf(m_rotation.y);
  m_right.y = sinf(m_rotation.z);
  m_right.z = sinf(m_rotation.y);

  //set up... up... (forward x right)
  m_up = glm::cross(m_forward, m_right);
}
