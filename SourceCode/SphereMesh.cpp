/******************************************************************************/
/*!
@file   SphereMesh.cpp
@author Chen Shu
@par    email: shuchenjp@gmail.com
@date   3/3/2018
@brief  SphereMesh class implementation.
*/
/******************************************************************************/

#include "SphereMesh.h"
#include "GlobalDeclaration.h"

float SphereMesh::GetV(int index)
{
  return V[index];
}

float SphereMesh::GetU(int index)
{
  return U[index];
}

Point& SphereMesh::GetCenter()
{
  return center;
}

Vector& SphereMesh::GetDimensions(void)
{
  return dimensions;
}

Point& SphereMesh::GetVertex(int index)
{
  return vertice[index];
}

SphereMesh::SphereMesh()
{
  //Initialize center of the sphere
  center = Point(0, 0, 0);
  
  //Initialize the scale of sphere
  scale = Vector(1, 1, 1);
  
  //Initialize the dimensions of the sphere
  dimensions = Vector(2, 2, 2);
  
  //Initialize the point of the sphere
  float x = 0;
  float y = 0;
  float z = 0;
  float radius = 1;
  int n = 0;
  const double PI = 3.1415926535897;
  for(float b = 0; b <= 180 - 10; b += 10)
  {
    for(float a = 0; a <= 360 - 10; a+=10)
    {
      vertice[n].x = radius * sin((a) / 180 * PI) * sin((b) / 180 * PI)  - x;
      vertice[n].y = radius * cos((a) / 180 * PI) * sin((b) / 180 * PI) + y;
      vertice[n].z = radius * cos((b) / 180 * PI)  - z;
      V[n] = (2 * b) / 360;
      U[n] = (a) / 360;
      n++;
      
      vertice[n].x = radius * sin((a) / 180 * PI) * sin((b + 10) / 180 * PI)  - x;
      vertice[n].y = radius * cos((a) / 180 * PI) * sin((b + 10) / 180 * PI) + y;
      vertice[n].z = radius * cos((b + 10) / 180 * PI)  - z;
      V[n] = (2 * (b + 10)) / 360;
      U[n] = (a) / 360;
      n++;
      
      
      vertice[n].x = radius * sin((a + 10) / 180 * PI) * sin((b) / 180 * PI)  - x;
      vertice[n].y = radius * cos((a + 10) / 180 * PI) * sin((b) / 180 * PI) + y;
      vertice[n].z = radius * cos((b) / 180 * PI)  - z;
      V[n] = (2 * b) / 360;
      U[n] = (a + 10) / 360;
      n++;
      
      vertice[n].x = radius * sin((a + 10) / 180 * PI) * sin((b + 10) / 180 * PI)  - x;
      vertice[n].y = radius * cos((a + 10) / 180 * PI) * sin((b + 10) / 180 * PI) + y;
      vertice[n].z = radius * cos((b + 10) / 180 * PI)  - z;
      V[n] = (2 * (b + 10)) / 360;
      U[n] = (a + 10) / 360;
      n++;
    }
  }
  
  
}