#pragma once
#include <voxel/array3.hpp>
#include <voxel/registry.hpp>

namespace VOXEL_NAMESPACE
{
	struct Cluster;

	class Sector
	{
	protected:
		Array3<id_t> ids;
		Array3<md_t> mds;
	public:
		Sector(const size3_t size = size3_t(
			sectorLength, sectorLength, sectorLength),
			const id_t id = nullVoxelID,
			const md_t md = nullVoxelMD) :
			ids(size, id),
			mds(size, md)
		{}
		virtual ~Sector()
		{}

		inline Array3<id_t>& getIDS() noexcept
		{
			return ids;
		}
		inline const Array3<id_t>& getIDS() const noexcept
		{
			return ids;
		}

		inline Array3<md_t>& getMDS() noexcept
		{
			return mds;
		}
		inline const Array3<md_t>& getMDS() const noexcept
		{
			return mds;
		}

		virtual void update(const Registry& registry,
			Cluster& cluster, const time_t deltaTime)
		{
			for (size_t i = 0; i < sectorSize; i++)
			{
				const auto id = ids.get(i);
				const auto& voxel = registry.get(id);

				if (voxel.updater)
					voxel.updater->update(registry, deltaTime, i, cluster);
			}
		}
	};
}
