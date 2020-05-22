#pragma once
#include <cstdint>

namespace VOXEL_NAMESPACE
{
#define VOXEL_NAMESPACE voxel

#if !defined(VOXEL_ID_TYPE)
#	if defined(VOXEL_ID_64)
#		define VOXEL_ID_TYPE uint64_t
#	elif defined(VOXEL_ID_32)
#		define VOXEL_ID_TYPE uint32_t
#	elif defined(VOXEL_ID_16)
#		define VOXEL_ID_TYPE uint16_t
#	elif defined(VOXEL_ID_8)
#		define VOXEL_ID_TYPE uint8_t
#	else
#		define VOXEL_ID_TYPE uint8_t
#	endif
#endif

#if !defined(VOXEL_MD_TYPE)
#	if defined(VOXEL_MD_64)
#		define VOXEL_MD_TYPE uint64_t
#	elif defined(VOXEL_MD_32)
#		define VOXEL_MD_TYPE uint32_t
#	elif defined(VOXEL_MD_16)
#		define VOXEL_MD_TYPE uint16_t
#	elif defined(VOXEL_MD_8)
#		define VOXEL_MD_TYPE uint8_t
#	else
#		define VOXEL_MD_TYPE uint8_t
#	endif
#endif

#if !defined(VOXEL_SECTOR_STATE_TYPE)
#	if defined(VOXEL_SECTOR_STATE_64)
#		define VOXEL_SECTOR_STATE_TYPE uint64_t
#	elif defined(VOXEL_SECTOR_STATE_32)
#		define VOXEL_SECTOR_STATE_TYPE uint32_t
#	elif defined(VOXEL_SECTOR_STATE_16)
#		define VOXEL_SECTOR_STATE_TYPE uint16_t
#	elif defined(VOXEL_SECTOR_STATE_8)
#		define VOXEL_SECTOR_STATE_TYPE uint8_t
#	else
#		define VOXEL_SECTOR_STATE_TYPE uint8_t
#	endif
#endif

#if !defined(VOXEL_MESH_VERTEX_TYPE)
#	if defined(VOXEL_MESH_VERTEX_DOUBLE)
#		define VOXEL_MESH_VERTEX_TYPE double
#	elif defined(VOXEL_MESH_VERTEX_FLOAT)
#		define VOXEL_MESH_VERTEX_TYPE float
#	else
#		define VOXEL_MESH_VERTEX_TYPE float
#	endif
#endif

#if !defined(VOXEL_MESH_NORMAL_TYPE)
#	if defined(VOXEL_MESH_NORMAL_DOUBLE)
#		define VOXEL_MESH_NORMAL_TYPE double
#	elif defined(VOXEL_MESH_NORMAL_FLOAT)
#		define VOXEL_MESH_NORMAL_TYPE float
#	else
#		define VOXEL_MESH_NORMAL_TYPE float
#	endif
#endif

#if !defined(VOXEL_MESH_INDEX_TYPE)
#	if defined(VOXEL_MESH_INDEX_32)
#		define VOXEL_MESH_INDEX_TYPE uint32_t
#	elif defined(VOXEL_MESH_INDEX_16)
#		define VOXEL_MESH_INDEX_TYPE uint16_t
#	elif defined(VOXEL_MESH_INDEX_8)
#		define VOXEL_MESH_INDEX_TYPE uint8_t
#	else
#		define VOXEL_MESH_INDEX_TYPE uint8_t
#	endif
#endif

#if !defined(VOXEL_TIME_TYPE)
#	if defined(VOXEL_TIME_DOUBLE)
#		define VOXEL_TIME_TYPE double
#	elif defined(VOXEL_TIME_FLOAT)
#		define VOXEL_TIME_TYPE float
#	else
#		define VOXEL_TIME_TYPE float
#	endif
#endif

#define VOXEL_ID_NULL (VOXEL_ID_TYPE)0
#define VOXEL_ID_UNKNOWN (VOXEL_ID_TYPE)1

#define VOXEL_MD_NULL (VOXEL_MD_TYPE)0

#define VOXEL_DIRECTION_ZERO 0
#define VOXEL_DIRECTION_LEFT -1
#define VOXEL_DIRECTION_RIGHT +1
#define VOXEL_DIRECTION_DOWN -1
#define VOXEL_DIRECTION_UP +1
#define VOXEL_DIRECTION_BACK -1
#define VOXEL_DIRECTION_FORWARD +1

#if !defined(VOXEL_SECTOR_LENGTH)
#	define VOXEL_SECTOR_LENGTH 10
#endif

#define VOXEL_SECTOR_SAFE_LENGTH VOXEL_SECTOR_LENGTH - 1
#define VOXEL_SECTOR_FACTOR VOXEL_SECTOR_LENGTH * VOXEL_SECTOR_LENGTH
#define VOXEL_SECTOR_SIZE VOXEL_SECTOR_LENGTH * VOXEL_SECTOR_LENGTH * VOXEL_SECTOR_LENGTH
#define VOXEL_SECTOR_ID_SIZE VOXEL_SECTOR_SIZE * sizeof(VOXEL_ID_TYPE)
#define VOXEL_SECTOR_MD_SIZE VOXEL_SECTOR_SIZE * sizeof(VOXEL_MD_TYPE)
}
