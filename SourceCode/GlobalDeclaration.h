/******************************************************************************/
/*!
@file   GlobalDeclaration.h
@author Chen Shu
@par    email: shuchenjp@gmail.com
@date   3/3/2018
@brief  Global variables.
*/
/******************************************************************************/

#ifndef SSS_GLOBALDEC_H
#define SSS_GLOBALDEC_H

#include "Object.h"
#include <vector>
#include "Texture.h"
#include "SphereMesh.h"
#include "Camera.h"
#include "Time.h"
#include "WindowsSys.h"

//extern GlobalTime SystemTime;
//extern WindowsSys glWindows;

//extern SphereMesh sphere;
//cams[0]: Original camera.
//extern Camera cams[1];
//extern Vector RelativeUp;
//extern float PI;

//Center
//extern const Point O;

//ObjectList
//extern std::vector<Object*> ObjectList;

//ObjectID
//extern int Index;

//Texture
//extern SSS_Texture* SSStexture;

//Object Initialization
//extern bool obj_initialized;

//Mouse related
//extern bool obj_initialized;
//extern bool Mouse_pressed_l;
//extern bool mouse_pos_initialized;
//extern float camera_rot_speed;//0~1


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
    SSS_Texture* SSStexture; 
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