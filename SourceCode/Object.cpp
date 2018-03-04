/******************************************************************************/
/*!
@file   Object.cpp
@author Chen Shu
@par    email: shuchenjp@gmail.com
@date   3/3/2018
@brief  Object class implementation.
*/
/******************************************************************************/

#include "Object.h"
#include "GlobalDeclaration.h"
#include <iostream>
#include "Projection.h"
  
void Object::WriteAngle(float i)
{
  angle = i;
}
float Object::GetAngle(void)
{
  return angle;
}

void Object::ObjectDraw(Affine& CMatrix, Matrix& PMatrix, bool obj_initialized)
{

  glBindTexture (GL_TEXTURE_2D, TextureID);

  glBegin (GL_TRIANGLE_STRIP);
	
	Hcoords Point1tmp;
	
	if (obj_initialized == false)
	{
		ModelMatrix = Trans(Vector(Position.x, Position.y, Position.z)) * Rot(DefaultRotation.y, Vector(0,1,0))
								* Scale(this->DefaultScale.x,this->DefaultScale.y,this->DefaultScale.z);
	}
	
	ModelMatrix = Trans(Vector(Translation.x, Translation.y, Translation.z)) * Rot(Rotation.y, Vector(0,1,0))
								* Scale(this->scale.x,this->scale.y,this->scale.z) * ModelMatrix;
								
	Matrix tmpM0 = CMatrix * ModelMatrix;
	Matrix tmpM = PMatrix * CMatrix * ModelMatrix;
	
	
  for (int b = 0; b < 2592; b++)
  {
		if ((tmpM0 * sphere.GetVertex(b)).z < 0)
		{
			Point1tmp = tmpM * sphere.GetVertex(b);
			Point1tmp = Scale(1.0 / Point1tmp.w) * Point1tmp;
			glTexCoord2f (sphere.GetU(b), sphere.GetV(b));
			glVertex3f (Point1tmp.x, Point1tmp.y, -Point1tmp.z);
		}
  }

  
  glEnd();
}

Object::Object(int& index, GLuint& TID)
{
  axis = Vector(0, 0, 0);
  Translation = Point(0, 0, 0);
  Rotation = Point(0, 0, 0);
  TextureID = TID;
  scale = Vector(1, 1, 1);
	DefaultScale = Vector(1, 1, 1);
	DefaultRotation = Point(0, 0, 0);
  angle = 0;
  
  ObjectID = index;
	
	ModelMatrix = Matrix();
}

int Object::GetObjectID(void)
{
  return ObjectID;
}

Point& Object::GetTranslation(void)
{
  return Translation;
}

void Object::WriteTranslation(float x, float y, float z)
{
  Translation.x = x;
  Translation.y = y;
  Translation.z = z;
}

Point& Object::GetRotation(void)
{
  return Rotation;
}

void Object::WriteRotation(float x, float y, float z)
{
  Rotation.x = x;
  Rotation.y = y;
  Rotation.z = z;
}

GLuint& Object::GetTextureID(void)
{
  return TextureID;
}

void Object::WriteTextureID(int input)
{
  TextureID = input;
}

void Object::WriteScale(float x, float y, float z)
{
  scale.x = x;
  scale.y = y;
  scale.z = z;
}

Vector Object::GetScale(void)
{
  return scale;
}

Point& Object::GetPosition(void)
{
  return Position;
}

void Object::WritePosition(float x, float y, float z)
{
  Position.x = x;
  Position.y = y;
  Position.z = z;
}