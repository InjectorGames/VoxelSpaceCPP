#pragma once
#include <voxel/defines.hpp>
#include <vector>

namespace VOXEL_NAMESPACE
{
	struct Mesh
	{
		std::vector<mesh_vert_t> vertices;
		std::vector<mesh_ind_t> indices;
		std::vector<mesh_norm_t> normals;

		Mesh(const std::vector<mesh_vert_t>& _vertices = {},
			const std::vector<mesh_ind_t>& _indices = {},
			const std::vector<mesh_norm_t>& _normals = {}) :
			vertices(_vertices),
			indices(_indices),
			normals(_normals)
		{}
	};
}
