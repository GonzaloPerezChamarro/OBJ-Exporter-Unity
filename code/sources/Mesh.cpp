
#include "stdafx.h"
#include "Mesh.h"

Mesh::Mesh()
	:mesh_transform(Transform())
{
	log = "";
	data = "";
}

Mesh::~Mesh()
{
}

void Mesh::set_transform(Vector3f position, Vector3f rotation, Vector3f scale)
{
	mesh_transform.set(position, rotation, scale);

}

void Mesh::set_vertex(Vector3f v[], int size)
{
	vertex.clear();
	vertex.resize(size);
	for (size_t i = 0; i < size; ++i)
	{
		vertex[i] = v[i];
	}
}

void Mesh::set_normals(Vector3f n[], int size)
{
	normals.clear();
	normals.resize(size);
	for (size_t i = 0; i < size; ++i)
	{
		normals[i] = n[i];
	}
}

void Mesh::set_texcoord(Vector2f tc[], int size)
{
	texcoord.clear();
	texcoord.resize(size);
	for (size_t i = 0; i < size; ++i)
	{
		texcoord[i] = tc[i];
	}
}

size_t Mesh::get_vertex_count() 
{
	return vertex.size();
}

const std::string & Mesh::get_log()
{
	return log;
}

std::string & Mesh::export_mesh(int last_index)
{
	int order = int(mesh_transform.scale.x * mesh_transform.scale.z);

	if (order < -1) order = -1;
	else if (order > 1) order = 1;

	for (auto & v : vertex)
	{
		Vector3f copy_vertex = v;

		copy_vertex = Vector3f::multiply(copy_vertex, mesh_transform.scale);
		//Rotacion
		copy_vertex += mesh_transform.position;
		copy_vertex.x *= -1;
		data += "\n";
		data += "v " + std::to_string(copy_vertex.x) + " " + std::to_string(copy_vertex.y) + " " + std::to_string(copy_vertex.z);
	}

	for (auto & n : normals)
	{
		Vector3f copy_normal = n;

		copy_normal = Vector3f::multiply(copy_normal, mesh_transform.scale.normalized());
		//Rotacion
		copy_normal += mesh_transform.position;
		copy_normal.x *= -1;
		data += "\n";
		data += "vn " + std::to_string(copy_normal.x) + " " + std::to_string(copy_normal.y) + " " + std::to_string(copy_normal.z);
	}

	for (auto & t : texcoord)
	{
		data += "\n";
		data += "vt " + std::to_string(t.x) + " " + std::to_string(t.y);
	}

	for (auto & tris : triangles_submeshes)
	{
		for (size_t i = 0; i < tris.size(); i += 3)
		{
			int id1 = tris[i] + 1 + last_index;
			int id2 = tris[i + 1] + 1 + last_index;
			int id3 = tris[i + 2] + 1 + last_index;

			std::string aux;
			std::string aux2;
			std::string aux3;
			if (order < 0)
			{
				aux = std::to_string(id1);
				aux2 = std::to_string(id2);
				aux3 = std::to_string(id3);
			}
			else
			{
				aux = std::to_string(id3);
				aux2 = std::to_string(id2);
				aux3 = std::to_string(id1);
			}

			data += "\n";
			data += "f " + aux + "/" + aux + "/" + aux;
			data += " " + aux2 + "/" + aux2 + "/" + aux2;
			data += " " + aux3 + "/" + aux3 + "/" + aux3;
		}
	}

	return data;
}

void Mesh::set_submeshes_size(size_t size)
{
	triangles_submeshes.clear();
	triangles_submeshes.resize(size);
}

bool Mesh::set_triangles(int submesh, int triangles[], int size)
{
	if (submesh >= triangles_submeshes.size()) return false;


	std::vector<int> aux;
	aux.resize(size);
	for (size_t i = 0; i < size; ++i)
	{
		aux[i] = triangles[i];
	}
	triangles_submeshes[submesh] = aux;

	return true;
}
