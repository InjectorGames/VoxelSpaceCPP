#pragma once
#include <vxl/vector.hpp>
#include <vxl/voxel.hpp>

namespace vxl
{
	template<class TID, class TMD>
	class Sector;
	template<class TID, class TMD>
	struct SectorGroup;
	struct SectorMesh;

	template<class TID, class TMD>
	class Sector
	{
	protected:
		Vector3<TID> m_ids;
		Vector3<TMD> m_mds;
	public:
		Sector(const Vector3<TID>& ids, const Vector3<TMD>& mds) :
			m_ids(ids),
			m_mds(mds)
		{}
		Sector(const size_t sizeX, const size_t sizeY, const size_t sizeZ, const TID& id = TID(), const TMD& md = TMD()) :
			m_ids(sizeX, sizeY, sizeZ, id),
			m_mds(sizeX, sizeY, sizeZ, md)
		{}
		Sector(const size_t sizeXYZ, const TID& id = TID(), const TMD& md = TMD()) :
			m_ids(sizeXYZ, id),
			m_mds(sizeXYZ, md)
		{}

		inline size_t size() const noexcept
		{
			return m_ids.size();
		}
		inline size_t sizeX() const noexcept
		{
			return m_ids.sizeX();
		}
		inline size_t sizeY() const noexcept
		{
			return m_ids.sizeY();
		}
		inline size_t sizeZ() const noexcept
		{
			return m_ids.sizeZ();
		}
		inline size_t sizeXY() const noexcept
		{
			return m_ids.sizeXY();
		}

		inline void resize(const size_t sizeX, const size_t sizeY, const size_t sizeZ)
		{
			m_ids.resize(sizeX, sizeY, sizeZ);
			m_mds.resize(sizeX, sizeY, sizeZ);
		}
		inline void resize(const size_t sizeX, const size_t sizeY, const size_t sizeZ, const TID& id, const TMD& md)
		{
			m_ids.resize(sizeX, sizeY, sizeZ, id);
			m_mds.resize(sizeX, sizeY, sizeZ, md);
		}
		inline void resize(const size_t sizeXYZ)
		{
			m_ids.resize(sizeXYZ);
			m_mds.resize(sizeXYZ);
		}
		inline void resize(const size_t sizeXYZ, const TID& id, const TMD& md)
		{
			m_ids.resize(sizeXYZ, id);
			m_mds.resize(sizeXYZ, md);
		}

		inline TID& idAt(const size_t position)
		{
			return m_ids.at(position);
		}
		inline const TID& idAt(const size_t position) const
		{
			return m_ids.at(position);
		}

		inline TID& idAt(const size_t x, const size_t y, const size_t z)
		{
			return m_ids.at(x, y, z);
		}
		inline const TID& idAt(const size_t x, const size_t y, const size_t z) const
		{
			return m_ids.at(x, y, z);
		}

		inline TID& idAtUnsafe(const size_t position) noexcept
		{
			return m_ids.atUnsafe(position);
		}
		inline const TID& idAtUnsafe(const size_t position) const noexcept
		{
			return m_ids.atUnsafe(position);
		}

		inline TID& idAtUnsafe(const size_t x, const size_t y, const size_t z)  noexcept
		{
			return m_ids.atUnsafe(x, y, z);
		}
		inline const TID& idAtUnsafe(const size_t x, const size_t y, const size_t z) const noexcept
		{
			return m_ids.atUnsafe(x, y, z);
		}

		inline const Vector3<TID>& ids() const noexcept
		{
			return m_ids;
		}
		inline const Vector3<TMD>& mds() const noexcept
		{
			return m_mds;
		}

		inline void update(const VoxelArray<TID, TMD>& voxels, SectorGroup<TID, TMD>& sectors, const double& deltaTime)
		{
			for (size_t i = 0; i < m_ids.size(); i++)
			{
				const auto& voxel = voxels.at(m_ids.atUnsafe(i));

				if (voxel.update)
					voxel.update(voxels, sectors, deltaTime, i);
			}
		}
	};

	template<class TID, class TMD>
	struct SectorGroup
	{
		const Sector<TID, TMD>& center;
		const Sector<TID, TMD>& left;
		const Sector<TID, TMD>& right;
		const Sector<TID, TMD>& down;
		const Sector<TID, TMD>& up;
		const Sector<TID, TMD>& back;
		const Sector<TID, TMD>& forward;

		SectorGroup(const Sector<TID, TMD>& _center, const Sector<TID, TMD>& _left, const Sector<TID, TMD>& _right, const Sector<TID, TMD>& _down, const Sector<TID, TMD>& _up, const Sector<TID, TMD>& _back, const Sector<TID, TMD>& _forward) :
			center(_center),
			left(_left),
			right(_right),
			down(_down),
			up(_up),
			back(_back),
			forward(_forward)
		{}
	};

	struct SectorMesh
	{
		std::vector<float> vertices;
		std::vector<uint32_t> indices;

		SectorMesh() :
			vertices(),
			indices()
		{}
	};
}
