#pragma once
#include <voxel/cluster.hpp>
#include <voxel/sector.hpp>

#include <map>

namespace VOXEL_NAMESPACE
{
	template<class T = Sector>
	class Terrain
	{
	protected:
		std::map<Vec3<size_t>, T> sectors;

		inline const bool updateSector(const Registry& registry, const time_t deltaTime,
			const Vec3<size_t>& position, T& sector)
		{
			auto leftIterator = sectors.find(Vec3<size_t>(
				position.x + leftDir, position.y, position.z));
			if (leftIterator == sectors.end())
				return false;

			auto rightIterator = sectors.find(Vec3<size_t>(
				position.x + rightDir, position.y, position.z));
			if (rightIterator == sectors.end())
				return false;

			auto downIterator = sectors.find(Vec3<size_t>(
				position.x, position.y + downDir, position.z));
			if (downIterator == sectors.end())
				return false;

			auto upIterator = sectors.find(Vec3<size_t>(
				position.x, position.y + upDir, position.z));
			if (upIterator == sectors.end())
				return false;

			auto backIterator = sectors.find(Vec3<size_t>(
				position.x, position.y, position.z + backDir));
			if (backIterator == sectors.end())
				return false;

			auto forwardIterator = sectors.find(Vec3<size_t>(
				position.x, position.y, position.z + forwardDir));
			if (forwardIterator == sectors.end())
				return false;

			auto cluster = Cluster(sector,
				leftIterator->second,
				rightIterator->second,
				downIterator->second,
				upIterator->second,
				backIterator->second,
				forwardIterator->second);
			sector.update(registry, cluster, deltaTime);
			return true;
		}
	public:
		Terrain(const std::map<Vec3<size_t>, T>& _sectors = {}) :
			sectors(_sectors)
		{}
		virtual ~Terrain()
		{}

		virtual void update(const Registry& registry,
			const time_t deltaTime)
		{
			for (auto& pair : sectors)
				updateSector(registry, deltaTime, pair.first, pair.second);
		}
	};
}
