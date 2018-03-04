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
  cams[0] = Camera(Point(0.0f, 0.0f, 0.0f), Vector(0.0f, 0.0, -1.0f), RelativeUp
                , 0.5f*PI, 1, 0.01f, 1.0f);          
  SSStexture = &SSS_Texture();
  Object* tmp = new Object(Index, SSStexture->GetTexture(0));//TMP
  tmp->WriteScale(1, 1, 1);
	tmp->DefaultScale = Vector(1, 1, 1);
	tmp->DefaultRotation = Point(0, 0, 0);
  tmp->WriteTranslation(0, 0, 0);
	tmp->WritePosition(0, 0, -5);
	tmp->WriteRotation(0, 0.002, 0);
  AddObject(tmp);
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
    ObjectList[i]->WriteAngle(ObjectList[i]->GetAngle() + 1);
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