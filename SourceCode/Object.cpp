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
		BasicModelMatrix = Trans(Vector(DefaultPosition.x, DefaultPosition.y, DefaultPosition.z));
		
		
		ModelMatrix = BasicModelMatrix * 
									Rot(DefaultRotation.x, Vector(1,0,0)) *
		              Rot(DefaultRotation.y, Vector(0,1,0)) *
									Rot(DefaultRotation.z, Vector(0,0,1)) *
									Scale(this->DefaultScale.x,this->DefaultScale.y,this->DefaultScale.z);
									Position = DefaultPosition;
									//std::cout << Position.x << " " << Position.y << " " << Position.z << std::endl;
	}
	
	
	Matrix tmpBSMatrix = Trans(Vector(Translation.x, Translation.y, Translation.z)) * 
								Rot(Rotation.x, Vector(1,0,0)) *
								Rot(Rotation.y, Vector(0,1,0)) *
								Rot(Rotation.z, Vector(0,0,1));
  //Point Position321 = tmpBSMatrix * Position;
	//std::cout << Position321.x << " " << Position321.y << " " << Position321.z << std::endl;
	BasicModelMatrix = tmpBSMatrix * BasicModelMatrix;
	
								
	ModelMatrix = tmpBSMatrix * 
								//self rotation matrix here
								Trans(Position - Point(0, 0, 0)) *
								Rot(SelfRotation.x, Vector(1,0,0)) *
								Rot(SelfRotation.y, Vector(0,1,0)) *
								Rot(SelfRotation.z, Vector(0,0,1)) *
								//self rotation matrix calculation end here.
								Scale(this->scale.x,this->scale.y,this->scale.z) * 
								Trans(Point(0, 0, 0) - Position) *
								ModelMatrix;
								
	Matrix tmpM0 = CMatrix * ModelMatrix;
	Matrix tmpM = PMatrix * CMatrix * ModelMatrix;
	//Point Position321 = Trans(Vector(-1 * Position.x, -1 * Position.y, -1 * Position.z)) * Position;
	//std::cout << Position321.x << " " << Position321.y << " " << Position321.z << std::endl;
	//std::cout << Position.x << " " << Position.y << " " << Position.z << std::endl;
	Position = BasicModelMatrix * Point(0, 0, 0);
	
	
  for (int b = 0; b < 2592; b++)
  {
		if ((tmpM0 * GLVar.sphere.GetVertex(b)).z < 0)
		{
			Point1tmp = tmpM * GLVar.sphere.GetVertex(b);
			Point1tmp = Scale(1.0 / Point1tmp.w) * Point1tmp;
			glTexCoord2f (GLVar.sphere.GetU(b), GLVar.sphere.GetV(b));
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

Point& Object::GetDefaultPosition(void)
{
  return DefaultPosition;
}

void Object::WriteDefaultPosition(float x, float y, float z)
{
  DefaultPosition.x = x;
  DefaultPosition.y = y;
  DefaultPosition.z = z;
}

void Object::WriteSelfRotation(float x, float y, float z)
{
	SelfRotation.x = x;
	SelfRotation.y = y;
	SelfRotation.z = z;
}
Point& Object::GetSelfRotation(void)
{
	return SelfRotation;
}
