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

void AddObject(Object* object)
{
  GLVar.ObjectList.push_back(object);
  GLVar.Index++;
}

void MouseMotionFunction(int x, int y)
{
  if (GLVar.Mouse_pressed_l == true)
  {
    std::cout << x << " ," << y << std::endl;
  }
}

void MousePassMotionFunction(int x, int y)
{
  if (GLVar.mouse_pos_initialized == false)
  {
    GLVar.mouse_x = GLVar.glWindows.Getwidth()/2;
    GLVar.mouse_y = GLVar.glWindows.Getheight()/2;
    GLVar.mouse_x_old = GLVar.mouse_x;
    GLVar.mouse_y_old = GLVar.mouse_y;
    GLVar.mouse_pos_initialized = true;
    glutWarpPointer(GLVar.glWindows.Getwidth()/2, GLVar.glWindows.Getheight()/2);
  }
  else
  {
    GLVar.mouse_x = x;
    GLVar.mouse_y = y;
    GLVar.cams[0].RotateCamera(GLVar.camera_rot_speed * -1 * (GLVar.mouse_y - GLVar.mouse_y_old), 
                         GLVar.camera_rot_speed * -1 * (GLVar.mouse_x - GLVar.mouse_x_old), 0);
    GLVar.mouse_x_old = GLVar.mouse_x;
    GLVar.mouse_y_old = GLVar.mouse_y;
    //glutWarpPointer(GLVar.glWindows.Getwidth()/2, GLVar.glWindows.Getheight()/2);
  }
}

void MouseFunction(int button, int state,
                                int x, int y)
{
  if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
  {
    GLVar.Mouse_pressed_l = true;
  }
  if(button == GLUT_LEFT_BUTTON && state == GLUT_UP)
  {
    GLVar.Mouse_pressed_l = false;
  }
}

void KeyPressed(unsigned char c, int x, int y) 
{
  if (c == '\x1b')
    exit(0);
  if (c == 'w')
  {
    GLVar.cams[0].ChangeEye(0, 0, -1);
  }
  if (c == 's')
  {
    GLVar.cams[0].ChangeEye(0, 0, 1);
  }
  if (c == 'a')
  {
    GLVar.cams[0].ChangeEye(-1, 0, 0);
  }
  if (c == 'd')
  {
    GLVar.cams[0].ChangeEye(1, 0, 0);
  }
  if (c == 'q')
  {
    GLVar.cams[0].ChangeEye(0, 1, 0);
  }
	if (c == 'e')
  {
    GLVar.cams[0].ChangeEye(0, -1, 0);
  }
	if (c == 'e')
  {
    GLVar.cams[0].ChangeEye(0, -1, 0);
  }
	
  /*
  if (c == 'z')
  {
    GLVar.cams[0].RotateCamera(0.01, 0, 0);
  }
  if (c == 'x')
  {
    GLVar.cams[0].RotateCamera(-0.01, 0, 0);
  }
  if (c == 'c')
  {
    GLVar.cams[0].RotateCamera(0, 0.01, 0);
  }
  if (c == 'v')
  {
    GLVar.cams[0].RotateCamera(0, -0.01, 0);
  }*/
}

void Loop(void)
{
  glutPostRedisplay();
}

