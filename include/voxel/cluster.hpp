#pragma once
#include <voxel/sector.hpp>

namespace VOXEL_NAMESPACE
{
	struct Cluster
	{
		Sector& center;
		Sector& left;
		Sector& right;
		Sector& down;
		Sector& up;
		Sector& back;
		Sector& forward;

		Cluster(Sector& _center,
			Sector& _left,
			Sector& _right,
			Sector& _down,
			Sector& _up,
			Sector& _back,
			Sector& _forward) :
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
