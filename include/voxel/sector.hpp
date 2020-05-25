#pragma once
#include <voxel/array3.hpp>
#include <voxel/register.hpp>

namespace VOXEL_NAMESPACE
{
	class Cluster;

	class Sector
	{
	public:
		Array3<id_t> ids;
		Array3<md_t> mds;

		Sector(const id_t id = nullVoxelID,
			const md_t md = nullVoxelMD) :
			ids(Vec3<size_t>(sectorLength, sectorLength, sectorLength), id),
			mds(Vec3<size_t>(sectorLength, sectorLength, sectorLength), md)
		{}
		virtual ~Sector()
		{}

		virtual void update(const Register& _register,
			Cluster& cluster, const time_t deltaTime)
		{
			for (size_t i = 0; i < sectorSize; i++)
			{
				const auto id = ids.get(i);
				const auto& voxel = _register.get(id);

				if (voxel.updater)
					voxel.updater->update(_register, deltaTime, i, cluster);
			}
		}
	};
}
