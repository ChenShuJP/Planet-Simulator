/******************************************************************************/
/*!
@file   WindowsSys.h
@author Chen Shu
@par    email: shuchenjp@gmail.com
@date   4/4/2018
@brief  Header file of Windows-related issues.
*/
/******************************************************************************/


#ifndef PS_WINDOWSSYS_H
#define PS_WINDOWSSYS_H

class WindowsSys
{
  public:
  char* Getname(void);
  int Getwidth(void);
  int Getheight(void);
  void Writewidth(int input);
  void Writeheight(int input);
  
  private:
  char* name = "Planet Simulator";
  int width = 1600;
  int height = 800;
};

#endif