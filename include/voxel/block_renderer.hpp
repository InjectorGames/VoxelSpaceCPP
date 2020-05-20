#pragma once
#include <voxel/renderer.hpp>

namespace voxel
{
	class BlockRenderer : public Renderer
	{
	protected:
		inline static const std::vector<VOXEL_MESH_VERTEX_T> leftBlockVertices
		{
			0.0f, 0.0f, 1.0f,
			0.0f, 1.0f, 1.0f,
			0.0f, 1.0f, 0.0f,
			0.0f, 0.0f, 0.0f,
		};
		inline static const std::vector<VOXEL_MESH_VERTEX_T> rightBlockVertices
		{
			1.0f, 0.0f, 0.0f,
			1.0f, 1.0f, 0.0f,
			1.0f, 1.0f, 1.0f,
			0.0f, 1.0f, 0.0f,
		};
		inline static const std::vector<VOXEL_MESH_VERTEX_T> downBlockVertices
		{
			0.0f, 0.0f, 1.0f,
			0.0f, 0.0f, 0.0f,
			1.0f, 0.0f, 0.0f,
			1.0f, 0.0f, 1.0f,
		};
		inline static const std::vector<VOXEL_MESH_VERTEX_T> upBlockVertices
		{
			0.0f, 1.0f, 0.0f,
			0.0f, 1.0f, 1.0f,
			1.0f, 1.0f, 1.0f,
			1.0f, 1.0f, 0.0f,
		};
		inline static const std::vector<VOXEL_MESH_VERTEX_T> backBlockVertices
		{
			0.0f, 0.0f, 0.0f,
			0.0f, 1.0f, 0.0f,
			1.0f, 1.0f, 0.0f,
			0.0f, 1.0f, 0.0f,
		};
		inline static const std::vector<VOXEL_MESH_VERTEX_T> forwardBlockVertices
		{
			1.0f, 1.0f, 0.0f,
			1.0f, 1.0f, 1.0f,
			0.0f, 1.0f, 1.0f,
			0.0f, 0.0f, 1.0f,
		};

		// TODO: make method for each side

