#pragma once
#include <cstdint>

#define VOXEL_NAMESPACE voxel

namespace voxel
{
#if defined(VOXEL_ID_64)
	using id_t = uint64_t;
#elif defined(VOXEL_ID_32)
	using id_t = uint32_t;
#elif defined(VOXEL_ID_16)
	using id_t = uint16_t;
#elif defined(VOXEL_ID_8)
	using id_t = uint8_t;
#else
	using id_t = uint8_t;
#endif

#if defined(VOXEL_MD_64)
	using md_t = uint64_t;
#elif defined(VOXEL_MD_32)
	using md_t = uint32_t;
#elif defined(VOXEL_MD_16)
	using md_t = uint16_t;
#elif defined(VOXEL_MD_8)
	using md_t = uint8_t;
#else
	using md_t = uint8_t;
#endif

#if defined(VOXEL_MESH_VERTEX_DOUBLE)
	using mesh_vert_t = double;
#elif defined(VOXEL_MESH_VERTEX_FLOAT)
	using mesh_vert_t = float;
#else
	using mesh_vert_t = float;
#endif

#if defined(VOXEL_MESH_NORMAL_DOUBLE)
	using mesh_norm_t = double;
#elif defined(VOXEL_MESH_NORMAL_FLOAT)
	using mesh_norm_t = float;
#else
	using mesh_norm_t = float;
#endif

#if defined(VOXEL_MESH_INDEX_32)
	using mesh_ind_t = uint32_t;
#elif defined(VOXEL_MESH_INDEX_16)
	using mesh_ind_t = uint16_t;
#elif defined(VOXEL_MESH_INDEX_8)
	using mesh_ind_t = uint8_t;
#else
	using mesh_ind_t = uint8_t;
#endif

#if defined(VOXEL_TIME_DOUBLE)
	using time_t = double;
#elif defined(VOXEL_TIME_FLOAT)
	using time_t = float;
#else
	using time_t = float;
#endif

	constexpr id_t nullVoxelID = 0;
	constexpr id_t unknownVoxelID = 0;

	constexpr md_t nullVoxelMD = 0;

	constexpr auto zeroDir = 0;
	constexpr auto leftDir = -1;
	constexpr auto rightDir = -1;
	constexpr auto downDir = -1;
	constexpr auto upDir = -1;
	constexpr auto backDir = -1;
	constexpr auto forwardDir = -1;


#if !defined(VOXEL_SECTOR_LENGTH)
	constexpr size_t sectorLength = 10;
#else
	constexpr size_t sectorLength = VOXEL_SECTOR_LENGTH;
#endif
	constexpr size_t sectorSafeLength = sectorLength - 1;
	constexpr size_t sectorByteLengthID = sectorLength * sizeof(id_t);
	constexpr size_t sectorByteLengthMD = sectorLength * sizeof(md_t);

	constexpr size_t sectorSize = sectorLength * sectorLength * sectorLength;
	constexpr size_t sectorByteSizeID = sectorSize * sizeof(id_t);
	constexpr size_t sectorByteSizeMD = sectorSize * sizeof(md_t);
	constexpr size_t sectorByteSize = sectorByteSizeID + sectorByteSizeMD;
}
