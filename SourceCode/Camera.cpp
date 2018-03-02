/******************************************************************************/
/*!
@file   Camera.cpp
@author Chen Shu
@par    email: shuchenjp@gmail.com
@date   3/3/2018
@brief  3D Camera class implementation.
*/
/******************************************************************************/

#include "Camera.h"
#include "Affine.h"
#include <cmath>

Camera::Camera()
{
  right = Vector(1, 0, 0);
  up = Vector(0, 1, 0);
  back = Vector(0, 0, 1);
  eye = Point(0, 0, 0);
  
  near = 0.1;
  far = 10;
  distance = 1;
  width = 2;
  height = 2;
  
  matrix = Affine();
}

void Camera::ChangeEye(float x, float y, float z)
{
  eye.x += x;
  eye.y += y;
  eye.z += z;
}

Affine& Camera::GetMatrix(void)
{
  return matrix;
}

void Camera::MultiplyMatrix(Affine& input)
{
  matrix = input * matrix;
}

Camera::Camera(const Point& E, const Vector& look, const Vector& vp,
               float fov, float aspect, float near, float far)
{
  eye = E;
  back = -1 * (1 / abs(look)) * look;
  Vector tmp = cross(look, vp);
  right = (1 / abs(tmp)) * tmp;
  Vector tmpUp = cross(back, right);
  up = (1 / abs(tmpUp)) * tmpUp;
  this->near = near;
  this->far = far;
  
  distance = 1;
  width = tan(fov / 2) * 2 * distance;
  height = width / aspect;
}

Point Camera::Eye(void) const
{
  return eye;
}

Vector Camera::Right(void) const
{
  return right;
}

Vector Camera::Up(void) const
{
  return up;
}

Vector Camera::Back(void) const
{
  return back;
}

Vector Camera::ViewportGeometry(void) const
{
  return Vector(width, height, distance);
}

float Camera::NearDistance(void) const
{
  return near;
}

float Camera::FarDistance(void) const
{
  return far;
}

Camera& Camera::Zoom(float factor)
{
  width *= factor;
  height *= factor;
  return *this;
}

Camera& Camera::Forward(float distance)
{
  eye = eye - distance * back;
  distance += distance;
  return *this;
}

Camera& Camera::Yaw(float angle)
{
  Point tmp = eye + up;
  Vector rotAxis = tmp - eye;
  right = Rot(angle, rotAxis) * right;
  back = Rot(angle, rotAxis) * back;
  return *this;
}

Camera& Camera::Pitch(float angle)
{
  Point tmp = eye + right;
  Vector rotAxis = tmp - eye;
  up = Rot(angle, rotAxis) * up;
  back = Rot(angle, rotAxis) * back;
  return *this;
}

Camera& Camera::Roll(float angle)
{
  Point tmp = eye + back;
  Vector rotAxis = tmp - eye;
  up = Rot(angle, rotAxis) * up;
  right = Rot(angle, rotAxis) * right;
  return *this;
}

Affine Camera::CameraToWorld(const Camera& cam)
{
  Affine tmp;
  //First column
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      if (j == 0)
      {
       tmp[i][j] = cam.Right()[i];
      }
      
      if (j == 1)
      {
       tmp[i][j] = cam.Up()[i];
      }
      
      if (j == 2)
      {
       tmp[i][j] = cam.Back()[i];
      }
      
      if (j == 3)
      {
       tmp[i][j] = cam.Eye()[i];
      }
    }
  }
  
  return tmp;
}

Affine Camera::WorldToCamera(const Camera& cam)
{
  Affine tmp = CameraToWorld(cam);
  tmp = Inverse(tmp);
  return tmp;
}

Camera& Camera2Dmove(const float X, const float Y);// 9/9 Added
{
  float localX = X;
  float localY = Y;
  
  ChangeEye(localX, localY, this.Eye.z);
  return *this;
}

