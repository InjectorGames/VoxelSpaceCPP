#pragma once
#include <voxel/voxel.hpp>
#include <stdexcept>

namespace VOXEL_NAMESPACE
{
	class Register
	{
	protected:
		size_t count;
		std::vector<Voxel> voxels;
	public:
		Register(const std::vector<Voxel>& _voxels) :
			count(voxels.size()),
			voxels(_voxels)
		{
			if (voxels.at(0).id != nullVoxelID)
				throw std::runtime_error("Incorrect null voxel");
			if (voxels.at(1).id != unknownVoxelID)
				throw std::runtime_error("Incorrect unknown voxel");
		}

		inline const Voxel& get(const id_t id) const noexcept
		{
			if (id < count)
				return voxels[id];
			else
				return voxels[unknownVoxelID];
		}
		template<class TV = Voxel>
		inline const TV& get(const id_t id) const noexcept
		{
			if (id < count)
				return static_cast<TV&>(voxels[id]);
			else
				return static_cast<TV&>(voxels[unknownVoxelID]);
		}
	};
}
