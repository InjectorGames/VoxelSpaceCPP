#pragma once
#include <vxl/sector.hpp>
#include <vxl/sector_group.hpp>

namespace vxl
{
	template<class TID, class TMD>
	class Structure
	{
	protected:
		Array3<Sector<TID, TMD>> sectors;
	public:
		Structure(const Array3<Sector<TID, TMD>>& _sectors) :
			sectors(_sectors)
		{}
		Structure(const size_t sizeX,
			const size_t sizeY,
			const size_t sizeZ,
			const Sector<TID, TMD>& sector) :
			sectors(sizeX, sizeY, sizeZ, sector)
		{}
		Structure(const size_t sizeXYZ,
			const Sector<TID, TMD>& sector) :
			sectors(sizeXYZ, sector)
		{}

		inline size_t getSize() const noexcept
		{
			return sectors.getSize();
		}
		inline size_t getSizeX() const noexcept
		{
			return sectors.getSizeX();
		}
		inline size_t getSizeY() const noexcept
		{
			return sectors.getSizeY();
		}
		inline size_t getSizeZ() const noexcept
		{
			return sectors.getSizeZ();
		}
		inline size_t getSizeXY() const noexcept
		{
			return sectors.getSizeXY();
		}
		inline const Array3<Sector<TID, TMD>>& getSectors() const noexcept
		{
			return sectors;
		}

		inline void update(const VoxelArray<TID, TMD>& voxels, SectorGroup<TID, TMD>& _sectors, const double& deltaTime)
		{
			for (size_t i = 0; i < sectors.getSize(); i++)
			{
				// TODO: if sector loaded update
			}
		}
	};
}
