/**
 * @file Mesh.h
 * @author Gonzalo Perez Chamarro (Gonzalo1810 Github)
 * @brief Clase que representa un objeto Malla
 * @version 0.1
 * @date 2019-06-08
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef MESH__HEADER
#define MESH__HEADER

#include "Vector3f.h"
#include "Vector2f.h"
#include "Transform.h"
#include <vector>
#include <string>



class Mesh
{
private:
/**
 * @brief Transform de la malla
 * 
 */
	Transform mesh_transform;

/**
 * @brief Conjunto de vertices de la malla
 * 
 */
	std::vector<Vector3f> vertex;
	/**
	 * @brief COnjunto de normales de la malla
	 * 
	 */
	std::vector<Vector3f> normals;
	/**
	 * @brief Conjunto de coordenadas de textura 
	 * 
	 */
	std::vector<Vector2f> texcoord;
	/**
	 * @brief Triangulos
	 * 
	 */
	std::vector<std::vector<int>> triangles_submeshes;

/**
 * @brief Texto de log
 * 
 */
	std::string log;

	std::string data;

public:
/**
 * @brief Log de error por defecto
 * 
 */
	const std::string LOG_ERROR = "ERROR_EXPORT_MESH";

public:
/**
 * @brief Constructor de Mesh
 * 
 */
	Mesh();

	/**
	 * @brief Destructor de Mesh
	 * 
	 */
	~Mesh();

public:
/**
 * @brief Modifica el valor de transform 
 * 
 * @param position Posicion
 * @param rotation Rotacion
 * @param scale Escala
 */
	void set_transform(Vector3f position, Vector3f rotation, Vector3f scale);

/**
 * @brief Modifica el valor de vertex 
 * 
 * @param v Array de vertices
 * @param size Tamaño del array
 */
	void set_vertex(Vector3f v[], int size);
/**
 * @brief Modifica el valor de normals 
 * 
 * @param n Array de normales
 * @param size  Tamaño del array
 */
	void set_normals(Vector3f n[], int size);

/**
 * @brief Modifica el valor de texcoord 
 * 
 * @param tc Array de uvs
 * @param size  Tamaño del array
 */
	void set_texcoord(Vector2f tc[], int size);
/**
 * @brief Devuelve el numero de vertices
 * 
 * @return size_t 
 */
	size_t get_vertex_count();
/**
 * @brief Devuelve log 
 * 
 * @return const std::string& 
 */
	const std::string &  get_log();
/**
 * @brief Exporta la malla individualmente
 * 
 * @param last_index Indice de malla actual
 * @return std::string& Texto de exportacion
 */
	std::string & export_mesh(int last_index);
/**
 * @brief Modifica el valor del tamaño de submallas
 * 
 * @param size 
 */
	void set_submeshes_size(size_t size);
/**
 * @brief Modifica el valor del array de triangulos
 * 
 * @param submesh Indice de submalla
 * @param triangles Array de triangulos
 * @param size  Tamaño del array
 * @return true 
 * @return false 
 */
	bool set_triangles(int submesh, int triangles[], int size);


};
#endif
