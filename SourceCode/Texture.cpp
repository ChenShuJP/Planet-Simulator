/******************************************************************************/
/*!
@file   Texture.cpp
@author Chen Shu
@par    email: shuchenjp@gmail.com
@date   3/3/2018
@brief  Texture upload.
*/
/******************************************************************************/

#include "Texture.h"
#include <iostream>
SSS_Texture::SSS_Texture()
{
  for (int i = 0; i < texture_num; i++)
  {
    texture_fl_name[i] = "texture.raw";
  }
  
  for (int i = 0; i < texture_num; i++)
  {
    texture[i] = LoadTextureRAW(texture_fl_name[i].c_str(), i);
    std::cout << texture[i] << std::endl;
  }
}


GLuint SSS_Texture::LoadTextureRAW(const char* filename, int TextureID)
{
  int width, height;
  unsigned char * data;
  FILE * file;
  file = fopen(filename, "rb");
  GLuint textureL;
  if (file == NULL) return 0;

  width = 1024;
  height = 512;
    
  data = (unsigned char *)malloc(width * height * 3);
  fread(data, width * height * 3, 1, file);
    
  fclose(file);
  glGenTextures(1, &textureL); 
    

    
  glBindTexture(GL_TEXTURE_2D, textureL);
  glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE); 
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
                  GL_LINEAR_MIPMAP_NEAREST);
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, 
                  GL_LINEAR);
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, 
                  GL_REPEAT);
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, 
                  GL_REPEAT);
  gluBuild2DMipmaps(GL_TEXTURE_2D, 3, width, height, 
                    GL_RGB, GL_UNSIGNED_BYTE, data);
  free(data);
    

    
  return textureL;
}

GLuint& SSS_Texture::GetTexture(int index)
{
  return texture[index];
}