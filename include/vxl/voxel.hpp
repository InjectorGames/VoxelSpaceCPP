#pragma once
#include <vxl/defines.hpp>

#include <vector>

namespace vxl
{
	template<class V>
	struct VoxelInfo
	{
		V voxel;
		bool passable;

		VoxelInfo(const V _voxel = V(), const bool _passable = false) :
			voxel(_voxel),
			passable(_passable)
		{}
	};

	template<class V, class I = VoxelInfo<V>>
	class VoxelInfoArray
	{
	protected:
		V m_unknown;
		std::vector<I> m_infos;
	public:
		VoxelInfoArray(const V unknown, const std::vector<I>& infos) :
			m_unknown(unknown),
			m_infos(infos)
		{}

		inline const V& unknown() const noexcept
		{
			return m_unknown;
		}

		inline I& at(V voxel) noexcept
		{
			if (static_cast<size_t>(voxel) < m_infos.size())
				return m_infos[static_cast<size_t>(voxel)];
			else
				return m_infos[static_cast<size_t>(m_unknown)];
		}
		inline const I& at(V voxel) const noexcept
		{
			if (static_cast<size_t>(voxel) < m_infos.size())
				return m_infos[static_cast<size_t>(voxel)];
			else
				return m_infos[static_cast<size_t>(m_unknown)];
		}
	};
}
