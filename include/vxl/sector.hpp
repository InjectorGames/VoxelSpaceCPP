#pragma once
#include <vxl/array3.hpp>
#include <vxl/voxel.hpp>
#include <vxl/voxel_array.hpp>

namespace vxl
{
	template<class TID, class TMD>
	struct SectorGroup;

	template<class TID, class TMD>
	class Sector
	{
	protected:
		Array3<TID> ids;
		Array3<TMD> mds;
	public:
		Sector(const Array3<TID>& _ids,
			const Array3<TMD>& _mds) :
			ids(_ids),
			mds(_mds)
		{}
		Sector(const size_t sizeX,
			const size_t sizeY,
			const size_t sizeZ,
			const TID& id = TID(),
			const TMD& md = TMD()) :
			ids(sizeX, sizeY, sizeZ, id),
			mds(sizeX, sizeY, sizeZ, md)
		{}
		Sector(const size_t sizeXYZ,
			const TID& id = TID(),
			const TMD& md = TMD()) :
			ids(sizeXYZ, id),
			mds(sizeXYZ, md)
		{}

		inline size_t getSize() const noexcept
		{
			return ids.getSize();
		}
		inline size_t getSizeX() const noexcept
		{
			return ids.getSizeX();
		}
		inline size_t getSizeY() const noexcept
		{
			return ids.getSizeY();
		}
		inline size_t getSizeZ() const noexcept
		{
			return ids.getSizeZ();
		}
		inline size_t getSizeXY() const noexcept
		{
			return ids.getSizeXY();
		}
		inline const Array3<TID>& getIds() const noexcept
		{
			return ids;
		}
		inline const Array3<TMD>& getMds() const noexcept
		{
			return mds;
		}

		inline TID& idAt(const size_t position)
		{
			return ids.at(position);
		}
		inline const TID& idAt(const size_t position) const
		{
			return ids.at(position);
		}
		inline TID& idAt(const size_t x, const size_t y, const size_t z)
		{
			return ids.at(x, y, z);
		}
		inline const TID& idAt(const size_t x, const size_t y, const size_t z) const
		{
			return ids.at(x, y, z);
		}

		inline TID& idAtUnsafe(const size_t position) noexcept
		{
			return ids.atUnsafe(position);
		}
		inline const TID& idAtUnsafe(const size_t position) const noexcept
		{
			return ids.atUnsafe(position);
		}
		inline TID& idAtUnsafe(const size_t x, const size_t y, const size_t z)  noexcept
		{
			return ids.atUnsafe(x, y, z);
		}
		inline const TID& idAtUnsafe(const size_t x, const size_t y, const size_t z) const noexcept
		{
			return ids.atUnsafe(x, y, z);
		}

		inline void update(const VoxelArray<TID, TMD>& voxels,
			SectorGroup<TID, TMD>& sectors,
			const double& deltaTime)
		{
			for (size_t i = 0; i < ids.getSize(); i++)
			{
				const auto& id = ids.atUnsafe(i);
				const auto& voxel = voxels.get(id);

				if (voxel.update)
					voxel.update(voxels, sectors, deltaTime, i);
			}
		}
	};
}
