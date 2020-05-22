#pragma once
#include <voxel/voxel.hpp>
#include <stdexcept>

namespace VOXEL_NAMESPACE
{
	class Register
	{
	protected:
		std::vector<Voxel> voxels;
	public:
		Register(const std::vector<Voxel>& _voxels) :
			voxels(_voxels)
		{
			if (voxels.at(0).id != VOXEL_ID_NULL)
				throw std::runtime_error("Incorrect null voxel");
			if (voxels.at(1).id != VOXEL_ID_UNKNOWN)
				throw std::runtime_error("Incorrect unknown voxel");
		}

		inline const Voxel& get(const VOXEL_ID_TYPE id) const noexcept
		{
			if (id < voxels.size())
				return voxels[id];
			else
				return voxels[VOXEL_ID_UNKNOWN];
		}
		template<class TV = Voxel>
		inline const TV& get(const VOXEL_ID_TYPE id) const noexcept
		{
			if (id < voxels.size())
				return static_cast<TV&>(voxels[id]);
			else
				return static_cast<TV&>(voxels[VOXEL_ID_UNKNOWN]);
		}
	};
}
