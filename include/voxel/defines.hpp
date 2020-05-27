#pragma once
#define VOXEL_NAMESPACE voxel
#include <voxel/vec2.hpp>
#include <voxel/vec3.hpp>

#include <cstdint>

namespace voxel
{
#if defined(VOXEL_SIZE_VAL_TYPE)
	using size_val_t = VOXEL_SIZE_VAL_TYPE;
#else
	using size_val_t = size_t;
#endif

#if defined(VOXEL_SIZE_2_TYPE)
	using size2_t = VOXEL_SIZE_2_TYPE;
#else
	using size2_t = Vec2<size_val_t>;
#endif

#if defined(VOXEL_SIZE_3_TYPE)
	using size3_t = VOXEL_SIZE_3_TYPE;
#else
	using size3_t = Vec3<size_val_t>;
#endif

#if defined(VOXEL_ID_TYPE)
	using id_t = VOXEL_ID_TYPE;
#else
	using id_t = uint8_t;
#endif

#if defined(VOXEL_MD_TYPE)
	using md_t = VOXEL_MD_TYPE;
#else
	using md_t = uint8_t;
#endif

#if defined(VOXEL_MESH_VERT_TYPE)
	using mesh_vert_t = VOXEL_MESH_VERT_TYPE;
#else
	using mesh_vert_t = float;
#endif

#if defined(VOXEL_MESH_IND_TYPE)
	using mesh_ind_t = VOXEL_MESH_IND_TYPE;
#else
	using mesh_ind_t = uint8_t;
#endif

#if defined (VOXEL_USE_MESH_NORM)
#	if defined(VOXEL_MESH_NORM_TYPE)
	using mesh_norm_t = VOXEL_MESH_NORM_TYPE;
#	else
	using mesh_norm_t = float;
#	endif
#endif

#if defined(VOXEL_TIME_TYPE)
	using time_t = VOXEL_TIME_TYPE;
#else
	using time_t = float;
#endif

#if defined(VOXEL_STRUCTURE_POS_TYPE)
	using structure_pos_t = VOXEL_STRUCTURE_POS_TYPE;
#else
	using structure_pos_t = Vec3<float>;
#endif

#if defined(VOXEL_TERRAIN_POS_TYPE)
	using terrain_pos_t = VOXEL_TERRAIN_POS_TYPE;
#else
	using terrain_pos_t = Vec2<uint8_t>;
#endif

	constexpr auto zeroDir = 0;
	constexpr auto leftDir = -1;
	constexpr auto rightDir = -1;
	constexpr auto downDir = -1;
	constexpr auto upDir = -1;
	constexpr auto backDir = -1;
	constexpr auto forwardDir = -1;

	constexpr auto triangleVertCount = 3;
	constexpr auto quadVertCount = 4;

	constexpr id_t nullVoxelID = 0;
	constexpr id_t unknownVoxelID = 0;

	constexpr md_t nullVoxelMD = 0;

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
