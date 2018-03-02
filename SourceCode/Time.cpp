/******************************************************************************/
/*!
@file   Time.cpp
@author Chen Shu
@par    email: shuchenjp@gmail.com
@date   3/3/2018
@brief  Implementation of Time system.
*/
/******************************************************************************/

#include "Time.h"

float GlobalTime::Getlast_time()
{
  return last_time;
}
float GlobalTime::Getdt()
{
  return dt;
}
void GlobalTime::Writelast_time(float input)
{
  last_time = input;
}
void GlobalTime::Writedt(float input)
{
  dt = input;
}
float GlobalTime::Getframe_count()
{
  return frame_count;
}
float GlobalTime::Getframe_time()
{
  return frame_time;
}
void GlobalTime::Writeframe_count(int input)
{
  frame_count = input;
}
void GlobalTime::Writeframe_time(float input)
{
  frame_time = input;
}
float GlobalTime::Getcurrent_time()
{
  return current_time;
}
void GlobalTime::Writecurrent_time(float input)
{
  current_time = input;
}