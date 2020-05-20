#pragma once
#include <voxel/defines.hpp>
#include <voxel/array3.hpp>
#include <voxel/cluster.hpp>
#include <voxel/sector.hpp>

#include <stdio>
#include <chrono>

namespace voxel
{
	class Structure : public Array3<Sector>
	{
	protected:
		VOXEL_TIME_T maxUpdateTime;

		inline const Cluster getCluster(
			const size_t x, const size_t y, const size_t z) const
		{
			return Cluster(
				get(x, y, z),
				get(x + VOXEL_DIRECTION_LEFT, y, z),
				get(x + VOXEL_DIRECTION_RIGHT, y, z),
				get(x, y + VOXEL_DIRECTION_DOWN, z),
				get(x, y + VOXEL_DIRECTION_UP, z),
				get(x, y, z + VOXEL_DIRECTION_BACK),
				get(x, y, z + VOXEL_DIRECTION_FORWARD));
		}

		virtual void handleException(const std::exception& exception)
		{}
		virtual void loadSector(Sector& sector)
		{
			sector.state = static_cast<VOXEL_SECTOR_STATE_T>(SectorState::Loaded);
		}
		virtual void unloadSector(const Sector& sector)
		{
			sector.state = static_cast<VOXEL_SECTOR_STATE_T>(SectorState::Created);
		}
		virtual void renderSector(const Cluster& cluster)
		{
			cluster.center.state = static_cast<VOXEL_SECTOR_STATE_T>(SectorState::Rendered);
		}
	public:
		Structure(
			const size_t sizeX, const size_t sizeY, const size_t sizeZ,
			const Sector& sector = Sector(),
			const VOXEL_TIME_T _maxUpdateTime = INFINITY) :
			Array3<Sector>(sizeX, sizeY, sizeZ, sector),
			maxUpdateTime(_maxUpdateTime)
		{}

		virtual void update(const Register& _register,
			const VOXEL_TIME_T deltaTime)
		{
			auto index = static_cast<size_t>(0);
			auto startTime = std::chrono::steady_clock::now();

			for (size_t z = 0; z < sizeZ; z++)
			{
				for (size_t y = 0; y < sizeY; y++)
				{
					for (size_t x = 0; x < sizeX; x++)
					{
						auto& sector = data[index];

						try
						{
							if (sector.state == static_cast<VOXEL_SECTOR_STATE_T>(SectorState::Created))
							{
								loadSector(sector);
							}
							else if (sector.state == static_cast<VOXEL_SECTOR_STATE_T>(SectorState::Loaded))
							{
								const auto cluster = getCluster(x, y, z);
								renderSector(cluster);
							}
							
							if (sector.state >= static_cast<VOXEL_SECTOR_STATE_T>(SectorState::Loaded))
							{
								const auto cluster = getCluster(x, y, z);
								sector.update(_register, cluster, deltaTime);
							}
						}
						catch (const std::exception& exception)
						{
							handleException(exception);
						}
						
						auto time = std::chrono::steady_clock::now();
						auto delay = std::chrono::duration_cast<
							std::chrono::duration<VOXEL_TIME_T>>(time - startTime);

						if (delay >= maxUpdateTime)
							return;

						index++;
					}
				}
			}
		}
	};
}
