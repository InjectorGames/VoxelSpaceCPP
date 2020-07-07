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
		virtual void render(
			const Registry& registry,
			const Cluster& cluster,
			const Vec3<size_t>& position,
			size_t& vertexIndex,
			Mesh& mesh) = 0;

		inline static const Mesh render(
			const Registry& registry,
			const Cluster& cluster)
		{
			if (!cluster.center)
				throw std::runtime_error("Cluster center is null");

			auto mesh = Mesh();
			size_t vertexIndex = 0;

			for (size_t z = 0; z < sectorLength; z++)
			{
				for (size_t y = 0; y < sectorLength; y++)
				{
					for (size_t x = 0; x < sectorLength; x++)
					{
						const auto& ids = cluster.center->getIDS();
						const auto& id = ids.get(Vec3<size_t>(x, y, z));
						const auto& voxel = registry.get(id);

						if (voxel.renderer)
							voxel.renderer->generate(
								registry, cluster, position, vertexIndex, mesh);
					}
				}
			}

			return mesh;
		}
	};
}
