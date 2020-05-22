#pragma once
#include <voxel/defines.hpp>
#include <vector>

namespace VOXEL_NAMESPACE
{
	struct Mesh
	{
		std::vector<VOXEL_MESH_VERTEX_TYPE> vertices;
		std::vector<VOXEL_MESH_INDEX_TYPE> indices;
		std::vector<VOXEL_MESH_NORMAL_TYPE> normals;

		Mesh(const std::vector<VOXEL_MESH_VERTEX_TYPE>& _vertices = {},
			const std::vector<VOXEL_MESH_NORMAL_TYPE>& _normals = {},
			const std::vector<VOXEL_MESH_INDEX_TYPE>& _indices = {}) :
			vertices(_vertices),
			normals(_normals),
			indices(_indices)
		{}
	};
}
