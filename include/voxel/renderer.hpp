#pragma once
#include <voxel/vec3.hpp>
#include <voxel/mesh.hpp>

namespace VOXEL_NAMESPACE
{
	struct Cluster;
	class Registry;

	class Renderer
	{
	public:
		virtual void generate(const Registry& registry, const Cluster& cluster,
			 const size3_t& position, Mesh& mesh) = 0;
	};
}
