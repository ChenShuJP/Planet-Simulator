/******************************************************************************/
/*!
@file   Time.h
@author Chen Shu
@par    email: shuchenjp@gmail.com
@date   3/3/2018
@brief  time-system-related functions and variables.
*/
/******************************************************************************/

#ifndef SSS_TIME_H
#define SSS_TIME_H
class GlobalTime
{
  public:
  GlobalTime() {}
  float Getlast_time();
  float Getdt();
  void Writelast_time(float input);
  void Writedt(float input);
  float Getframe_count();
  float Getframe_time();
  void Writeframe_count(int input);
  void Writeframe_time(float input);
  float Getcurrent_time();
  void Writecurrent_time(float input);
  
  private:
  float last_time = 0;
  float dt = 0;
  int frame_count = 0;
  float frame_time = 0;
  float current_time = 0;
};

#endif