		inline static void renderBlockSide(Mesh& mesh, size_t& vertexIndex,
			const size_t x, const size_t y, const size_t z,
			const std::vector<VOXEL_MESH_VERTEX_T>& blockVertices)
		{
			const VOXEL_MESH_VERTEX_T vertices[]
			{
				x + blockVertices[0], y + blockVertices[1], z + blockVertices[2],
				x + blockVertices[3], y + blockVertices[4], z + blockVertices[5],
				x + blockVertices[6], y + blockVertices[7], z + blockVertices[8],
				x + blockVertices[9], y + blockVertices[10], z + blockVertices[11],
			};
			mesh.vertices.insert(mesh.vertices.end(), std::begin(vertices), std::end(vertices));

			const VOXEL_MESH_INDEX_T indices[]
			{
				vertexIndex, vertexIndex + 1, vertexIndex + 2, vertexIndex, vertexIndex + 2, vertexIndex + 3,
			};
			mesh.indices.insert(mesh.indices.end(), std::begin(indices), std::end(indices));

			vertexIndex += 4;
		}
	public:
		void generate(Mesh& mesh,
			const Register& _register, const Cluster& cluster,
			const size_t x, const size_t y, const size_t z) override
		{
			auto vertexIndex = mesh.vertices.size() / 3;

			// TODO: check if renderer is BlockRederer type

			if (x == VOXEL_DIRECTION_ZERO)
			{
				if (!_register.get(cluster.left.getID(VOXEL_SECTOR_SAFE_LENGTH, y, z)).renderer)
					renderBlockSide(mesh, vertexIndex, x, y, z, leftBlockVertices);
				if (!_register.get(cluster.center.getID(x + VOXEL_DIRECTION_RIGHT, y, z)).renderer)
					renderBlockSide(mesh, vertexIndex, x, y, z, rightBlockVertices);
			}
			else if (x == VOXEL_SECTOR_SAFE_LENGTH)
			{
				if (!_register.get(cluster.center.getID(x + VOXEL_DIRECTION_LEFT, y, z)).renderer)
					renderBlockSide(mesh, vertexIndex, x, y, z, leftBlockVertices);
				if (!_register.get(cluster.right.getID(VOXEL_DIRECTION_ZERO, y, z)).renderer)
					renderBlockSide(mesh, vertexIndex, x, y, z, rightBlockVertices);
			}
			else
			{
				if (!_register.get(cluster.center.getID(x + VOXEL_DIRECTION_LEFT, y, z)).renderer)
					renderBlockSide(mesh, vertexIndex, x, y, z, leftBlockVertices);
				if (!_register.get(cluster.center.getID(x + VOXEL_DIRECTION_RIGHT, y, z)).renderer)
					renderBlockSide(mesh, vertexIndex, x, y, z, rightBlockVertices);
			}

			if (y == VOXEL_DIRECTION_ZERO)
			{
				if (!_register.get(cluster.down.getID(x, VOXEL_SECTOR_SAFE_LENGTH, z)).renderer)
					renderBlockSide(mesh, vertexIndex, x, y, z, downBlockVertices);
				if (!_register.get(cluster.center.getID(x, y + VOXEL_DIRECTION_UP, z)).renderer)
					renderBlockSide(mesh, vertexIndex, x, y, z, upBlockVertices);
			}
			else if (y == VOXEL_SECTOR_SAFE_LENGTH)
			{
				if (!_register.get(cluster.center.getID(x, y + VOXEL_DIRECTION_DOWN, z)).renderer)
					renderBlockSide(mesh, vertexIndex, x, y, z, downBlockVertices);
				if (!_register.get(cluster.up.getID(x, VOXEL_DIRECTION_ZERO, z)).renderer)
					renderBlockSide(mesh, vertexIndex, x, y, z, upBlockVertices);
			}
			else
			{
				if (!_register.get(cluster.center.getID(x, y + VOXEL_DIRECTION_DOWN, z)).renderer)
					renderBlockSide(mesh, vertexIndex, x, y, z, downBlockVertices);
				if (!_register.get(cluster.center.getID(x, y + VOXEL_DIRECTION_UP, z)).renderer)
					renderBlockSide(mesh, vertexIndex, x, y, z, upBlockVertices);
			}

			if (z == VOXEL_DIRECTION_ZERO)
			{
				if (!_register.get(cluster.back.getID(x, y, VOXEL_SECTOR_SAFE_LENGTH)).renderer)
					renderBlockSide(mesh, vertexIndex, x, y, z, backBlockVertices);
				if (!_register.get(cluster.center.getID(x, y, z + VOXEL_DIRECTION_FORWARD)).renderer)
					renderBlockSide(mesh, vertexIndex, x, y, z, forwardBlockVertices);
			}
			else if (z == VOXEL_SECTOR_SAFE_LENGTH)
			{
				if (!_register.get(cluster.center.getID(x, y, z + VOXEL_DIRECTION_BACK)).renderer)
					renderBlockSide(mesh, vertexIndex, x, y, z, backBlockVertices);
				if (!_register.get(cluster.forward.getID(x, y, VOXEL_DIRECTION_ZERO)).renderer)
					renderBlockSide(mesh, vertexIndex, x, y, z, forwardBlockVertices);
			}
			else
			{
				if (!_register.get(cluster.center.getID(x, y, z + VOXEL_DIRECTION_BACK)).renderer)
					renderBlockSide(mesh, vertexIndex, x, y, z, backBlockVertices);
				if (!_register.get(cluster.center.getID(x, y, z + VOXEL_DIRECTION_FORWARD)).renderer)
					renderBlockSide(mesh, vertexIndex, x, y, z, forwardBlockVertices);
			}
		}
	};
}
