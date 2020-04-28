#pragma once
#include <vxl/defines.hpp>
#include <vxl/voxel.hpp>
#include <vxl/sector.hpp>

namespace vxl
{
	struct SectorMesh
	{
		std::vector<float> vertices;
		std::vector<uint32_t> indices;

		SectorMesh() :
			vertices(),
			indices()
		{}
	};

	template<class V, class M>
	struct SectorGroup
	{
		using Sector = Sector<V, M>;

		const Sector& center;
		const Sector& left;
		const Sector& right;
		const Sector& down;
		const Sector& up;
		const Sector& back;
		const Sector& forward;

		SectorGroup(const Sector& _center, const Sector& _left, const Sector& _right, const Sector& _down, const Sector& _up, const Sector& _back, const Sector& _forward) :
			center(_center),
			left(_left),
			right(_right),
			down(_down),
			up(_up),
			back(_back),
			forward(_forward)
		{}
	};

	template<class V, class M>
	struct VoxelRenderInfo
	{
		using SectorGroup = SectorGroup<V, M>;
		using VoxelInfoArray = VoxelInfoArray<V, VoxelRenderInfo<V, M>>;
		using RenderPFN = void (*)(const VoxelInfoArray&, const SectorGroup&, SectorMesh&, const size_t, const size_t, const size_t);

