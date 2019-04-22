/******************************************************************************/
/*!
@file   Affine.cpp
@author Chen Shu
@par    email: shuchenjp@gmail.com
@date   3/3/2018
@brief  Math library
*/
/******************************************************************************/

#include "Affine.h"

void swap(int& i, int& j)
{
  int tmp = i;
  i = j;
  j = tmp;
  return;
}

Matrix operator*(float A, const Matrix& B)
{
  Matrix tmp;
  for (int i = 0; i < 3; i++)
  {
    tmp[i] = A * B[i];
  }
  return tmp;
}

Matrix operator+(Matrix A, const Matrix& B)
{
  Matrix tmp;
  for (int i = 0; i < 3; i++)
  {
    tmp[i] = A[i] + B[i];
  }
  for(int i = 0; i < 4; i++)
  {
    tmp[3][i] = 0;
    if (i == 3)
    {
      tmp[3][i] = 1;
    }
  }
  return tmp;
}

void sortIndex(int& ai, int& bi, int& aj, int& bj)
{
  if (ai > 2)
  {
    ai -= 3;
  }
  if (bi > 2)
  {
    bi -= 3;
  }
  if (aj > 2)
  {
    aj -= 3;
  }
  if (bj > 2)
  {
    bj -= 3;
  }
  
  if (ai > bi)
  {
    swap(ai,bi);
  }
  
  if (aj > bj)
  {
    swap(aj,bj);
  }
}

Hcoords::Hcoords(void)
{
  x = 0;
  y = 0;
  z = 0;
  w = 0;
}

Hcoords::Hcoords(float X, float Y, float Z, float W)
{
  x = X;
  y = Y;
  z = Z;
  w = W;
}

Point::Point(void)
{
  x = 0;
  y = 0;
  z = 0;
  w = 1;
}

Point::Point(float X, float Y, float Z)
{
  x = X;
  y = Y;
  z = Z;
  w = 1;
}

Vector::Vector(void)
{
  x = 0;
  y = 0;
  z = 0;
  w = 0;
}

Vector::Vector(float X, float Y, float Z)
{
  x = X;
  y = Y;
  z = Z;
  w = 0;
}

bool Vector::Normalize(void)
{
  if (x == 0 && y == 0 && z == 0)
  {
    return false;
  }
  float length = sqrt(x * x + y * y + z * z);
  x /= length;
  y /= length;
  z /= length;
  return true;
}

Matrix::Matrix(void)
{
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      (row[i][j]) = 0;
    }
  }
}

Affine::Affine(void)
{
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      if (i == j)
      {
        (row[i][j]) = 1;
      }
      else
      {
        (row[i][j]) = 0;
      }
    }
  }
}

Affine::Affine(const Vector& Lx, const Vector& Ly, const Vector& Lz, const Point& D)
{
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      if (i == 0)
      {
        row[j][i] = Lx[j];
      }
      if (i == 1)
      {
        row[j][i] = Ly[j];
      }
      if (i == 2)
      {
        row[j][i] = Lz[j];
      }
      if (i == 3)
      {
        row[j][i] = D[j];
      }
    }
  }
}

Hcoords operator+(const Hcoords& u, const Hcoords& v)
{
  Hcoords tmp;
  tmp.x = u.x + v.x;
  tmp.y = u.y + v.y;
  tmp.z = u.z + v.z;
  tmp.w = u.w + v.w;
  return tmp;
}

//Vector A - Vector B
Hcoords operator-(const Hcoords& u, const Hcoords& v)
{
  Hcoords tmp;
  tmp.x = u.x - v.x;
  tmp.y = u.y - v.y;
  tmp.z = u.z - v.z;
  tmp.w = u.w - v.w;
  return tmp;
}

//-1 * Vector A
Hcoords operator-(const Hcoords& v)
{
  Hcoords tmp;
  tmp.x = -1 * v.x;
  tmp.y = -1 * v.y;
  tmp.z = -1 * v.z;
  tmp.w = -1 * v.w;
  return tmp;
}

