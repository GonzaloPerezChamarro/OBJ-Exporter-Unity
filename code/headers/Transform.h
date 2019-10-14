/**
 * @file Transform.h
 * @author Gonzalo Perez Chamarro (Gonzalo1810 Github)
 * @brief Clase básica de transform
 * @version 0.1
 * @date 2019-06-08
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef TRANSFORM__HEADER
#define TRANSFORM__HEADER


#include "Vector3f.h"

using namespace mathexp;

class Transform
{
public:
/**
 * @brief Vector de posicion
 * 
 */
	Vector3f position;
/**
 * @brief Vector de rotacion.
 * 
 */
	Vector3f rotation; //Podria modificarse a Quaternion
/**
 * @brief Vector de escala
 * 
 */
	Vector3f scale;

/**
 * @brief Constructor de Transform por defecto
 * 
 */
	Transform() = default;

/**
 * @brief Constructor de Transform
 * 
 * @param position 
 * @param rotation 
 * @param scale 
 */
	Transform(Vector3f position, Vector3f rotation, Vector3f scale)
		:position(position), rotation(rotation), scale(scale)
	{
	}
/**
 * @brief Ajusta los valores del transform
 * 
 * @param p 
 * @param r 
 * @param s 
 */
	void set(Vector3f p, Vector3f r, Vector3f s)
	{
		position = p;
		rotation = r;
		scale = s;
	}

};
#endif