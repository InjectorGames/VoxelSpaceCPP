#pragma once
#include <vxl/voxel.hpp>
#include <vxl/sector.hpp>

namespace vxl
{
	class Renderer
	{
	public:
		template<class TID, class TMD>
		static void generate(const VoxelArray<TID, TMD>& voxels, const SectorGroup<TID, TMD>& sectors, SectorMesh& mesh)
		{
			if (sectors.center.size() != sectors.left.size() ||
				sectors.center.size() != sectors.right.size() ||
				sectors.center.size() != sectors.down.size() ||
				sectors.center.size() != sectors.up.size() ||
				sectors.center.size() != sectors.back.size() ||
				sectors.center.size() != sectors.forward.size())
				throw std::runtime_error("Sector sizes are not equal");

			for (size_t z = 0; z < sectors.center.sizeX(); z++)
			{
				for (size_t y = 0; y < sectors.center.sizeY(); y++)
				{
					for (size_t x = 0; x < sectors.center.sizeZ(); x++)
					{
						const auto& voxel = voxels.at(sectors.center.idAtUnsafe(x, y, z));

						if (voxel.render)
							voxel.render(voxels, sectors, mesh, x, y, z);
					}
				}
			}
		}
	};
}
