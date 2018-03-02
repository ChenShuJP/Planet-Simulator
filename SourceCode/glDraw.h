/******************************************************************************/
/*!
@file   OpenGLDraw.h
@author Chen Shu
@par    email: shuchenjp@gmail.com
@date   3/3/2018
@brief  Header file of drawing functions.
*/
/******************************************************************************/
#ifndef SSS_GLDRAW_H
#define SSS_GLDRAW_H

void Loop(void);
void Resized(int W, int H);
void Init(void);
void Draw(void);
void Destroy(void);
void KeyPressed(unsigned char c, int x, int y);
void display (void);

#endif