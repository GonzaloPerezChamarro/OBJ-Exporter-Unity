
#include "stdafx.h"
#include "Vector3f.h"

#include <cmath>

namespace mathexp
{
	Vector3f::Vector3f(float x, float y, float z)
		:x(x), y(y), z(z)
	{
	}
	Vector3f::Vector3f(const Vector3f & other)
		:x(other.x), y(other.y), z(other.z)
	{
	}

	bool Vector3f::equals(Vector3f other)
	{
		return x == other.x && y == other.y && z == other.z;
	}

	void Vector3f::set(float new_x, float new_y, float new_z)
	{
		x = new_x;
		y = new_y;
		z = new_z;
	}
	Vector3f Vector3f::operator=(const Vector3f & other)
	{
		x = other.x;
		y = other.y;
		z = other.z;

		return *this;
	}

	Vector3f Vector3f::operator *(const Vector3f& b)
	{
		return Vector3f{ x * b.x, y * b.y ,z * b.z };
	}

	Vector3f Vector3f::operator+(const Vector3f & b)
	{
		return Vector3f{ x + b.x, y + b.y, z + b.z };
	}

	Vector3f & Vector3f::operator+=(const Vector3f & b)
	{
		*this = *this + b;
		return *this;
	}

	Vector3f Vector3f::normalized()
	{
		float module = std::sqrtf(x*x + y * y);
		return Vector3f(x / module, y / module);
	}

	Vector3f Vector3f::multiply(Vector3f a, Vector3f b)
	{
		return Vector3f{ a.x * b.x,a.y * b.y ,a.z * b.z };
	}
}