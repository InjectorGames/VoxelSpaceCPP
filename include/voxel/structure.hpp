#pragma once
#include <voxel/array3.hpp>
#include <voxel/cluster.hpp>
#include <voxel/sector.hpp>
#include <voxel/sector_state.hpp>

#include <chrono>

namespace VOXEL_NAMESPACE
{
	class Structure : public Array3<Sector>
	{
	protected:
		bool isShouldLoad;
		VOXEL_TIME_TYPE maxUpdateTime;

		inline Cluster getCluster(
			const size_t x, const size_t y, const size_t z)
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
	public:
		Structure(
			const size_t sizeX, const size_t sizeY, const size_t sizeZ,
			const Sector& sector = Sector(),
			const bool _isShouldLoad = true,
			const VOXEL_TIME_TYPE _maxUpdateTime = INFINITY) :
			Array3<Sector>(sizeX, sizeY, sizeZ, sector),
			isShouldLoad(_isShouldLoad),
			maxUpdateTime(_maxUpdateTime)
		{}
		virtual ~Structure()
		{}

		virtual void load(const size_t x, const size_t y, const size_t z, Sector& sector)
		{
			sector.state = static_cast<VOXEL_SECTOR_STATE_TYPE>(SectorState::Loaded);
		}
		virtual void unload(const size_t x, const size_t y, const size_t z, Sector& sector)
		{
			sector.state = static_cast<VOXEL_SECTOR_STATE_TYPE>(SectorState::Created);
		}
		virtual void process(const size_t x, const size_t y, const size_t z, Cluster& cluster)
		{
			cluster.center.state = static_cast<VOXEL_SECTOR_STATE_TYPE>(SectorState::Processed);
		}

		virtual void update(const Register& _register,
			const VOXEL_TIME_TYPE deltaTime)
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
							if (sector.state == static_cast<VOXEL_SECTOR_STATE_TYPE>(SectorState::Created))
							{
								if(isShouldLoad)
									load(x, y, z, sector);
							}
							else if (sector.state == static_cast<VOXEL_SECTOR_STATE_TYPE>(SectorState::Loaded))
							{
								if (!isShouldLoad)
								{
									unload(x, y, z, sector);
								}
								else
								{
									auto cluster = getCluster(x, y, z);
									sector.update(_register, cluster, deltaTime);
									process(x, y, z, cluster);
								}
							}
							else if (sector.state >= static_cast<VOXEL_SECTOR_STATE_TYPE>(SectorState::Processed))
							{
								auto cluster = getCluster(x, y, z);
								sector.update(_register, cluster, deltaTime);
							}
						}
						catch (const std::exception& exception)
						{
							handleException(exception);
						}
						
						auto time = std::chrono::steady_clock::now();
						auto delay = std::chrono::duration_cast<
							std::chrono::duration<VOXEL_TIME_TYPE>>(time - startTime);

						if (delay.count() >= maxUpdateTime)
							return;

						index++;
					}
				}
			}
		}

		virtual void loadAll()
		{
			auto index = static_cast<size_t>(0);

			for (size_t z = 0; z < sizeZ; z++)
			{
				for (size_t y = 0; y < sizeY; y++)
				{
					for (size_t x = 0; x < sizeX; x++)
					{
						auto& sector = data[index];
						load(x, y, z, sector);
						index++;
					}
				}
			}
		}
		virtual void unloadAll()
		{
			auto index = static_cast<size_t>(0);

			for (size_t z = 0; z < sizeZ; z++)
			{
				for (size_t y = 0; y < sizeY; y++)
				{
					for (size_t x = 0; x < sizeX; x++)
					{
						auto& sector = data[index];
						unload(x, y, z, sector);
						index++;
					}
				}
			}
		}
		virtual void processAll()
		{
			auto index = static_cast<size_t>(0);

			for (size_t z = 0; z < sizeZ; z++)
			{
				for (size_t y = 0; y < sizeY; y++)
				{
					for (size_t x = 0; x < sizeX; x++)
					{
						auto cluster = getCluster(x, y, z);
						process(x, y, z, cluster);
						index++;
					}
				}
			}
		}
	};
}
