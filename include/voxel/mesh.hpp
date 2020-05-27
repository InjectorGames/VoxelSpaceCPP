#pragma once
#include <voxel/defines.hpp>
#include <vector>

namespace VOXEL_NAMESPACE
{
	struct Mesh
	{
#if defined(VOXEL_USE_MESH_NORM)
		std::vector<mesh_norm_t> normals;
#endif

		std::vector<mesh_vert_t> vertices;
		std::vector<mesh_ind_t> indices;

		Mesh(
#if defined(VOXEL_USE_MESH_NORM)
			const std::vector<mesh_norm_t>& _normals = {},
#endif
			const std::vector<mesh_vert_t>& _vertices = {},
			const std::vector<mesh_ind_t>& _indices = {}
		) :
			
#if defined(VOXEL_USE_MESH_NORM)
			normals(_normals),
#endif
			vertices(_vertices),
			indices(_indices)
		{}
	};
}
