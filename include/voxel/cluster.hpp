#pragma once
#include <voxel/sector.hpp>

namespace VOXEL_NAMESPACE
{
	struct Cluster
	{
		std::shared_ptr<Sector> center;
		std::shared_ptr<Sector> left;
		std::shared_ptr<Sector> right;
		std::shared_ptr<Sector> down;
		std::shared_ptr<Sector> up;
		std::shared_ptr<Sector> back;
		std::shared_ptr<Sector> forward;

		Cluster(const std::shared_ptr<Sector>& _center = {},
			const std::shared_ptr<Sector>& _left = {},
			const std::shared_ptr<Sector>& _right = {},
			const std::shared_ptr<Sector>& _down = {},
			const std::shared_ptr<Sector>& _up = {},
			const std::shared_ptr<Sector>& _back = {},
			const std::shared_ptr<Sector>& _forward = {}) :
			center(_center),
			left(_left),
			right(_right),
			down(_down),
			up(_up),
			back(_back),
			forward(_forward)
		{}
	};
}
