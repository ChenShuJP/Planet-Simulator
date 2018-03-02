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