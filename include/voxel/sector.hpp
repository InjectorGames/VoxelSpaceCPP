#pragma once
#include <voxel/register.hpp>

namespace VOXEL_NAMESPACE
{
	class Cluster;

	class Sector
	{
	protected:
		VOXEL_ID_TYPE* ids;
		VOXEL_MD_TYPE* mds;
	public:
		VOXEL_SECTOR_STATE_TYPE state;

		Sector(const VOXEL_ID_TYPE id = VOXEL_ID_NULL,
			const VOXEL_MD_TYPE md = VOXEL_MD_NULL,
			const VOXEL_SECTOR_STATE_TYPE _state = VOXEL_SECTOR_STATE_TYPE()) :
			state(_state)
		{
			ids = new VOXEL_ID_TYPE[VOXEL_SECTOR_SIZE];
			std::fill_n(ids, VOXEL_SECTOR_SIZE, id);

			mds = new VOXEL_MD_TYPE[VOXEL_SECTOR_SIZE];
			std::fill_n(mds, VOXEL_SECTOR_SIZE, md);
		}
		Sector(const Sector& sector) :
			state(sector.state)
		{
			ids = new VOXEL_ID_TYPE[VOXEL_SECTOR_SIZE];
			std::copy_n(sector.ids, VOXEL_SECTOR_SIZE, ids);

			mds = new VOXEL_MD_TYPE[VOXEL_SECTOR_SIZE];
			std::copy_n(sector.mds, VOXEL_SECTOR_SIZE, mds);
		}
		virtual ~Sector()
		{
			delete[] ids;
			ids = nullptr;

			delete[] mds;
			mds = nullptr;
		}

		inline const VOXEL_ID_TYPE getSafeID(const size_t index) const
		{
			if (index >= VOXEL_SECTOR_SIZE)
				throw std::out_of_range("Out of size range");
			return ids[index];
		}
		inline void setSafeID(const size_t index, const VOXEL_ID_TYPE value)
		{
			if (index >= VOXEL_SECTOR_SIZE)
				throw std::out_of_range("Out of size range");
			ids[index] = value;
		}

		inline const VOXEL_ID_TYPE getSafeID(const size_t x, const size_t y, const size_t z) const
		{
			if (x * y * z >= VOXEL_SECTOR_SIZE)
				throw std::out_of_range("Out of size range");
			return ids[x + y * VOXEL_SECTOR_LENGTH + z * VOXEL_SECTOR_FACTOR];
		}
		inline void setSafeID(const size_t x, const size_t y, const size_t z, const VOXEL_ID_TYPE value)
		{
			if (x * y * z >= VOXEL_SECTOR_SIZE)
				throw std::out_of_range("Out of size range");
			ids[x + y * VOXEL_SECTOR_LENGTH + z * VOXEL_SECTOR_FACTOR] = value;
		}

		inline const VOXEL_ID_TYPE getID(const size_t index) const noexcept
		{
			return ids[index];
		}
		inline void setID(const size_t index, const VOXEL_ID_TYPE value) noexcept
		{
			ids[index] = value;
		}

		inline const VOXEL_ID_TYPE getID(const size_t x, const size_t y, const size_t z) const noexcept
		{
			return ids[x + y * VOXEL_SECTOR_LENGTH + z * VOXEL_SECTOR_FACTOR];
		}
		inline void setID(const size_t x, const size_t y, const size_t z, const VOXEL_ID_TYPE value) noexcept
		{
			ids[x + y * VOXEL_SECTOR_LENGTH + z * VOXEL_SECTOR_FACTOR] = value;
		}

		inline VOXEL_ID_TYPE* getIDS() noexcept
		{
			return ids;
		}
		inline const VOXEL_ID_TYPE* getIDS() const noexcept
		{
			return ids;
		}

		inline VOXEL_MD_TYPE* getMDS() noexcept
		{
			return mds;
		}
		inline const VOXEL_MD_TYPE* getMDS() const noexcept
		{
			return mds;
		}

		virtual void update(const Register& _register,
			Cluster& cluster, const VOXEL_TIME_TYPE deltaTime)
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
