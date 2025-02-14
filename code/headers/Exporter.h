/**
 * @file Exporter.h
 * @author Gonzalo Perez Chamarro (Gonzalo1810 GitHub.com)
 * @brief Clase exportador
 * @version 1.0
 * @date 2019-06-07
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#pragma once

#include "Mesh.h"

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#include <stdio.h>


class Exporter
{
private:
	typedef std::shared_ptr<Mesh> sh_Mesh;

	/* File name */
	std::string name;

	/* Export path*/
	std::string path;

	/* List of meshes to be exported */
	std::vector<sh_Mesh> meshes;

	/* Error log */
	std::string log;

public:
	/* Constructor */
	Exporter();

	/* Destructor by default */
	~Exporter() = default;

public:
	/**
	 * @brief It generates a .obj file with the name and path received
	 * 
	 * @param path Directory to create the file
	 * @param name File name
	 * @return if it was successful
	 */
	bool export_obj(std::string& path, std::string& name);

	/**
	 * @brief Returns the path of the current export
	 */
	const std::string& get_path() const;

	/**
	 * @brief Modifies the value of the current path
	 */
	void set_path(const std::string & path);

	/**
	 * @brief Adds a new mesh to the vector
	 * 
	 * @param position Mesh position
	 * @param rotation Mesh rotation
	 * @param scale Mesh scale
	 * @param vertex array of vertex
	 * @param normals array of normals
	 * @param uvs array of uvs
	 * @param size_v size of vertex array
	 * @param size_n size of normals array
	 * @param size_uv size of uvs array
	 */
	void add_mesh(Vector3f position, Vector3f rotation, Vector3f scale, Vector3f vertex[], Vector3f normals[], Vector2f uvs[], int size_v, int size_n, int size_uv);

	/**
	 * @brief Modifies the mesh's transform
	 * 
	 * @param index Mesh index
	 * @param position Mesh position
	 * @param rotation Mesh rotation
	 * @param scale Mesh scale
	 * @return true 
	 * @return false 
	 */
	bool set_mesh_transform(int index, Vector3f position, Vector3f rotation, Vector3f scale);

	/**
	 * @brief Modifies a mesh
	 * 
	 * @param index Index of the mesh
	 * @param vertex array of vertex
	 * @param normals array of normals 
	 * @param uvs array of uvs
	 * @param size_v size of vertex array
	 * @param size_n size of normals array
	 * @param size_uv size of uvs array
	 * @return true 
	 * @return false 
	 */
	bool set_mesh_by_index(int index, Vector3f vertex[], Vector3f normals[], Vector2f uvs[], int size_v, int size_n, int size_uv);
	
	/**
	 * @brief Modifies the size of the meshes vector
	 * @param size 
	 */
	void set_meshes_count(int size);

	/**
	 * @brief Modifica el tamaño del numero de submallas de una malla
	 * @brief Modifies the count of submeshes of a mesh
	 * 
	 * @param index index of the mesh
	 * @param size Number of submeshes
	 * @return true 
	 * @return false 
	 */
	bool set_mesh_submeshes_count(int index, int size);

	/**
	* @brief Modifica el valor de los triangulos de una submalla
	* @brief Modifies the triangles of a submesh
	* 
	* @param index Index of the mesh
	* @param submesh Index of the submesh
	* @param triangles Array of triangles
	* @param size Number of triangles
	* @return true 
	* @return false 
	*/
	bool set_submesh_triangles(int index, int submesh, int triangles[], int size);

	/**
	 * @brief Returns the log
	 */
	const std::string & get_log() const { return log; }

	/**
	 * @brief Returns the number of meshes
	 */
	int get_meshes_count() const { return meshes.size(); }

private:
	/**
	 * @brief Generates the .obj file
	 * @return if was succesful
	 */
	bool generate_file();

	/**
	 * @brief Converts a string into a char array
	 */
	const char* string_to_char(const std::string& s) const;
};