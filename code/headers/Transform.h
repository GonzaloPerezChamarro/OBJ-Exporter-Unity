/**
 * @file Transform.h
 * @author Gonzalo Perez Chamarro (Gonzalo1810 Github)
 * @brief Clase básica de transform
 * @version 0.1
 * @date 2019-06-08
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef TRANSFORM__HEADER
#define TRANSFORM__HEADER


#include "Vector3f.h"

using namespace mathexp;

class Transform
{
public:
	Vector3f position;
	Vector3f rotation;
	Vector3f scale;

	/* Constructor by default*/
	Transform() = default;

	/* Constructor with params */
	Transform(Vector3f position, Vector3f rotation, Vector3f scale)
		:position(position), rotation(rotation), scale(scale)
	{
	}

	/* Modifies the transform */
	void set(Vector3f p, Vector3f r, Vector3f s)
	{
		position = p;
		rotation = r;
		scale = s;
	}
};
#endif