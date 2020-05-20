#pragma once
#include <cstdint>

namespace voxel
{
	enum class SectorState : uint8_t
	{
		Created,
		Loading,
		Loaded,
		Rendering,
		Rendered,
	};
}