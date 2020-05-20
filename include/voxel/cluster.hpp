#pragma once
#include <voxel/sector.hpp>

namespace voxel
{
	struct Cluster
	{
		const Sector& center;
		const Sector& left;
		const Sector& right;
		const Sector& down;
		const Sector& up;
		const Sector& back;
		const Sector& forward;

		Cluster(const Sector& _center,
			const Sector& _left,
			const Sector& _right,
			const Sector& _down,
			const Sector& _up,
			const Sector& _back,
			const Sector& _forward) :
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
