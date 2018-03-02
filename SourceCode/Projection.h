/******************************************************************************/
/*!
@file   Projection.h
@author Chen Shu
@par    email: shuchenjp@gmail.com
@date   3/3/2018
@brief  Profection functions.
*/
/******************************************************************************/

#ifndef PROJECTION_H
#define PROJECTION_H

#include "Camera.h"


Affine CameraToWorld(const Camera& cam);
Affine WorldToCamera(const Camera& cam);
Matrix CameraToNDC(const Camera& cam);


#endif