		V voxel;
		RenderPFN render;

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
		static void renderBlock(const VoxelInfoArray& voxelInfos, const SectorGroup& sectors, SectorMesh& mesh, const size_t x, const size_t y, const size_t z)
		{
			const auto safeSizeX = sectors.center.sizeX() - 1;
			const auto safeSizeY = sectors.center.sizeY() - 1;
			const auto safeSizeZ = sectors.center.sizeZ() - 1;
			auto vertexIndex = mesh.vertices.size() / 3;

			if (x == 0)
			{
				auto otherVoxel = sectors.left.voxelAtUnsafe(safeSizeX, y, z);
				auto otherVoxelInfo = voxelInfos.at(otherVoxel);
				if (otherVoxelInfo.render)
					renderBlockSide(mesh, x, y, z, vertexIndex, verticesBlockLeft);
				otherVoxel = sectors.center.voxelAtUnsafe(x + 1, y, z);
				otherVoxelInfo = voxelInfos.at(otherVoxel);
				if (otherVoxelInfo.render)
					renderBlockSide(mesh, x, y, z, vertexIndex, verticesBlockRight);
			}
			else if (x == safeSizeX)
			{
				auto otherVoxel = sectors.center.voxelAtUnsafe(x - 1, y, z);
				auto otherVoxelInfo = voxelInfos.at(otherVoxel);
				if (otherVoxelInfo.render)
					renderBlockSide(mesh, x, y, z, vertexIndex, verticesBlockLeft);
				otherVoxel = sectors.right.voxelAtUnsafe(0, y, z);
				otherVoxelInfo = voxelInfos.at(otherVoxel);
				if (otherVoxelInfo.render)
					renderBlockSide(mesh, x, y, z, vertexIndex, verticesBlockRight);
			}
			else
			{
				auto otherVoxel = sectors.center.voxelAtUnsafe(x - 1, y, z);
				auto otherVoxelInfo = voxelInfos.at(otherVoxel);
				if (otherVoxelInfo.render)
					renderBlockSide(mesh, x, y, z, vertexIndex, verticesBlockLeft);
				otherVoxel = sectors.center.voxelAtUnsafe(x + 1, y, z);
				otherVoxelInfo = voxelInfos.at(otherVoxel);
				if (otherVoxelInfo.render)
					renderBlockSide(mesh, x, y, z, vertexIndex, verticesBlockRight);
			}

			if (y == 0)
			{
				auto otherVoxel = sectors.down.voxelAtUnsafe(x, safeSizeY, z);
				auto otherVoxelInfo = voxelInfos.at(otherVoxel);
				if (otherVoxelInfo.render)
					renderBlockSide(mesh, x, y, z, vertexIndex, verticesBlockDown);
				otherVoxel = sectors.center.voxelAtUnsafe(x, y + 1, z);
				otherVoxelInfo = voxelInfos.at(otherVoxel);
				if (otherVoxelInfo.render)
					renderBlockSide(mesh, x, y, z, vertexIndex, verticesBlockUp);
			}
			else if (y == safeSizeX)
			{
				auto otherVoxel = sectors.center.voxelAtUnsafe(x, y - 1, z);
				auto otherVoxelInfo = voxelInfos.at(otherVoxel);
				if (otherVoxelInfo.render)
					renderBlockSide(mesh, x, y, z, vertexIndex, verticesBlockDown);
				otherVoxel = sectors.up.voxelAtUnsafe(x, 0, z);
				otherVoxelInfo = voxelInfos.at(otherVoxel);
				if (otherVoxelInfo.render)
					renderBlockSide(mesh, x, y, z, vertexIndex, verticesBlockUp);
			}
			else
			{
				auto otherVoxel = sectors.center.voxelAtUnsafe(x, y - 1, z);
				auto otherVoxelInfo = voxelInfos.at(otherVoxel);
				if (otherVoxelInfo.render)
					renderBlockSide(mesh, x, y, z, vertexIndex, verticesBlockDown);
				otherVoxel = sectors.center.voxelAtUnsafe(x, y + 1, z);
				otherVoxelInfo = voxelInfos.at(otherVoxel);
				if (otherVoxelInfo.render)
					renderBlockSide(mesh, x, y, z, vertexIndex, verticesBlockUp);
			}

			if (z == 0)
			{
				auto otherVoxel = sectors.back.voxelAtUnsafe(x, y, safeSizeZ);
				auto otherVoxelInfo = voxelInfos.at(otherVoxel);
				if (otherVoxelInfo.render)
					renderBlockSide(mesh, x, y, z, vertexIndex, verticesBlockBack);
				otherVoxel = sectors.center.voxelAtUnsafe(x, y, z + 1);
				otherVoxelInfo = voxelInfos.at(otherVoxel);
				if (otherVoxelInfo.render)
					renderBlockSide(mesh, x, y, z, vertexIndex, verticesBlockForward);
			}
			else if (z == safeSizeX)
			{
				auto otherVoxel = sectors.center.voxelAtUnsafe(x, y, z - 1);
				auto otherVoxelInfo = voxelInfos.at(otherVoxel);
				if (otherVoxelInfo.render)
					renderBlockSide(mesh, x, y, z, vertexIndex, verticesBlockBack);
				otherVoxel = sectors.forward.voxelAtUnsafe(x, y, 0);
				otherVoxelInfo = voxelInfos.at(otherVoxel);
				if (otherVoxelInfo.render)
					renderBlockSide(mesh, x, y, z, vertexIndex, verticesBlockForward);
			}
			else
			{
				auto otherVoxel = sectors.center.voxelAtUnsafe(x, y, z - 1);
				auto otherVoxelInfo = voxelInfos.at(otherVoxel);
				if (otherVoxelInfo.render)
					renderBlockSide(mesh, x, y, z, vertexIndex, verticesBlockBack);
				otherVoxel = sectors.center.voxelAtUnsafe(x, y, z + 1);
				otherVoxelInfo = voxelInfos.at(otherVoxel);
				if (otherVoxelInfo.render)
					renderBlockSide(mesh, x, y, z, vertexIndex, verticesBlockForward);
			}
		}

		VoxelRenderInfo(const V _voxel, RenderPFN _render = nullptr) :
			voxel(_voxel),
			render(_render)
		{}
	};

	class Renderer
	{
	public:
		template<class V, class M>
		static void generate(const VoxelInfoArray<V, VoxelRenderInfo<V, M>>& voxelInfos, const SectorGroup<V, M>& sectors, SectorMesh& mesh)
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
						const auto voxel = sectors.center.voxelAtUnsafe(x, y, z);
						const auto voxelInfo = voxelInfos.at(voxel);

						if (voxelInfo.render)
							voxelInfo.render(voxelInfos, sectors, mesh, x, y, z);
					}
				}
			}
		}
	};
}
