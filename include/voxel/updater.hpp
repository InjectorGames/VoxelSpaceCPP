#pragma once
#include <voxel/defines.hpp>

namespace VOXEL_NAMESPACE
{
	class Cluster;
	class Register;

	class Updater
	{
	public:
		virtual void update(const Register& _register,
			const time_t deltaTime, const size_t index, Cluster& cluster) = 0;
	};
}
