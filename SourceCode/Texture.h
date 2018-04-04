/******************************************************************************/
/*!
@file   Texture.h
@author Chen Shu
@par    email: shuchenjp@gmail.com
@date   3/3/2018
@brief  Texture upload functions.
*/
/******************************************************************************/

#ifndef PS_TEXTURE_H
#define PS_TEXTURE_H
#include <string>
#include <GL/glut.h>

class PS_Texture
{
  public:
  PS_Texture();
  GLuint LoadTextureRAW(const char* filename, int TextureID);
  GLuint& GetTexture(int index);
  private:
  //Limited textures. No real-time texture loading.
  std::string texture_fl_name[1];
  const int texture_num = 1;
  GLuint texture[1];
};

#endif