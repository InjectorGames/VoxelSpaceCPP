#pragma once
#include <voxel/array3.hpp>
#include <voxel/cluster.hpp>
#include <voxel/sector.hpp>

#include <chrono>

namespace VOXEL_NAMESPACE
{
	template<class T = Sector>
	class Structure : public Array3<std::shared_ptr<T>>
	{
	protected:
		structure_pos_t position;
		// TODO: rotation
	public:
		Structure(const Vec3<size_t>& size,
			const structure_pos_t& _position) :
			Array3<std::shared_ptr<T>>(size, nullptr),
			position(_position)
		{
			for (size_t z = 0; z < size.z; z++)
			{
				for (size_t y = 0; y < size.y; y++)
				{
					for (size_t x = 0; x < size.x; x++)
					{
						const auto position = sector_pos_t(x, y, z);
						set(x, y, z, std::make_shared<Sector>(position));
					}
				}
			}
		}
		virtual ~Structure()
		{}

		inline const structure_pos_t& getPosition() const noexcept
		{
			return position;
		}

		virtual void update(
			const Registry& registry,
			const time_t deltaTime)
		{
			for (size_t i = 0; i < count; i++)
			{
				const auto sector = get(i);
				const auto position = indexToPosition<sectorLength, sectorLegth>(i);
				auto cluster = Cluster(sector);
				getCluster(position, sector);
				sector->update(registry, cluster, deltaTime);
			}
		}

		inline void getCluster(
			const Vec3<size_t>& position,
			Cluster& cluster) const noexcept
		{
			size_t index;

			if (positionToIndexNoex<sectorLegth, sectorLegth, sectorLegth>
				(position.x + leftDir, position.y, position.z, index))
				cluster.left = get(index);
			else
				cluster.left = nullptr;

			if (positionToIndexNoex<sectorLegth, sectorLegth, sectorLegth>
				(position.x + rightDir, position.y, position.z, index))
				cluster.right = get(index);
			else
				cluster.right = nullptr;

			if (positionToIndexNoex<sectorLegth, sectorLegth, sectorLegth>
				(position.x, position.y + downDir, position.z, index))
				cluster.down = get(index);
			else
				cluster.down = nullptr;

			if (positionToIndexNoex<sectorLegth, sectorLegth, sectorLegth>
				(position.x, position.y + upDir, position.z, index))
				cluster.up = get(index);
			else
				cluster.up = nullptr;

			if (positionToIndexNoex<sectorLegth, sectorLegth, sectorLegth>
				(position.x, position.y, position.z + backDir, index))
				cluster.back = get(index);
			else
				cluster.back = nullptr;

			if (positionToIndexNoex<sectorLegth, sectorLegth, sectorLegth>
				(position.x, position.y, position.z + forwardDir, index))
				cluster.forward = get(index);
			else
				cluster.forward = nullptr;
		}
	};
}
