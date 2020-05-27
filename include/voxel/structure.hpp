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
			const size3_t& position, T& sector)
		{
			size_t leftIndex;
			size_t rightIndex;
			size_t downIndex;
			size_t upIndex;
			size_t backIndex;
			size_t forwardIndex;

			if (!positionToIndexNoex<sectorLegth, sectorLegth, sectorLegth>
				(position.x + leftDir, position.y, position.z, leftIndex) ||
				!positionToIndexNoex<sectorLegth, sectorLegth, sectorLegth>
				(position.x + rightDir, position.y, position.z, rightIndex) ||
				!positionToIndexNoex<sectorLegth, sectorLegth, sectorLegth>
				(position.x, position.y + downDir, position.z, downIndex) ||
				!positionToIndexNoex<sectorLegth, sectorLegth, sectorLegth>
				(position.x, position.y + upDir, position.z, upIndex) ||
				!positionToIndexNoex<sectorLegth, sectorLegth, sectorLegth>
				(position.x, position.y, position.z + backDir, backIndex) ||
				!positionToIndexNoex<sectorLegth, sectorLegth, sectorLegth>
				(position.x, position.y, position.z + forwardDir, forwardIndex))
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
		structure_pos_t position;

		Structure(const size3_t& size,
			const structure_pos_t& _position =
			structure_pos_t(),
			const T& sector = T()) :
			Array3<T>(size, sector),
			position(_position)
		{}
		virtual ~Structure()
		{}

		virtual void update(const Registry& registry,
			const time_t deltaTime)
		{
			for (size_t i = 0; i < count; i++)
			{
				const auto position = indexToPosition<sectorLength, sectorLegth>(i);
				updateSector(registry, deltaTime, position, get(i));
			}
		}
	};
}
