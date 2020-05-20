#pragma once
#include <voxel/sector_state.hpp>

namespace voxel
{
#if !defined(VOXEL_ID_T)
#	if defined(VOXEL_ID_64)
#		define VOXEL_ID_T uint64_t
#	elif defined(VOXEL_ID_32)
#		define VOXEL_ID_T uint32_t
#	elif defined(VOXEL_ID_16)
#		define VOXEL_ID_T uint16_t
#	elif defined(VOXEL_ID_8)
#		define VOXEL_ID_T uint8_t
#	else
#		define VOXEL_ID_T uint8_t
#	endif
#endif

#if !defined(VOXEL_MD_T)
#	if defined(VOXEL_MD_64)
#		define VOXEL_MD_T uint64_t
#	elif defined(VOXEL_MD_32)
#		define VOXEL_MD_T uint32_t
#	elif defined(VOXEL_MD_16)
#		define VOXEL_MD_T uint16_t
#	elif defined(VOXEL_MD_8)
#		define VOXEL_MD_T uint8_t
#	else
#		define VOXEL_MD_T uint8_t
#	endif
#endif

#if !defined(VOXEL_SECTOR_STATE_T)
#	if defined(VOXEL_SECTOR_STATE_64)
#		define VOXEL_SECTOR_STATE_T uint64_t
#	elif defined(VOXEL_SECTOR_STATE_32)
#		define VOXEL_SECTOR_STATE_T uint32_t
#	elif defined(VOXEL_SECTOR_STATE_16)
#		define VOXEL_SECTOR_STATE_T uint16_t
#	elif defined(VOXEL_SECTOR_STATE_8)
#		define VOXEL_SECTOR_STATE_T uint8_t
	elif defined(VOXEL_SECTOR_STATE_ENUM)
#		define VOXEL_SECTOR_STATE_T SectorState
#	else
#		define VOXEL_SECTOR_STATE_T SectorState
#	endif
#endif

#if !defined(VOXEL_MESH_VERTEX_T)
#	if defined(VOXEL_MESH_VERTEX_DOUBLE)
#		define VOXEL_MESH_VERTEX_T double
#	elif defined(VOXEL_MESH_VERTEX_FLOAT)
#		define VOXEL_MESH_VERTEX_T float
#	else
#		define VOXEL_MESH_VERTEX_T float
#	endif
#endif

#if !defined(VOXEL_MESH_NORMAL_T)
#	if defined(VOXEL_MESH_NORMAL_DOUBLE)
#		define VOXEL_MESH_NORMAL_T double
#	elif defined(VOXEL_MESH_NORMAL_FLOAT)
#		define VOXEL_MESH_NORMAL_T float
#	else
#		define VOXEL_MESH_NORMAL_T float
#	endif
#endif

#if !defined(VOXEL_MESH_INDEX_T)
#	if defined(VOXEL_MESH_INDEX_32)
#		define VOXEL_MESH_INDEX_T uint32_t
#	elif defined(VOXEL_MESH_INDEX_16)
#		define VOXEL_MESH_INDEX_T uint16_t
#	elif defined(VOXEL_MESH_INDEX_8)
#		define VOXEL_MESH_INDEX_T uint8_t
#	else
#		define VOXEL_MESH_INDEX_T uint8_t
#	endif
#endif

#if !defined(VOXEL_TIME_T)
#	if defined(VOXEL_TIME_DOUBLE)
#		define VOXEL_TIME_T double
#	elif defined(VOXEL_TIME_FLOAT)
#		define VOXEL_TIME_T float
#	else
#		define VOXEL_TIME_T float
#	endif
#endif

#define VOXEL_ID_NULL (VOXEL_ID_T)0
#define VOXEL_ID_UNKNOWN (VOXEL_ID_T)1

#define VOXEL_MD_NULL (VOXEL_MD_T)0

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
}
