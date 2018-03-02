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