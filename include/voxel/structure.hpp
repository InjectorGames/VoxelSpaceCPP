#pragma once
#include <voxel/array3.hpp>
#include <voxel/cluster.hpp>
#include <voxel/sector.hpp>

#include <chrono>

namespace VOXEL_NAMESPACE
{
	// TODO: add template<class T = Sector>
	class Structure : public Array3<Sector>
	{
	protected:
		size_t updateIndex;

		inline const bool updateSector(const Register& _register, const time_t deltaTime,
			const Vec3<size_t>& position, Sector& sector)
		{
			size_t leftIndex;
			size_t rightIndex;
			size_t downIndex;
			size_t upIndex;
			size_t backIndex;
			size_t forwardIndex;

			if (positionToIndexNoex(position.x + leftDir, position.y, position.z, leftIndex) &&
				positionToIndexNoex(position.x + rightDir, position.y, position.z, rightIndex) &&
				positionToIndexNoex(position.x, position.y + downDir, position.z, downIndex) &&
				positionToIndexNoex(position.x, position.y + upDir, position.z, upIndex) &&
				positionToIndexNoex(position.x, position.y, position.z + backDir, backIndex) &&
				positionToIndexNoex(position.x, position.y, position.z + forwardDir, forwardIndex))
			{
				auto cluster = Cluster(sector,
					data[leftIndex],
					data[rightIndex],
					data[downIndex],
					data[upIndex],
					data[backIndex],
					data[forwardIndex]);
				sector.update(_register, cluster, deltaTime);
				return true;
			}
			else
			{
				return false;
			}
		}
	public:
		time_t maxUpdateTime;

		Structure(const Vec3<size_t>& size,
			const Sector& sector = Sector(),
			const time_t _maxUpdateTime = INFINITY) :
			Array3<Sector>(size, sector),
			maxUpdateTime(_maxUpdateTime)
		{}
		virtual ~Structure()
		{}

		virtual void update(const Register& _register,
			const time_t deltaTime)
		{
			const auto startTime = std::chrono::steady_clock::now();

			while (updateIndex < count)
			{
				const auto currentTime = std::chrono::steady_clock::now();
				const auto duration = std::chrono::duration_cast<
					std::chrono::duration<time_t>>(currentTime - startTime);

				if (duration.count() >= maxUpdateTime)
					return;

				const auto position = indexToPosition(updateIndex);
				auto& sector = data[updateIndex];
				updateSector(_register, deltaTime, position, sector);
				updateIndex++;
			}

			updateIndex = 0;
		}
	};
}
