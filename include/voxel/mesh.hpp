#pragma once
#include <voxel/defines.hpp>
#include <vector>

namespace VOXEL_NAMESPACE
{
	struct Mesh
	{
		std::vector<mesh_vert_t> vertices;
		std::vector<mesh_ind_t> indices;

		Mesh(
			const std::vector<mesh_vert_t>& _vertices = {},
			const std::vector<mesh_ind_t>& _indices = {}) :
			vertices(_vertices),
			indices(_indices)
		{}
	};
}
