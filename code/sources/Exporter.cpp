

#include "stdafx.h"

#include "Exporter.h"
#include <iostream>
#include <fstream>

Exporter::Exporter()
{
	path = "";
	log = "";

}

bool Exporter::export_obj(std::string & path, std::string & name)
{
	set_path(path);
	this->name = name;

	if (!generate_file())
	{
		for (auto & ms : meshes)
		{
			log += ms->get_log();
		}
		return false;
	}

	return true;
}

const std::string & Exporter::get_path()
{
	return string_to_char(path);
}

void Exporter::set_path(const std::string & path)
{
	this->path = path;
}

void Exporter::add_mesh(Vector3f position, Vector3f rotation, Vector3f scale, Vector3f vertex[], Vector3f normals[], Vector2f uvs[], int size_v, int size_n, int size_uv)
{
	std::shared_ptr<Mesh> new_mesh;

	new_mesh->set_transform(position, rotation, scale);
	new_mesh->set_vertex(vertex, size_v);
	new_mesh->set_normals(normals, size_n);
	new_mesh->set_texcoord(uvs, size_uv);

	meshes.push_back(new_mesh);
}

bool Exporter::set_mesh_transform(int index, Vector3f position, Vector3f rotation, Vector3f scale)
{
	if( index >= meshes.size()) return false;

	meshes[index]->set_transform(position, rotation, scale);
	return true;
}

bool Exporter::set_mesh_by_index(int index, Vector3f vertex[], Vector3f normals[], Vector2f uvs[], int size_v, int size_n, int size_uv)
{
	if (index >= meshes.size()) return false;

	
	meshes[index]->set_vertex(vertex, size_v);
	meshes[index]->set_normals(normals, size_n);
	meshes[index]->set_texcoord(uvs, size_uv);

	return true;
}

void Exporter::set_meshes_count(int size)
{
	for (size_t i = 0; i < size; ++i)
	{
		std::shared_ptr<Mesh> new_mesh(new Mesh());

		meshes.push_back(new_mesh);
	}
}

bool Exporter::set_mesh_submeshes_count(int index, int size)
{
	if (index >= meshes.size()) return false;

	meshes[index]->set_submeshes_size(size);
	return true;
}

bool Exporter::set_submesh_triangles(int index, int submesh, int triangles[], int size)
{
	if (index >= meshes.size()) return false;

	return meshes[index]->set_triangles(submesh, triangles, size);
}

bool Exporter::generate_file()
{
	int last_index = 0;

	std::string file = "";

	for (auto & ms : meshes)
	{
		file += ms->export_mesh(last_index);
		last_index += ms->get_vertex_count();
	}
	 
	if (file == "") return false;

	std::ofstream archive;
	archive.open(path + "/" + name + ".obj");
	if (!archive) return false;
	archive << file << std::endl;
	archive.close();

	return true;
}

const char * Exporter::string_to_char(const std::string & s)
{
	int length_str = s.length() + 1;
	char* temp = new char[length_str];
	const char * str = new char[length_str];
	strcpy_s(temp, length_str, path.c_str());
	str = temp;

	return str;
}
