/**
 * @file Mesh.h
 * @author Gonzalo Perez Chamarro (Gonzalo1810 Github)
 * @brief Clase que representa un objeto Malla
 * @version 0.1
 * @date 2019-06-08
 * 
 * @copyright Copyright (c) 2025
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
	/* mesh transform */
	Transform mesh_transform;

	/* List of mesh vertex */
	std::vector<Vector3f> vertex;

	/* List of mesh normals */
	std::vector<Vector3f> normals;

	 /* List of mesh texture coordinates */
	std::vector<Vector2f> texcoord;
	
	/* List of submeshes */
	std::vector<std::vector<int>> triangles_submeshes;

	/* Error log */
	std::string log;

	/* Data */
	std::string data;

public:
	/* Default log error */
	const std::string LOG_ERROR = "ERROR_EXPORT_MESH";

public:
	/* Constructor */
	Mesh();

	/* Destructor */
	~Mesh();

public:
	/**
	 * @brief Modifies the transform
	 * @param position
	 * @param rotation
	 * @param scale
	 */
	void set_transform(Vector3f position, Vector3f rotation, Vector3f scale);

	/**
	 * @brief Modifies the vertex
	 * @param v array of vertex
	 * @param size of the array
	 */
	void set_vertex(Vector3f v[], int size);

	/**
	 * @brief Modifies the normals
	 * @param n Array of normals
	 * @param size of the array
	 */
	void set_normals(Vector3f n[], int size);

	/**
	 * @brief Modifies the texture coord array
	 * @param tc Array of texture coord
	 * @param size of the array
	 */
	void set_texcoord(Vector2f tc[], int size);

	/**
	 * @brief Returns the number of vertex
	 */
	size_t get_vertex_count() const;

	/**
	 * @brief Returns the log
	 */
	const std::string& get_log() const;

	/**
	 * @brief exports the mesh
	 * @param last_index index of the mesh
	 * @return export text
	 */
	std::string& export_mesh(int last_index);

	/**
	 * @brief Modifies the size of submeshes
	 */
	void set_submeshes_size(size_t size);

	/**
	 * @brief Modifies the triangles of a submesh
	 * @param submesh index of the submesh
	 * @param triangles Array of triangles
	 * @param size of the array
	 * @return true 
	 * @return false 
	 */
	bool set_triangles(int submesh, int triangles[], int size);
};
#endif
