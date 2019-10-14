/**
 * @brief Estructura de vector de dos dimensiones, compatible con Vector2 de Unity
 * 
 */

#ifndef VECTOR2F__HEADER
#define VECTOR2F__HEADER



namespace mathexp
{
	struct Vector2f
	{
	public:
	/**
	 * @brief Posicion x
	 * 
	 */
		float x;
	/**
	 * @brief Posicion y
	 * 
	 */
		float y;

/**
 * @brief Constructor de Vector 2f
 * 
 * @param x 
 * @param y 
 */
		Vector2f(float x = 0, float y = 0);
/**
 * @brief Constructor de copia de  Vector 2f
 * 
 */
		Vector2f(const Vector2f&);

/**
 * @brief Indica si dos vectores son iguales
 * 
 * @param other 
 * @return true 
 * @return false 
 */
		bool equals(Vector2f other);

/**
 * @brief Ajusta el valor del vector
 * 
 * @param new_x 
 * @param new_y 
 */
		void set(float new_x, float new_y);

/**
 * @brief Sobrecarga del operador de asignacion
 * 
 * @return Vector2f 
 */
		Vector2f operator=(const Vector2f&);

/**
 * @brief Multiplicacion de dos vectores
 * 
 * @param a 
 * @param b 
 * @return Vector2f 
 */
		static Vector2f multiply(Vector2f a, Vector2f b);

/**
 * @brief Sobrecarga del operador de multiplicacion
 * 
 * @return Vector2f 
 */
		Vector2f operator *(const Vector2f&);

	};
}
#endif