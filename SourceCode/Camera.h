/******************************************************************************/
/*!
@file   Camera.h
@author Chen Shu
@par    email: shuchenjp@gmail.com
@date   3/3/2018
@brief  3D Camera class.
*/
/******************************************************************************/
#include "Affine.h"

#ifndef PS_CAMERA_H
#define PS_CAMERA_H



class Camera {
  public:
    Camera(void);
    Camera(const Point& E, const Vector& look, const Vector& vp,
           float fov, float aspect, float near, float far);
    Point Eye(void) const;
    Vector Right(void) const;
    Vector Up(void) const;
    Vector Back(void) const;
    Vector ViewportGeometry(void) const;
    float NearDistance(void) const;
    float FarDistance(void) const;
    Camera& Zoom(float factor);
    Camera& Forward(float distance);
    Camera& Yaw(float angle);
    Camera& Pitch(float angle);
    Camera& Roll(float angle);
    
    Affine CameraToWorld(const Camera& cam);
    Affine WorldToCamera(const Camera& cam);
    
    Affine& GetMatrix(void);
    void MultiplyMatrix(Affine& input);
    
    void ChangeEye(float x, float y, float z);
		void RotateCamera(float x, float y, float z);
  private:
    Point eye;
    Vector right, up, back;
    float width, height, distance,
          near, far;
          
    Affine matrix;
};

#endif


