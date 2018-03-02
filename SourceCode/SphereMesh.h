/******************************************************************************/
/*!
@file   SphereMesh.h
@author Chen Shu
@par    email: shuchenjp@gmail.com
@date   3/3/2018
@brief  SphereMesh class.
*/
/******************************************************************************/

#ifndef PS_SPHEREMESH_H
#define PS_SPHEREMESH_H

#include "Affine.h"

class SphereMesh
{
  public:
  SphereMesh();
  Point& GetCenter(void);
  Vector& GetDimensions(void);
  Point& GetVertex(int index);
  float GetV(int index);
  float GetU(int index);
  private:
  Vector scale;
  Vector dimensions;
  Point center;
  Point vertice[2592];
  float V[2592];
  float U[2592];
};

#endif