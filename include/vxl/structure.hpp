#pragma once
#include <vxl/vector.hpp>
#include <vxl/sector.hpp>

namespace vxl
{
	template<class TID, class TMD>
	class Structure;

	template<class TID, class TMD>
	class Structure
	{
	protected:
		Vector3<Sector<TID, TMD>> m_sectors;
	public:
		Structure(const Vector3<Sector<TID, TMD>>& sectors) :
			m_sectors(sectors)
		{}
		Structure(const size_t sizeX, const size_t sizeY, const size_t sizeZ, const Sector<TID, TMD>& sector) :
			m_sectors(sizeX, sizeY, sizeZ, sector)
		{}
		Structure(const size_t sizeXYZ, const Sector<TID, TMD>& sector) :
			m_sectors(sizeXYZ, sector)
		{}

		inline size_t size() const noexcept
		{
			return m_sectors.size();
		}
		inline size_t sizeX() const noexcept
		{
			return m_sectors.sizeX();
		}
		inline size_t sizeY() const noexcept
		{
			return m_sectors.sizeY();
		}
		inline size_t sizeZ() const noexcept
		{
			return m_sectors.sizeZ();
		}
		inline size_t sizeXY() const noexcept
		{
			return m_sectors.sizeXY();
		}
		
		inline void resize(const size_t sizeX, const size_t sizeY, const size_t sizeZ, const Sector<TID, TMD>& sector)
		{
			// TODO: clear structure
			m_sectors.resize(sizeX, sizeY, sizeZ, sector);
		}
		inline void resize(const size_t sizeXYZ, const Sector<TID, TMD>& sector)
		{
			// TODO: clear structure
			m_sectors.resize(sizeXYZ, sector);
		}

		inline const Vector3<Sector<TID, TMD>>& sectors() const noexcept
		{
			return m_sectors;
		}

		inline void update(const VoxelArray<TID, TMD>& voxels, SectorGroup<TID, TMD>& sectors, const double& deltaTime)
		{
			for (size_t i = 0; i < m_sectors.size(); i++)
			{
				// TODO: if sector loaded update
			}
		}
	};
}
