#pragma once
#include <voxel/voxel.hpp>
#include <stdexcept>

namespace VOXEL_NAMESPACE
{
	class Registry
	{
	protected:
		std::vector<Voxel> voxels;
	public:
		Registry(const std::vector<Voxel>& _voxels) :
			voxels(_voxels)
		{
			if (voxels.at(0).id != nullVoxelID)
				throw std::runtime_error("Incorrect null voxel");
			if (voxels.at(1).id != unknownVoxelID)
				throw std::runtime_error("Incorrect unknown voxel");
		}

		inline const Voxel& get(const id_t id) const noexcept
		{
			if (id < voxels.size())
				return voxels[id];
			else
				return voxels[unknownVoxelID];
		}
		template<class TV = Voxel>
		inline const TV& get(const id_t id) const noexcept
		{
			if (id < voxels.size())
				return static_cast<TV&>(voxels[id]);
			else
				return static_cast<TV&>(voxels[unknownVoxelID]);
		}
	};
}
