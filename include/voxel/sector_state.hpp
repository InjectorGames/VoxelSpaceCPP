#pragma once
#include <voxel/defines.hpp>
#include <cstdint>

namespace VOXEL_NAMESPACE
{
	enum class SectorState : uint8_t
	{
		Created,
		Loading,
		Loaded,
		Processing,
		Processed,
	};
}