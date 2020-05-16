#pragma once
#include <vxl/voxel.hpp>

namespace vxl
{
	template<class TID, class TMD>
	class VoxelArray
	{
	protected:
		TID unknown;
		std::vector<Voxel<TID, TMD>> voxels;
	public:
		VoxelArray(const TID _unknown, const std::vector<Voxel<TID, TMD>>& _voxels) :
			unknown(_unknown),
			voxels(_voxels)
		{}

		inline const TID& getUnknown() const noexcept
		{
			return unknown;
		}

		inline const Voxel<TID, TMD>& get(TID id) const noexcept
		{
			if (static_cast<size_t>(id) < voxels.size())
				return voxels[static_cast<size_t>(id)];
			else
				return voxels[static_cast<size_t>(unknown)];
		}
		template<class TV = Voxel<TID, TMD>>
		inline const TV& get(TID id) const noexcept
		{
			if (static_cast<size_t>(id) < voxels.size())
				return static_cast<TV&>(voxels[static_cast<size_t>(id)]);
			else
				return static_cast<TV&>(voxels[static_cast<size_t>(unknown)]);
		}
	};
}
