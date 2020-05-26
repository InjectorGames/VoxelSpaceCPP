#pragma once
#include <voxel/structure.hpp>

// TODO: switch to FastNoise2
// https://github.com/Auburns/FastNoise2
#include <FastNoiseSIMD/FastNoiseSIMD.h>

namespace VOXEL_NAMESPACE
{
	// TODO: make this class abstract as mesh generator
	class Generator
	{
	protected:
		FastNoiseSIMD* fastNoise;
	public:
		Generator(int seed = 1337)
		{
			fastNoise = FastNoiseSIMD::NewFastNoiseSIMD(seed);
		}
		virtual ~Generator()
		{
			delete fastNoise;
			fastNoise = nullptr;
		}

		inline void generateRandom(Array3<id_t>& ids,
			const id_t id,
			const int32_t chance = 50,
			const uint32_t seed = 1337) const
		{
			if (chance < 0 || chance > 100)
				throw std::range_error("Chance out of range");

			srand(seed);

			const auto modulo = 10000 / chance;

			for (size_t i = 0; i < sectorSize; i++)
			{
				if(rand() % modulo < 100)
					ids.set(i, id);
			}
		}

		inline void generateMesh(Mesh& mesh,
			const Registry& registry,
			const Cluster& cluster)
		{
			for (size_t z = 0; z < sectorLength; z++)
			{
				for (size_t y = 0; y < sectorLength; y++)
				{
					for (size_t x = 0; x < sectorLength; x++)
					{
						const auto position = Vec3<size_t>(x, y, z);
						const auto id = cluster.center.getIDS().get(position);
						const auto& voxel = registry.get(id);

						if (voxel.renderer)
							voxel.renderer->generate(registry, cluster, position, mesh);
					}
				}
			}
		}
	};
}