/******************************************************************************/
/*!
@file   main.cpp
@author Chen Shu
@par    email: shuchenjp@gmail.com
@date   3/3/2018
@brief  main file.
*/
/******************************************************************************/
#include <iostream>
#include "glDraw.h"
#include "GlobalDeclaration.h"
#include "WindowsSys.h"
#include "Time.h"

GlobalVariables GLVar;

int main(int argc, char* argv[])
{
  
  glutInit(&argc,argv);
  // Use a z-buffer for rendering:
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
  glutInitWindowPosition(0,0);
  glutInitWindowSize(GLVar.glWindows.Getwidth(), GLVar.glWindows.Getheight());
  glutCreateWindow(GLVar.glWindows.Getname());
  glutDisplayFunc(Draw);
  glutMotionFunc(MouseMotionFunction);
  glutPassiveMotionFunc(MousePassMotionFunction);
  glutMouseFunc(MouseFunction);
  glutReshapeFunc(Resized);
  glutIdleFunc(Loop);
  Init();
  glutKeyboardFunc(KeyPressed);
  glutMainLoop();
  Destroy();
  return 0;
}