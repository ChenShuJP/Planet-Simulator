/******************************************************************************/
/*!
@file   main.cpp
@author Chen Shu
@par    email: shuchen96@163.com
@date   2/25/2016
@brief  main file.
*/
/******************************************************************************/
#include <iostream>
#include "glDraw.h"
#include "GlobalDeclaration.h"
#include "WindowsSys.h"
#include "Time.h"

GlobalTime SystemTime;
WindowsSys glWindows;
float PI = 3.1415926535;
int Index = 0;
const Point O = Point(0, 0, 0);
SphereMesh sphere;
Camera cams[1];
Vector RelativeUp(0, 1, 0);
std::vector<Object*> ObjectList;
SSS_Texture* SSStexture;
bool TMP_FLAG = false;

int main(int argc, char* argv[])
{
  
  glutInit(&argc,argv);
  // Use a z-buffer for rendering:
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
  glutInitWindowPosition(0,0);
  glutInitWindowSize(glWindows.Getwidth(), glWindows.Getheight());
  glutCreateWindow(glWindows.Getname());
  glutDisplayFunc(Draw);
  glutKeyboardFunc(KeyPressed);
  glutReshapeFunc(Resized);
  glutIdleFunc(Loop);
  Init();
  glutMainLoop();
  Destroy();
  return 0;
}