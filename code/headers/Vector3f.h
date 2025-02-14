

/**
 * @brief Struct of a 3D vector, it matches with Unity's Vector3
 */

#ifndef VECTOR3F__HEADER
#define VECTOR3F__HEADER


namespace mathexp
{
	struct Vector3f
	{
	public:
		float x;
		float y;
		float z;

		/* Constructor */
		Vector3f(float x = 0, float y = 0, float z = 0);

		/* Copy constructor */
		Vector3f(const Vector3f&);

		/* Compare between vectors */
		bool equals(const Vector3f& other) const;

		/* Modifies the vector values */
		void set(float new_x, float new_y, float new_z);

		/* Returns a copy of the vector normalized */
		Vector3f normalized() const;

		/* Multiply two vectors */
		static Vector3f multiply(const Vector3f& a, const Vector3f& b);

		/* Overloaded = operator to compare between vectors */
		Vector3f operator=(const Vector3f&);

		/* Overloaded * operator to multiply between vectors */
		Vector3f operator*(const Vector3f&);

		/* Overloaded + operator to sum two vectors */
		Vector3f operator+(const Vector3f&);

		/* Overloaded += operator to sum two vectors */
		Vector3f& operator+=(const Vector3f&);
	};
}
#endif
