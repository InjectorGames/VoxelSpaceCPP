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
		virtual void generate(
			const Registry& registry,
			const Cluster& cluster,
			const Vec3<size_t>& position,
			size_t& vertexIndex,
			Mesh& mesh) = 0;
	};
}
