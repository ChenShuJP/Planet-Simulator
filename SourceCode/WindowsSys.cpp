/******************************************************************************/
/*!
@file   WindowsSys.cpp
@author Chen Shu
@par    email: shuchenjp@gmail.com
@date   4/4/2018
@brief  Implementation of Windows-related issues.
*/
/******************************************************************************/

#include "WindowsSys.h"

char* WindowsSys::Getname(void)
{
  return name;
}

int WindowsSys::Getwidth(void)
{
  return width;
}

int WindowsSys::Getheight(void)
{
  return height;
}

void WindowsSys::Writewidth(int input)
{
  width = input;
}

void WindowsSys::Writeheight(int input)
{
  height = input;
}