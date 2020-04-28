#pragma once
#include <vxl/vector.hpp>

namespace vxl
{
	template<class V, class M>
	class Sector
	{
	public:
		using Vector3 = Vector3<V>;
	protected:
		Vector3 m_voxels;
		Vector3 m_metadatas;
	public:
		Sector(const Vector3& voxels, const Vector3& metadatas) :
			m_voxels(voxels),
			m_metadatas(metadatas)
		{}
		Sector(const size_t sizeX, const size_t sizeY, const size_t sizeZ) :
			m_voxels(sizeX, sizeY, sizeZ),
			m_metadatas(sizeX, sizeY, sizeZ)
		{}
		Sector(const size_t sizeXYZ) :
			m_voxels(sizeXYZ),
			m_metadatas(sizeXYZ)
		{}

		inline size_t size() const noexcept
		{
			return m_voxels.size();
		}
		inline size_t sizeX() const noexcept
		{
			return m_voxels.sizeX();
		}
		inline size_t sizeY() const noexcept
		{
			return m_voxels.sizeY();
		}
		inline size_t sizeZ() const noexcept
		{
			return m_voxels.sizeZ();
		}
		inline size_t sizeXY() const noexcept
		{
			return m_voxels.sizeXY();
		}

		inline void resize(const size_t sizeX, const size_t sizeY, const size_t sizeZ)
		{
			m_voxels.resize(sizeX, sizeY, sizeZ);
			m_metadatas.resize(sizeX, sizeY, sizeZ);
		}
		inline void resize(const size_t sizeXYZ)
		{
			m_voxels.resize(sizeXYZ);
			m_metadatas.resize(sizeXYZ);
		}

		inline V& voxelAt(const size_t position)
		{
			return m_voxels.at(position);
		}
		inline const V& voxelAt(const size_t position) const
		{
			return m_voxels.at(position);
		}

		inline V& voxelAt(const size_t x, const size_t y, const size_t z)
		{
			return m_voxels.at(x, y, z);
		}
		inline const V& voxelAt(const size_t x, const size_t y, const size_t z) const
		{
			return m_voxels.at(x, y, z);
		}

		inline V& voxelAtUnsafe(const size_t position) noexcept
		{
			return m_voxels.atUnsafe(position);
		}
		inline const V& voxelAtUnsafe(const size_t position) const noexcept
		{
			return m_voxels.atUnsafe(position);
		}

		inline V& voxelAtUnsafe(const size_t x, const size_t y, const size_t z)  noexcept
		{
			return m_voxels.atUnsafe(x, y, z);
		}
		inline const V& voxelAtUnsafe(const size_t x, const size_t y, const size_t z) const noexcept
		{
			return m_voxels.atUnsafe(x, y, z);
		}

		inline const Vector3& voxels() const noexcept
		{
			return m_voxels;
		}
		inline const Vector3& metadatas() const noexcept
		{
			return m_metadatas;
		}
	};
}
