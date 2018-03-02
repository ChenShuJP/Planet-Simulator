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
  
void Object::WriteAngle(float i)
{
  angle = i;
}
float Object::GetAngle(void)
{
  return angle;
}

void Object::ObjectDraw(GLfloat* CMatrix)
{
  glLoadIdentity();
    
  glRotatef(angle,0,1,0);

  glRotatef (90, 1, 0, 0);
  
  glTranslatef(0,0,-10);
  
  glMultMatrixf(CMatrix);
  
  
  
  //Camera
  
  glRotatef(3,cams[0].Up().x,cams[0].Up().y,cams[0].Up().z);
  
  glTranslatef(cams[0].Eye().x,cams[0].Eye().y,cams[0].Eye().z);

  glBindTexture (GL_TEXTURE_2D, TextureID);

  glBegin (GL_TRIANGLE_STRIP);
    
  for (int b = 0; b < 2592; b++)
  {
    glTexCoord2f (sphere.GetU(b), sphere.GetV(b));
    //std::cout << VERTEX[b].U <<std::endl;     
    glVertex3f (sphere.GetVertex(b).x, sphere.GetVertex(b).y, -sphere.GetVertex(b).z);
    //std::cout << VERTEX[b].X <<std::endl;
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
  angle = 0;
  
  ObjectID = index;
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
