/******************************************************************************/
/*!
@file   OpenGLDraw.cpp
@author Chen Shu
@par    email: shuchenjp@gmail.com
@date   3/3/2018
@brief  Drawing functions implementation.
*/
/******************************************************************************/
#include <sstream>
#include "glDraw.h"
#include "GlobalDeclaration.h"
#include <iostream>
#include <vector>
#include "Projection.h"
#include <GL/glut.h>
#include "Object.h"


bool obj_initialized = false;

void AddObject(Object* object)
{
  ObjectList.push_back(object);
  Index++;
}

void KeyPressed(unsigned char c, int x, int y) 
{
  if (c == '\x1b')
    exit(0);
  if (c == 'w')
  {
    cams[0].ChangeEye(0, 0, -1);
  }
  if (c == 's')
  {
    cams[0].ChangeEye(0, 0, 1);
  }
  if (c == 'a')
  {
    cams[0].ChangeEye(-1, 0, 0);
  }
  if (c == 'd')
  {
    cams[0].ChangeEye(1, 0, 0);
  }
  if (c == 'q')
  {
    cams[0].ChangeEye(0, 1, 0);
  }
	if (c == 'e')
  {
    cams[0].ChangeEye(0, -1, 0);
  }
	if (c == 'e')
  {
    cams[0].ChangeEye(0, -1, 0);
  }
	
  if (c == 'z')
  {
    cams[0].RotateCamera(0.01, 0, 0);
  }
  if (c == 'x')
  {
    cams[0].RotateCamera(-0.01, 0, 0);
  }
  if (c == 'c')
  {
    cams[0].RotateCamera(0, 0.01, 0);
  }
  if (c == 'v')
  {
    cams[0].RotateCamera(0, -0.01, 0);
  }
}

void Loop(void)
{
  glutPostRedisplay();
}

void Resized(int W, int H) 
{
  glWindows.Writewidth(W);
  glWindows.Writeheight(H);
  glViewport(0,0,W,H);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(60, (GLfloat)glWindows.Getwidth() / (GLfloat)glWindows.Getheight(), 0.1, 100.0);
  glMatrixMode(GL_MODELVIEW);
}

void Init()
{
  glEnable(GL_DEPTH_TEST);
  glEnable( GL_TEXTURE_2D );
  glDepthFunc(GL_LEQUAL);
  glCullFace(GL_BACK);
  glFrontFace(GL_CCW);
  glEnable(GL_CULL_FACE);
  
  SystemTime.Writelast_time(glutGet(GLUT_ELAPSED_TIME));
  SystemTime.Writeframe_count(0);
  SystemTime.Writeframe_time(0);
  cams[0] = Camera(Point(0.0f, 0.0f, 50.0f), Vector(0.0f, 0.0, -1.0f), RelativeUp
                , 0.5f*PI, 1, 0.01f, 1.0f);          
  SSStexture = &SSS_Texture();
  Object* tmp = new Object(Index, SSStexture->GetTexture(0));//TMP
  tmp->WriteScale(1, 1, 1);
	tmp->DefaultScale = Vector(1, 1, 1);
	tmp->DefaultRotation = Point(-1 * 3.1415926/2, 0, 0);
  tmp->WriteTranslation(0, 0, 0);
	tmp->WriteDefaultPosition(0, 0, -13);
	tmp->WriteRotation(0, 0.01, 0);
	tmp->WriteSelfRotation(0.00, 0.03, 0.0);
  AddObject(tmp);
	
	Object* tmp1 = new Object(Index, SSStexture->GetTexture(0));//TMP
	tmp1->WriteScale(1, 1, 1);
	tmp1->DefaultScale = Vector(7, 7, 7);
	tmp1->DefaultRotation = Point(-1 * 3.1415926/2, 0, 0);
  tmp1->WriteTranslation(0, 0, 0);
	tmp1->WriteDefaultPosition(0, 0, 0);
	tmp1->WriteRotation(0, 0.0, 0);
	tmp1->WriteSelfRotation(0.00, 0.0, 0.0);
	AddObject(tmp1);
	
	Object* tmp2 = new Object(Index, SSStexture->GetTexture(0));//TMP
	tmp2->WriteScale(1, 1, 1);
	tmp2->DefaultScale = Vector(2.3, 2.3, 2.3);
	tmp2->DefaultRotation = Point(-1 * 3.1415926/2, 0, 0);
  tmp2->WriteTranslation(0, 0, 0);
	tmp2->WriteDefaultPosition(0, 0, -20);
	tmp2->WriteRotation(0, 0.002, 0);
	tmp2->WriteSelfRotation(0.00, 0.01, 0.0);
	AddObject(tmp2);
	
	Object* tmp3 = new Object(Index, SSStexture->GetTexture(0));//TMP
	tmp3->WriteScale(1, 1, 1);
	tmp3->DefaultScale = Vector(4, 4, 4);
	tmp3->DefaultRotation = Point(-1 * 3.1415926/2, 0, 0);
  tmp3->WriteTranslation(0, 0, 0);
	tmp3->WriteDefaultPosition(0, 0, -27);
	tmp3->WriteRotation(0, 0.001, 0);
	tmp3->WriteSelfRotation(0.00, 0.002, 0.0);
	AddObject(tmp3);
}

void Draw()
{
  //time
  int t = glutGet(GLUT_ELAPSED_TIME);
  SystemTime.Writedt(0.001*(t-SystemTime.Getlast_time()));
  SystemTime.Writelast_time(t);
  
  // frame rate
  SystemTime.Writeframe_count((SystemTime.Getframe_count()) + 1);
  SystemTime.Writeframe_time((SystemTime.Getframe_time()) 
                               + (SystemTime.Getdt()));
  if (SystemTime.Getframe_time() >= 0.5) {
    double fps = SystemTime.Getframe_count()/SystemTime.Getframe_time();
    SystemTime.Writeframe_count(0);
    SystemTime.Writeframe_time(0);
    std::stringstream ss;
    ss << glWindows.Getname() << " [fps=" << int(fps) << "]";
    glutSetWindowTitle(ss.str().c_str());
  }
  
  // clear the screen
  glClearColor(0,0,0,0);
  glClear(GL_COLOR_BUFFER_BIT);
  // clear the z-buffer
  glClearDepth(1);
  glClear(GL_DEPTH_BUFFER_BIT);
	
	//Update
	//ObjectList[0]->WriteRotation(0, ObjectList[0]->GetRotation().y + 0.005, 0);
  
  //Calculate Camera Matrix
  Affine tmpCameraAffine = cams[0].WorldToCamera(cams[0]);
	Matrix tmpProjecMatrix = CameraToNDC(cams[0]);
 
  
  //Drawing
  for (std::vector<Object*>::size_type i = 0; i < Index; i++)
  {
    ObjectList[i]->ObjectDraw(tmpCameraAffine, tmpProjecMatrix, obj_initialized);
    //ObjectList[i]->WriteAngle(ObjectList[i]->GetAngle() + 1);
  }
  // swap in the back buffer
  glutSwapBuffers();
  SystemTime.Writecurrent_time(SystemTime.Getcurrent_time() +
                                SystemTime.Getdt());
																
	if(obj_initialized == false)
	{
		obj_initialized = true;
	}
}


void Destroy(void)
{
  //delete SystemTime;
}