#pragma once
#include <vxl/sector.hpp>

namespace vxl
{
	template<class TID, class TMD>
	struct SectorGroup
	{
		const Sector<TID, TMD>& center;
		const Sector<TID, TMD>& left;
		const Sector<TID, TMD>& right;
		const Sector<TID, TMD>& down;
		const Sector<TID, TMD>& up;
		const Sector<TID, TMD>& back;
		const Sector<TID, TMD>& forward;

		SectorGroup(const Sector<TID, TMD>& _center,
			const Sector<TID, TMD>& _left,
			const Sector<TID, TMD>& _right,
			const Sector<TID, TMD>& _down,
			const Sector<TID, TMD>& _up,
			const Sector<TID, TMD>& _back,
			const Sector<TID, TMD>& _forward) :
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
