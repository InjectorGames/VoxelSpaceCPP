#pragma once
#include <voxel/defines.hpp>
#include <voxel/cluster.hpp>

namespace VOXEL_NAMESPACE
{
	class MeshGenerator
	{
	public:
		inline static const Mesh generate(
			const Registry& registry,
			const Cluster& cluster)
		{
			if (!cluster.center)
				throw std::runtime_error("Cluster center is null");

			auto mesh = Mesh();

			for (size_t z = 0; z < sectorLength; z++)
			{
				for (size_t y = 0; y < sectorLength; y++)
				{
					for (size_t x = 0; x < sectorLength; x++)
					{
						const auto position = Vec3<size_t>(x, y, z);
						const auto& id = cluster.center->getIDS().get(position);
						const auto& voxel = registry.get(id);

						if (voxel.renderer)
							voxel.renderer->generate(
								registry, cluster, position, mesh);
					}
				}
			}

			return mesh;
		}
	};
}
