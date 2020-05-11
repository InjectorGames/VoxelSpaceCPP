#pragma once
#include <vxl/voxel.hpp>
#include <vxl/sector.hpp>

namespace vxl
{
	class Renderer
	{
	public:
		template<class TID, class TMD>
		static void generate(const VoxelArray<TID, TMD>& voxels,
			const SectorGroup<TID, TMD>& sectors, SectorMesh& mesh)
		{
			if (sectors.center.getSize() != sectors.left.getSize() ||
				sectors.center.getSize() != sectors.right.getSize() ||
				sectors.center.getSize() != sectors.down.getSize() ||
				sectors.center.getSize() != sectors.up.getSize() ||
				sectors.center.getSize() != sectors.back.getSize() ||
				sectors.center.getSize() != sectors.forward.getSize())
				throw std::runtime_error("Sector sizes are not equal");

			for (size_t z = 0; z < sectors.center.getSizeZ(); z++)
			{
				for (size_t y = 0; y < sectors.center.getSizeY(); y++)
				{
					for (size_t x = 0; x < sectors.center.getSizeX(); x++)
					{
						const auto& id = sectors.center.idAtUnsafe(x, y, z);
						const auto& voxel = voxels.get(id);

						if (voxel.render)
							voxel.render(voxels, sectors, mesh, x, y, z);
					}
				}
			}
		}
	};
}
