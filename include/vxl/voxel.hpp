#pragma once
#include <vector>

namespace vxl
{
	template<class TID, class TMD>
	struct Voxel;
	template<class TID, class TMD>
	class VoxelArray;

	template<class TID, class TMD>
	struct SectorGroup;
	struct SectorMesh;

	template<class TID, class TMD>
	struct Voxel
	{
		using UpdatePFN = void (*)(const VoxelArray<TID, TMD>&, SectorGroup<TID, TMD>&, const double&, const size_t&);
		using RenderPFN = void (*)(const VoxelArray<TID, TMD>&, const SectorGroup<TID, TMD>&, SectorMesh&, const size_t, const size_t, const size_t);

		TID id;
		bool passable;
		UpdatePFN update;
		RenderPFN render;

		Voxel(const TID _id, const bool _passable = false, const UpdatePFN _update = nullptr, const RenderPFN _render = nullptr) :
			id(_id),
			passable(_passable),
			update(_update),
			render(_render)
		{}
		virtual ~Voxel() 
		{}

		inline static const std::vector<float> verticesBlockLeft
		{
			0.0f, 0.0f, 1.0f,  0.0f, 1.0f, 1.0f,  0.0f, 1.0f, 0.0f,  0.0f, 0.0f, 0.0f,
		};
		inline static const std::vector<float> verticesBlockRight
		{
			1.0f, 0.0f, 0.0f,  1.0f, 1.0f, 0.0f,  1.0f, 1.0f, 1.0f,  0.0f, 1.0f, 1.0f,
		};
		inline static const std::vector<float> verticesBlockDown
		{
			0.0f, 0.0f, 1.0f,  0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,  1.0f, 0.0f, 1.0f,
		};
		inline static const std::vector<float> verticesBlockUp
		{
			0.0f, 1.0f, 0.0f,  0.0f, 1.0f, 1.0f,  1.0f, 1.0f, 1.0f,  1.0f, 1.0f, 0.0f,
		};
		inline static const std::vector<float> verticesBlockBack
		{
			0.0f, 0.0f, 0.0f,  0.0f, 1.0f, 0.0f,  1.0f, 1.0f, 0.0f,  0.0f, 1.0f, 0.0f,
		};
		inline static const std::vector<float> verticesBlockForward
		{
			1.0f, 1.0f, 0.0f,  1.0f, 1.0f, 1.0f,  0.0f, 1.0f, 1.0f,  0.0f, 0.0f, 1.0f,
		};
		inline static void renderBlockSide(SectorMesh& mesh, const size_t x, const size_t y, const size_t z, size_t& vertexIndex, const std::vector<float>& blockVertices)
		{
			const float_t vertices[] { blockVertices[0] + x, blockVertices[1] + y, blockVertices[2] + z, blockVertices[3] + x, blockVertices[4] + y, blockVertices[5] + z, blockVertices[6] + x, blockVertices[7] + y, blockVertices[8] + z, blockVertices[9] + x, blockVertices[10] + y, blockVertices[11] + z, };
			mesh.vertices.insert(mesh.vertices.end(), std::begin(vertices), std::end(vertices));
			const uint32_t indices[] { vertexIndex, vertexIndex + 1, vertexIndex + 2, vertexIndex, vertexIndex + 2, vertexIndex + 3, };
			mesh.indices.insert(mesh.indices.end(), std::begin(indices), std::end(indices));
			vertexIndex += 4;
		}
		static void renderBlock(const VoxelArray<TID, TMD>& voxels, const  SectorGroup<TID, TMD>& sectors, SectorMesh& mesh, const size_t x, const size_t y, const size_t z)
		{
			const auto safeSizeX = sectors.center.sizeX() - 1;
			const auto safeSizeY = sectors.center.sizeY() - 1;
			const auto safeSizeZ = sectors.center.sizeZ() - 1;
			auto vertexIndex = mesh.vertices.size() / 3;

			if (x == 0)
			{
				if (!voxels.at(sectors.left.idAtUnsafe(safeSizeX, y, z)).render)
					renderBlockSide(mesh, x, y, z, vertexIndex, verticesBlockLeft);
				if (!voxels.at(sectors.center.idAtUnsafe(x + 1, y, z)).render)
					renderBlockSide(mesh, x, y, z, vertexIndex, verticesBlockRight);
			}
			else if (x == safeSizeX)
			{
				if (!voxels.at(sectors.center.idAtUnsafe(x - 1, y, z)).render)
					renderBlockSide(mesh, x, y, z, vertexIndex, verticesBlockLeft);
				if (!voxels.at(sectors.right.idAtUnsafe(0, y, z)).render)
					renderBlockSide(mesh, x, y, z, vertexIndex, verticesBlockRight);
			}
			else
			{
				if (!voxels.at(sectors.center.idAtUnsafe(x - 1, y, z)).render)
					renderBlockSide(mesh, x, y, z, vertexIndex, verticesBlockLeft);
				if (!voxels.at(sectors.center.idAtUnsafe(x + 1, y, z)).render)
					renderBlockSide(mesh, x, y, z, vertexIndex, verticesBlockRight);
			}

			if (y == 0)
			{
				if (!voxels.at(sectors.down.idAtUnsafe(x, safeSizeY, z)).render)
					renderBlockSide(mesh, x, y, z, vertexIndex, verticesBlockDown);
				if (!voxels.at(sectors.center.idAtUnsafe(x, y + 1, z)).render)
					renderBlockSide(mesh, x, y, z, vertexIndex, verticesBlockUp);
			}
			else if (y == safeSizeX)
			{
				if (!voxels.at(sectors.center.idAtUnsafe(x, y - 1, z)).render)
					renderBlockSide(mesh, x, y, z, vertexIndex, verticesBlockDown);
				if (!voxels.at(sectors.up.idAtUnsafe(x, 0, z)).render)
					renderBlockSide(mesh, x, y, z, vertexIndex, verticesBlockUp);
			}
			else
			{
				if (!voxels.at(sectors.center.idAtUnsafe(x, y - 1, z)).render)
					renderBlockSide(mesh, x, y, z, vertexIndex, verticesBlockDown);
				if (!voxels.at(sectors.center.idAtUnsafe(x, y + 1, z)).render)
					renderBlockSide(mesh, x, y, z, vertexIndex, verticesBlockUp);
			}

			if (z == 0)
			{
				if (!voxels.at(sectors.back.idAtUnsafe(x, y, safeSizeZ)).render)
					renderBlockSide(mesh, x, y, z, vertexIndex, verticesBlockBack);
				if (!voxels.at(sectors.center.idAtUnsafe(x, y, z + 1)).render)
					renderBlockSide(mesh, x, y, z, vertexIndex, verticesBlockForward);
			}
			else if (z == safeSizeX)
			{
				if (!voxels.at(sectors.center.idAtUnsafe(x, y, z - 1)).render)
					renderBlockSide(mesh, x, y, z, vertexIndex, verticesBlockBack);
				if (!voxels.at(sectors.forward.idAtUnsafe(x, y, 0)).render)
					renderBlockSide(mesh, x, y, z, vertexIndex, verticesBlockForward);
			}
			else
			{
				if (!voxels.at(sectors.center.idAtUnsafe(x, y, z - 1)).render)
					renderBlockSide(mesh, x, y, z, vertexIndex, verticesBlockBack);
				if (!voxels.at(sectors.center.idAtUnsafe(x, y, z + 1)).render)
					renderBlockSide(mesh, x, y, z, vertexIndex, verticesBlockForward);
			}
		}
	};

