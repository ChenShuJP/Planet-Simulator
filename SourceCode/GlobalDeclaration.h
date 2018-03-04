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

extern GlobalTime SystemTime;
extern WindowsSys glWindows;

extern SphereMesh sphere;
//cams[0]: Original camera.
extern Camera cams[1];
extern Vector RelativeUp;
extern float PI;

//Center
extern const Point O;

//ObjectList
extern std::vector<Object*> ObjectList;

//ObjectID
extern int Index;

//Texture
extern SSS_Texture* SSStexture;

//Object Initialization
extern bool obj_initialized;

#endif