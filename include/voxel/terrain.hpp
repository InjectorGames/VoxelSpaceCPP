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
		terrain_pos_t position;
		std::map<sector_pos_t, std::shared_ptr<T>> sectors;
	public:
		Terrain(const terrain_pos_t& _position,
			const std::map<sector_pos_t, std::shared_ptr<T>>& _sectors = {}) :
			position(_position),
			sectors(_sectors)
		{}
		virtual ~Terrain()
		{}

		inline const terrain_pos_t& getPosition() const noexcept
		{
			return position;
		}

		inline const std::shared_ptr<T>& getSector(
			const sector_pos_t& position) const
		{
			const auto iterator = sectors.find(position);
			if (iterator == sectors.end())
				throw std::runtime_error("Failed to find sector");
			return iterator.second;
		}
		inline void addSector(
			const std::shared_ptr<T>& sector)
		{
			if (!sectors.emplace(sector->getPosition(), sector).second)
				throw std::runtime_error("Failed to add sector");
		}
		inline void removeSector(
			const sector_pos_t& position)
		{
			if (sectors.erase(position) == 0)
				throw std::runtime_error("Failed to remove sector");
		}

		inline const bool tryGetSector(
			const sector_pos_t& position,
			std::shared_ptr<T>& sector) const noexcept
		{
			const auto iterator = sectors.find(position);
			if (iterator == sectors.end())
				return false;
			sector = iterator->second;
			return true;
		}
		inline const bool tryAddSector(
			const sector_pos_t& position,
			const std::shared_ptr<T>& sector) noexcept
		{
			return sectors.emplace(position, sector).second;
		}
		inline const bool tryRemoveSector(
			const sector_pos_t& position) noexcept
		{
			return sectors.erase(position) > 0;
		}

		inline void removeAll() noexcept
		{
			sectors.clear();
		}

		virtual void update(
			const Registry& registry,
			const time_t deltaTime)
		{
			for (auto& pair : sectors)
			{
				auto cluster = Cluster(pair.second);
				getCluster(pair.first, cluster);
				pair.second->update(registry, cluster, deltaTime);
			}
		}

		inline void getCluster(
			const sector_pos_t& position,
			Cluster& cluster) const noexcept
		{
			auto iterator = sectors.find(sector_pos_t(
				position.x + leftDir, position.y, position.z));
			if (iterator != sectors.end())
				cluster.left = iterator->second;
			else
				cluster.left = nullptr;

			iterator = sectors.find(sector_pos_t(
				position.x + rightDir, position.y, position.z));
			if (iterator != sectors.end())
				cluster.right = iterator->second;
			else
				cluster.right = nullptr;

			iterator = sectors.find(sector_pos_t(
				position.x, position.y + downDir, position.z));
			if (iterator != sectors.end())
				cluster.down = iterator->second;
			else
				cluster.down = nullptr;

			iterator = sectors.find(sector_pos_t(
				position.x, position.y + upDir, position.z));
			if (iterator != sectors.end())
				cluster.up = iterator->second;
			else
				cluster.up = nullptr;

			iterator = sectors.find(sector_pos_t(
				position.x, position.y, position.z + backDir));
			if (iterator != sectors.end())
				cluster.back = iterator->second;
			else
				cluster.back = nullptr;

			iterator = sectors.find(sector_pos_t(
				position.x, position.y, position.z + forwardDir));
			if (iterator != sectors.end())
				cluster.forward = iterator->second;
			else
				cluster.forward = nullptr;
		}
	};
}
