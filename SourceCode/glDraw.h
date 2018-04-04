/******************************************************************************/
/*!
@file   OpenGLDraw.h
@author Chen Shu
@par    email: shuchenjp@gmail.com
@date   3/3/2018
@brief  Header file of drawing functions.
*/
/******************************************************************************/
#ifndef PS_GLDRAW_H
#define PS_GLDRAW_H

void Loop(void);
void Resized(int W, int H);
void Init(void);
void Draw(void);
void Destroy(void);
void KeyPressed(unsigned char c, int x, int y);
void MouseFunction(int button, int state,
                                int x, int y);
void MouseMotionFunction(int x, int y);
void MousePassMotionFunction(int x, int y);
void display (void);

#endif