void Resized(int W, int H) 
{
  GLVar.glWindows.Writewidth(W);
  GLVar.glWindows.Writeheight(H);
  glViewport(0,0,W,H);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(60, (GLfloat)GLVar.glWindows.Getwidth() / (GLfloat)GLVar.glWindows.Getheight(), 0.1, 100.0);
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
  
  GLVar.SystemTime.Writelast_time(glutGet(GLUT_ELAPSED_TIME));
  GLVar.SystemTime.Writeframe_count(0);
  GLVar.SystemTime.Writeframe_time(0);
  GLVar.cams[0] = Camera(Point(0.0f, 0.0f, 50.0f), Vector(0.0f, 0.0, -1.0f), GLVar.RelativeUp
                , 0.5f*GLVar.PI, 1, 0.01f, 1.0f);          
  GLVar.PStexture = &PS_Texture();
  Object* tmp = new Object(GLVar.Index, GLVar.PStexture->GetTexture(0));//TMP
  tmp->WriteScale(1, 1, 1);
	tmp->DefaultScale = Vector(1, 1, 1);
	tmp->DefaultRotation = Point(-1 * 3.1415926/2, 0, 0);
  tmp->WriteTranslation(0, 0, 0);
	tmp->WriteDefaultPosition(0, 0, -13);
	tmp->WriteRotation(0, 0.01, 0);
	tmp->WriteSelfRotation(0.00, 0.03, 0.0);
  AddObject(tmp);
	
	Object* tmp1 = new Object(GLVar.Index, GLVar.PStexture->GetTexture(0));//TMP
	tmp1->WriteScale(1, 1, 1);
	tmp1->DefaultScale = Vector(7, 7, 7);
	tmp1->DefaultRotation = Point(-1 * 3.1415926/2, 0, 0);
  tmp1->WriteTranslation(0, 0, 0);
	tmp1->WriteDefaultPosition(0, 0, 0);
	tmp1->WriteRotation(0, 0.0, 0);
	tmp1->WriteSelfRotation(0.00, 0.0, 0.0);
	AddObject(tmp1);
	
	Object* tmp2 = new Object(GLVar.Index, GLVar.PStexture->GetTexture(0));//TMP
	tmp2->WriteScale(1, 1, 1);
	tmp2->DefaultScale = Vector(2.3, 2.3, 2.3);
	tmp2->DefaultRotation = Point(-1 * 3.1415926/2, 0, 0);
  tmp2->WriteTranslation(0, 0, 0);
	tmp2->WriteDefaultPosition(0, 0, -20);
	tmp2->WriteRotation(0, 0.002, 0);
	tmp2->WriteSelfRotation(0.00, 0.01, 0.0);
	AddObject(tmp2);
	
	Object* tmp3 = new Object(GLVar.Index, GLVar.PStexture->GetTexture(0));//TMP
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
  GLVar.SystemTime.Writedt(0.001*(t-GLVar.SystemTime.Getlast_time()));
  GLVar.SystemTime.Writelast_time(t);
  
  // frame rate
  GLVar.SystemTime.Writeframe_count((GLVar.SystemTime.Getframe_count()) + 1);
  GLVar.SystemTime.Writeframe_time((GLVar.SystemTime.Getframe_time()) 
                               + (GLVar.SystemTime.Getdt()));
  if (GLVar.SystemTime.Getframe_time() >= 0.5) {
    double fps = GLVar.SystemTime.Getframe_count()/GLVar.SystemTime.Getframe_time();
    GLVar.SystemTime.Writeframe_count(0);
    GLVar.SystemTime.Writeframe_time(0);
    std::stringstream ss;
    ss << GLVar.glWindows.Getname() << " [fps=" << int(fps) << "]";
    glutSetWindowTitle(ss.str().c_str());
  }
  
  // clear the screen
  glClearColor(0,0,0,0);
  glClear(GL_COLOR_BUFFER_BIT);
  // clear the z-buffer
  glClearDepth(1);
  glClear(GL_DEPTH_BUFFER_BIT);
	
	//Update
	//GLVar.ObjectList[0]->WriteRotation(0, GLVar.ObjectList[0]->GetRotation().y + 0.005, 0);
  
  //Calculate Camera Matrix
  Affine tmpCameraAffine = GLVar.cams[0].WorldToCamera(GLVar.cams[0]);
	Matrix tmpProjecMatrix = CameraToNDC(GLVar.cams[0]);
 
  
  //Drawing
  for (std::vector<Object*>::size_type i = 0; i < GLVar.Index; i++)
  {
    GLVar.ObjectList[i]->ObjectDraw(tmpCameraAffine, tmpProjecMatrix, GLVar.obj_initialized);
    //GLVar.ObjectList[i]->WriteAngle(GLVar.ObjectList[i]->GetAngle() + 1);
  }
  // swap in the back buffer
  glutSwapBuffers();
  GLVar.SystemTime.Writecurrent_time(GLVar.SystemTime.Getcurrent_time() +
                                GLVar.SystemTime.Getdt());
																
	if(GLVar.obj_initialized == false)
	{
		GLVar.obj_initialized = true;
	}
}


void Destroy(void)
{
  //delete GLVar.SystemTime;
}