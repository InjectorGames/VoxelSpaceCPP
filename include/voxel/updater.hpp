#pragma once
#include <voxel/defines.hpp>

namespace VOXEL_NAMESPACE
{
	class Cluster;
	class Register;

	class Updater
	{
	public:
		virtual void update(
			const Register& _register,
			Cluster& cluster,
			const VOXEL_TIME_TYPE deltaTime,
			const size_t index) = 0;
	};
}
