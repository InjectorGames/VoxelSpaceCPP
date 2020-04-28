#pragma once
#include <cstdint>

namespace vxl
{
	typedef uint8_t voxel8_t;
	typedef uint16_t voxel16_t;
	typedef uint32_t voxel32_t;
	typedef uint64_t voxel64_t;

	typedef uint8_t metadata8_t;
	typedef uint16_t metadata16_t;
	typedef uint32_t metadata32_t;
	typedef uint64_t metadata64_t;

	enum class SideType
	{
		Left,
		Right,
		Down,
		Up,
		Back,
		Forward,
	};
}