	template<class TID, class TMD>
	class VoxelArray
	{
	protected:
		TID m_unknown;
		std::vector<Voxel<TID, TMD>> m_voxels;
	public:
		VoxelArray(const TID unknown, const std::vector<Voxel<TID, TMD>>& voxels) :
			m_unknown(unknown),
			m_voxels(voxels)
		{}

		inline const TID& unknown() const noexcept
		{
			return m_unknown;
		}
		
		inline Voxel<TID, TMD>& at(TID id) noexcept
		{
			if (static_cast<size_t>(id) < m_voxels.size())
				return m_voxels[static_cast<size_t>(id)];
			else
				return m_voxels[static_cast<size_t>(m_unknown)];
		}
		inline const Voxel<TID, TMD>& at(TID id) const noexcept
		{
			if (static_cast<size_t>(id) < m_voxels.size())
				return m_voxels[static_cast<size_t>(id)];
			else
				return m_voxels[static_cast<size_t>(m_unknown)];
		}
		template<class TV = Voxel<TID, TMD>>
		inline TV& at(TID id) noexcept
		{
			if (static_cast<size_t>(id) < m_voxels.size())
				return static_cast<TV&>(m_voxels[static_cast<size_t>(id)]);
			else
				return static_cast<TV&>(m_voxels[static_cast<size_t>(m_unknown)]);
		}
		template<class TV = Voxel<TID, TMD>>
		inline const TV& at(TID id) const noexcept
		{
			if (static_cast<size_t>(id) < m_voxels.size())
				return static_cast<TV&>(m_voxels[static_cast<size_t>(id)]);
			else
				return static_cast<TV&>(m_voxels[static_cast<size_t>(m_unknown)]);
		}
	};
}
