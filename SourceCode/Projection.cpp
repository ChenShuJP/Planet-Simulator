/******************************************************************************/
/*!
@file   Projection.cpp
@author Chen Shu
@par    email: shuchenjp@gmail.com
@date   3/3/2018
@brief  Profection implementation.
*/
/******************************************************************************/

#include "Projection.h"

Affine CameraToWorld(const Camera& cam)
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

Affine WorldToCamera(const Camera& cam)
{
  Affine tmp = CameraToWorld(cam);
  tmp = Inverse(tmp);
  return tmp;
}

Matrix CameraToNDC(const Camera& cam)
{
  Affine tmp;
  float W = cam.ViewportGeometry().x;
  float H = cam.ViewportGeometry().y;
  float D = cam.ViewportGeometry().z;
  float N = cam.NearDistance();
  float F = cam.FarDistance();
  tmp[0][0] = 2 * D / W;
  tmp[1][1] = 2 * D / H;
  tmp[2][2] = (N + F) / (N - F);
  tmp[3][3] = 0;
  tmp[2][3] = 2 * N * F / (N - F);
  tmp[3][2] = -1;
  return tmp;
}