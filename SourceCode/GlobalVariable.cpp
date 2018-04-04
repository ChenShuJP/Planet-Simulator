/******************************************************************************/
/*!
@file   GlobalDeclaration.h
@author Chen Shu
@par    email: shuchenjp@gmail.com
@date   3/3/2018
@brief  Global variables.
*/
/******************************************************************************/

#include "GlobalDeclaration.h"

//Constructor
GlobalVariables::GlobalVariables()
{
  Index = 0;
  RelativeUp = Vector(0, 1, 0);
  PI = 3.1415926535;
  obj_initialized = false;
  Mouse_pressed_l = false;
  mouse_x = 0;
  mouse_y = 0;
  mouse_x_old = 0;
  mouse_y_old = 0;
  mouse_pos_initialized = false;
  camera_rot_speed = 0.001;//0~1
}
