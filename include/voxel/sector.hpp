#pragma once
#include <voxel/defines.hpp>
#include <voxel/register.hpp>

namespace voxel
{
	class Cluster;

	class Sector
	{
	protected:
		std::array<VOXEL_ID_T, VOXEL_SECTOR_SIZE> ids;
		std::array<VOXEL_MD_T, VOXEL_SECTOR_SIZE> mds;
	public:
		VOXEL_SECTOR_STATE_T state;

		Sector(const std::array<VOXEL_ID_T, VOXEL_SECTOR_SIZE>& _ids,
			const std::array<VOXEL_MD_T, VOXEL_SECTOR_SIZE>& _mds,
			const VOXEL_SECTOR_STATE_T _state = VOXEL_SECTOR_STATE_T()) :
			ids(_ids),
			mds(_mds),
			state(_state)
		{}
		Sector(const VOXEL_ID_T id = VOXEL_ID_NULL,
			const VOXEL_MD_T md = VOXEL_MD_NULL,
			const VOXEL_SECTOR_STATE_T _state = VOXEL_SECTOR_STATE_T()) :
			ids(),
			mds(),
			state(_state)
		{
			ids.fill(id);
			mds.fill(md);
		}

		inline const VOXEL_ID_T getSafeID(const size_t index) const
		{
			if (index >= VOXEL_SECTOR_SIZE)
				throw std::out_of_range("Out of size range");
			return ids[index];
		}
		inline void setSafeID(const size_t index, const VOXEL_ID_T value)
		{
			if (index >= VOXEL_SECTOR_SIZE)
				throw std::out_of_range("Out of size range");
			ids[index] = value;
		}

		inline const VOXEL_ID_T getSafeID(const size_t x, const size_t y, const size_t z) const
		{
			if (x * y * z >= VOXEL_SECTOR_SIZE)
				throw std::out_of_range("Out of size range");
			return ids[x + y * VOXEL_SECTOR_LENGTH + z * VOXEL_SECTOR_FACTOR];
		}
		inline void setSafeID(const size_t x, const size_t y, const size_t z, const VOXEL_ID_T value)
		{
			if (x * y * z >= VOXEL_SECTOR_SIZE)
				throw std::out_of_range("Out of size range");
			ids[x + y * VOXEL_SECTOR_LENGTH + z * VOXEL_SECTOR_FACTOR] = value;
		}

		inline const VOXEL_ID_T getID(const size_t index) const noexcept
		{
			return ids[index];
		}
		inline void setID(const size_t index, const VOXEL_ID_T value) noexcept
		{
			ids[index] = value;
		}

		inline const VOXEL_ID_T getID(const size_t x, const size_t y, const size_t z) const noexcept
		{
			return ids[x + y * VOXEL_SECTOR_LENGTH + z * VOXEL_SECTOR_FACTOR];
		}
		inline void setID(const size_t x, const size_t y, const size_t z, const VOXEL_ID_T value) noexcept
		{
			ids[x + y * VOXEL_SECTOR_LENGTH + z * VOXEL_SECTOR_FACTOR] = value;
		}

		virtual void update(const Register& _register,
			Cluster& cluster, const VOXEL_TIME_T deltaTime)
		{
			for (size_t i = 0; i < VOXEL_SECTOR_SIZE; i++)
			{
				const auto id = ids[i];
				const auto& voxel = _register.get(id);

				if (voxel.updater)
					voxel.updater->update(_register, cluster, deltaTime, i);
			}
		}
	};
}
