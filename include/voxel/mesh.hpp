#pragma once
#include <voxel/defines.hpp>
#include <vector>

namespace voxel
{
	struct Mesh
	{
		std::vector<VOXEL_MESH_VERTEX_T> vertices;
		std::vector<VOXEL_MESH_NORMAL_T> normals;
		std::vector<VOXEL_MESH_INDEX_T> indices;

		Mesh(const std::vector<VOXEL_MESH_VERTEX_T>& _vertices = {},
			const std::vector<VOXEL_MESH_NORMAL_T>& _normals = {},
			const std::vector<VOXEL_MESH_INDEX_T>& _indices = {}) :
			vertices(_vertices),
			normals(_normals),
			indices(_indices)
		{}
	};
}