Hcoords operator*(float r, const Hcoords& v)
{
  Hcoords tmp;
  tmp.x = r * v.x;
  tmp.y = r * v.y;
  tmp.z = r * v.z;
  tmp.w = r * v.w;
  return tmp;
}

Hcoords operator*(const Matrix& A, const Hcoords& v)
{
  Hcoords tmp;
  for (int i = 0; i < 4; i++)
  {
    float result = 0;
    for (int j = 0; j < 4; j++)
    {
      result += A[i][j] * v[j];
    }
    tmp[i] = result; 
  }
  return tmp;
}

Matrix operator*(const Matrix& A, const Matrix& B)
{
  Matrix tmp;
  
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      float result = 0;
      for (int z = 0; z < 4; z++)
      {
        result += A[i][z] * B[z][j];
      }
      tmp[i][j] = result;
    }
  }
  return tmp;
}

float dot(const Vector& u, const Vector& v)
{
  float result = 0;
  for (int i = 0; i < 4; i++)
  {
    result += u[i] * v[i];
  }
  return result;
}

float abs(const Vector& v)
{
  return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}


Vector cross(const Vector& u, const Vector& v)
{
  float tmpX;
  float tmpY;
  float tmpZ;
  
  tmpX = u.y * v.z - u.z * v.y;
  tmpY = u.z * v.x - u.x * v.z;
  tmpZ = u.x * v.y - u.y * v.x;
  
  Vector tmp(tmpX, tmpY, tmpZ);
  return tmp;
}

Affine Rot(float t, const Vector& v)
{
  Affine firstPart;
  firstPart = Scale((float)cos(t)) * firstPart;
  Matrix secondPart;
  secondPart[0][1] = -1 * v.z;
  secondPart[0][2] = v.y;
  secondPart[1][0] = v.z;
  secondPart[1][2] = -1 * v.x;
  secondPart[2][0] = -1 * v.y;
  secondPart[2][1] = v.x;
  secondPart[3][3] = 1;
  secondPart = Scale(sin(t)/abs(v)) * secondPart;
  Matrix thirdPart;
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      thirdPart[i][j] = v[i] * v[j];
    }
  }
  thirdPart = Scale((1 - cos(t))/(abs(v) * abs(v))) * thirdPart;
  Affine tmp = firstPart + secondPart + thirdPart;
  return tmp;
}
Affine Trans(const Vector& v)
{
  Affine tmp;
  tmp[0][3] = v.x;
  tmp[1][3] = v.y;
  tmp[2][3] = v.z;
  return tmp;
}
Affine Scale(float r)
{
  Affine tmp;
  for (int i = 0; i < 3; i++)
  {
    tmp[i][i] = r;
  }
  return tmp;
}

Affine Scale(float rx, float ry, float rz)
{
  Affine tmp;
  tmp[0][0] = rx;
  tmp[1][1] = ry;
  tmp[2][2] = rz;
  return tmp;
}
Affine Inverse(const Affine& A)
{
  Affine tmp;
  bool IsPositive = true;
  float det = 0;
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      int smalleri = i + 1;
      int largeri = i + 2;
      int smallerj = j + 1;
      int largerj = j + 2;
      sortIndex(smalleri, largeri, smallerj, largerj);
      
      tmp[j][i] = A[smalleri][smallerj] * A[largeri][largerj] - A[smalleri][largerj] * A[largeri][smallerj];
      if (IsPositive == false)
      {
        tmp[j][i] *= -1;
        IsPositive = true;
      }
      else
      {
        IsPositive = false;
      }
      if (i == 0)
      {
        det += A[i][j] * tmp[j][i];
      }
    }
  }
  Affine TransM;
  for (int i = 0; i < 3; i++)
  {
    TransM[i][3] = -1 * A[i][3];
  }
  tmp = (Scale(1 / det) * tmp) * TransM;
  return tmp;
}