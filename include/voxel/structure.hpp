#pragma once
#include <voxel/array3.hpp>
#include <voxel/cluster.hpp>
#include <voxel/sector.hpp>

#include <chrono>

namespace VOXEL_NAMESPACE
{
	template<class T = Sector>
	class Structure : public Array3<T>
	{
	protected:
		inline const bool updateSector(const Registry& registry, const time_t deltaTime,
			const Vec3<size_t>& position, T& sector)
		{
			size_t leftIndex;
			size_t rightIndex;
			size_t downIndex;
			size_t upIndex;
			size_t backIndex;
			size_t forwardIndex;

			if (!positionToIndexNoex(position.x + leftDir, position.y, position.z, leftIndex) ||
				!positionToIndexNoex(position.x + rightDir, position.y, position.z, rightIndex) ||
				!positionToIndexNoex(position.x, position.y + downDir, position.z, downIndex) ||
				!positionToIndexNoex(position.x, position.y + upDir, position.z, upIndex) ||
				!positionToIndexNoex(position.x, position.y, position.z + backDir, backIndex) ||
				!positionToIndexNoex(position.x, position.y, position.z + forwardDir, forwardIndex))
				return false;

			auto cluster = Cluster(sector,
				get(leftIndex),
				get(rightIndex),
				get(downIndex),
				get(upIndex),
				get(backIndex),
				get(forwardIndex));
			sector.update(registry, cluster, deltaTime);
			return true;
		}
	public:
		Structure(const Vec3<size_t>& size,
			const T& sector = T()) :
			Array3<T>(size, sector)
		{}
		virtual ~Structure()
		{}

		virtual void update(const Registry& registry,
			const time_t deltaTime)
		{
			for (size_t i = 0; i < count; i++)
			{
				const auto position = indexToPosition(i);
				auto& sector = get(i);
				updateSector(registry, deltaTime, position, sector);
			}
		}
	};
}
