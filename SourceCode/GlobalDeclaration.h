/******************************************************************************/
/*!
@file   GlobalDeclaration.h
@author Chen Shu
@par    email: shuchenjp@gmail.com
@date   3/3/2018
@brief  Global variables.
*/
/******************************************************************************/

#ifndef PS_GLOBALDEC_H
#define PS_GLOBALDEC_H

#include "Object.h"
#include <vector>
#include "Texture.h"
#include "SphereMesh.h"
#include "Camera.h"
#include "Time.h"
#include "WindowsSys.h"

class GlobalVariables 
{
  public:
    GlobalVariables();
  //private:
    GlobalTime SystemTime;
    WindowsSys glWindows;
    SphereMesh sphere;
    Camera cams[1];
    Vector RelativeUp;
    float PI;
    const Point O = Point(0, 0, 0);
    std::vector<Object*> ObjectList;
    //ObjectID
    int Index;
    //Texture
    PS_Texture* PStexture; 
    //Object Initialization
    bool obj_initialized;
    //Mouse related
    bool Mouse_pressed_l;
    float mouse_x;
    float mouse_y;
    float mouse_x_old;
    float mouse_y_old;
    bool mouse_pos_initialized;
    float camera_rot_speed;//0~1       
 };
 
 extern GlobalVariables GLVar;

#endif