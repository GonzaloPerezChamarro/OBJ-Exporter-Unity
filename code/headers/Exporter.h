/**
 * @file Exporter.h
 * @author Gonzalo Perez Chamarro (Gonzalo1810 GitHub.com)
 * @brief Clase exportador
 * @version 0.1
 * @date 2019-06-07
 * 
 * @copyright Copyright (c) 2019
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

	/**
	 * @brief Ruta de exportacion
	 * 
	 */
	std::string path;

	/**
	 * @brief Mensajes de error
	 * 
	 */
	std::string log;

	/**
	 * @brief Nombre del archivo
	 * 
	 */
	std::string name;

	/**
	 * @brief Conjunto de mallas que se van a exportar
	 * 
	 */
	std::vector<sh_Mesh> meshes;

public:
	/**
	 * @brief Construye el exportador
	 * 
	 */
	Exporter();

	/**
	 * @brief Destructor
	 * 
	 */
	~Exporter() = default;

public:
/**
 * @brief Genera un archivo .obj con el nombre y en la ruta recibidas
 * 
 * @param path Directorio de creacion
 * @param name Nombre del archivo
 * @return true Exportacion correcta
 * @return false Error
 */
	bool export_obj(std::string & path, std::string & name);

/**
 * @brief Devuelve la ruta de exportacion actual
 * 
 * @return const std::string& 
 */
	const std::string & get_path();

/**
 * @brief Modifica el valor de la ruta actual
 * 
 * @param path 
 */
	void set_path(const std::string & path);

/**
 * @brief Añade una nueva malla al vector de mallas
 * 
 * @param position Posicion de la malla
 * @param rotation rotacion de la malla
 * @param scale escala de la malla
 * @param vertex conjunto de vertices
 * @param normals conjunto de normales
 * @param uvs conjunto de uvs
 * @param size_v 
 * @param size_n 
 * @param size_uv 
 */
	void add_mesh(Vector3f position, Vector3f rotation, Vector3f scale, Vector3f vertex[], Vector3f normals[], Vector2f uvs[], int size_v, int size_n, int size_uv);
/**
 * @brief Modifica el valor del transform de una malla
 * 
 * @param index Indice de la malla
 * @param position Posicion de la malla
 * @param rotation Rotacion de la malla
 * @param scale Escala de la malla
 * @return true 
 * @return false 
 */
	bool set_mesh_transform(int index, Vector3f position, Vector3f rotation, Vector3f scale);
/**
 * @brief Modifica el valor de una malla
 * 
 * @param index Indice de la malla
 * @param vertex 
 * @param normals 
 * @param uvs 
 * @param size_v 
 * @param size_n 
 * @param size_uv 
 * @return true 
 * @return false 
 */
	bool set_mesh_by_index(int index, Vector3f vertex[], Vector3f normals[], Vector2f uvs[], int size_v, int size_n, int size_uv);
	/**
	 * @brief Modifica el tamaño del vector de mallas
	 * 
	 * @param size 
	 */
	void set_meshes_count(int size);
/**
 * @brief Modifica el tamaño del numero de submallas de una malla
 * 
 * @param index Indice de la malla
 * @param size Numero de submallas
 * @return true 
 * @return false 
 */
	bool set_mesh_submeshes_count(int index, int size);
	/**
	 * @brief Modifica el valor de los triangulos de una submalla
	 * 
	 * @param index Indice de malla
	 * @param submesh Indice de submalla
	 * @param triangles Conjunto de triangulos
	 * @param size Numero de triangulos
	 * @return true 
	 * @return false 
	 */
	bool set_submesh_triangles(int index, int submesh, int triangles[], int size);
/**
 * @brief Devuelve log 
 * 
 * @return const std::string& 
 */
	const std::string & get_log() { return log; }

/**
 * @brief Devuelve el numero de meshes
 * 
 * @return int 
 */
	int get_meshes_count() { return meshes.size(); }

private:
/**
 * @brief Genera el archivo .obj
 * 
 * @return true 
 * @return false 
 */
	bool generate_file();
/**
 * @brief Hace una conversion de string a array de char
 * 
 * @param s 
 * @return const char* 
 */
	const char * string_to_char(const std::string & s);
};