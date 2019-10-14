/**
 * @brief Estructura de un vector de 3 dimensiones. COmpatible con Vector3 de Unity
 * 
 */

#ifndef VECTOR3F__HEADER
#define VECTOR3F__HEADER



namespace mathexp
{
	struct Vector3f
	{
	public:
	/**
	 * @brief Posicion x
	 * 
	 */
		float x;

		/**
		 * @brief Posicion Y
		 * 
		 */
		float y;

		/**
		 * @brief Posicion Z
		 * 
		 */
		float z;

/**
 * @brief Constructor de Vector 3f
 * 
 * @param x 
 * @param y 
 * @param z 
 */
		Vector3f(float x = 0, float y = 0, float z = 0);
/**
 * @brief Constructor de copia de Vector 3f
 * 
 */
		Vector3f(const Vector3f&);
/**
 * @brief Indica si dos vectores son iguales
 * 
 * @param other 
 * @return true 
 * @return false 
 */
		bool equals(Vector3f other);
/**
 * @brief Ajusta el valor del vector
 * 
 * @param new_x 
 * @param new_y 
 * @param new_z 
 */
		void set(float new_x, float new_y, float new_z);
/**
 * @brief Sobrecarga del operador de asignacion
 * 
 * @return Vector3f 
 */
		Vector3f operator=(const Vector3f&);
/**
 * @brief Multiplicacion de dos vectores
 * 
 * @param a 
 * @param b 
 * @return Vector3f 
 */
		static Vector3f multiply(Vector3f a, Vector3f b);
/**
 * @brief Sobrecarga del operador de multiplicacion
 * 
 * @return Vector3f 
 */
		Vector3f operator *(const Vector3f&);
/**
 * @brief Sobrecarga del operador de suma
 * 
 * @return Vector3f 
 */
		Vector3f operator+(const Vector3f&);

/**
 * @brief SObrecarga del operador +=
 * 
 * @return Vector3f& 
 */
		Vector3f& operator+=(const Vector3f&);
/**
 * @brief Devuelve una copia del vector normalizado
 * 
 * @return Vector3f 
 */
		Vector3f normalized();

		//Se necesita quaternion
		//Vector3f rotate_around_point(Vector3f pivot, Vector3f point, )

	};
}
#endif
