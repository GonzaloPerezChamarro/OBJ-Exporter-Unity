
#include "stdafx.h"
#include "Vector2f.h"

namespace mathexp
{
	Vector2f::Vector2f(float x, float y)
		:x(x), y(y)
	{
	}
	Vector2f::Vector2f(const Vector2f & other)
		: x(other.x), y(other.y)
	{
	}
	bool Vector2f::equals(Vector2f other)
	{
		return  x == other.x && y == other.y;
	}
	void Vector2f::set(float new_x, float new_y)
	{
		x = new_x;
		y = new_y;
	}
	Vector2f Vector2f::operator=(const Vector2f & other)
	{
		x = other.x;
		y = other.y;
		return *this;
	}

	Vector2f Vector2f::operator*(const Vector2f & b)
	{
		return Vector2f{ x * b.x, y * b.y };
	}
}