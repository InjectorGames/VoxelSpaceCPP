#pragma once
#include <voxel/defines.hpp>

namespace VOXEL_NAMESPACE
{
	struct Cluster;
	class Registry;

	class Updater
	{
	public:
		virtual void update(const Registry& registry, const time_t deltaTime,
			const size_t index, Cluster& cluster) = 0;
	};
}
