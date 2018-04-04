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

//GlobalTime SystemTime;
//WindowsSys GLVar.glWindows;
//int Index = 0;
//Camera cams[1];
//Vector RelativeUp(0, 1, 0);
//std::vector<Object*> ObjectList;
//SSS_Texture* SSStexture;

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
  glutKeyboardFunc(KeyPressed);
  glutMotionFunc(MouseMotionFunction);
  glutPassiveMotionFunc(MousePassMotionFunction);
  glutMouseFunc(MouseFunction);
  glutReshapeFunc(Resized);
  glutIdleFunc(Loop);
  Init();
  glutMainLoop();
  Destroy();
  return 0;
}