

/**
 * @brief Struct of a 2D vector, it matches with Unity's Vector2
 */

#ifndef VECTOR2F__HEADER
#define VECTOR2F__HEADER

namespace mathexp
{
	struct Vector2f
	{
	public:
		float x;
		float y;

		/* Constructor */
		Vector2f(float x = 0, float y = 0);

		/* Copy constructor */
		Vector2f(const Vector2f&);

		/* Compare between vectors */
		bool equals(const Vector2f& other) const;

		/* Modifies the vector values */
		void set(float new_x, float new_y);

		/* Multiply two vectors */
		static Vector2f multiply(const Vector2f& a, const Vector2f& b);

		/* Overloaded = operator to compare between vectors */
		Vector2f operator=(const Vector2f&);

		/* Overloaded * operator to multiply between vectors */
		Vector2f operator*(const Vector2f&);
	};
}
#endif