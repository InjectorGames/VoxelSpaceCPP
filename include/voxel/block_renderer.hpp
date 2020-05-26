#pragma once
#include <voxel/renderer.hpp>

namespace VOXEL_NAMESPACE
{
	class BlockRenderer : public Renderer
	{
	protected:
		inline static const std::vector<mesh_vert_t> leftBlockVertices
		{
			0.0f, 0.0f, 1.0f,
			0.0f, 1.0f, 1.0f,
			0.0f, 1.0f, 0.0f,
			0.0f, 0.0f, 0.0f,
		};
		inline static const std::vector<mesh_vert_t> rightBlockVertices
		{
			1.0f, 0.0f, 0.0f,
			1.0f, 1.0f, 0.0f,
			1.0f, 1.0f, 1.0f,
			0.0f, 1.0f, 0.0f,
		};
		inline static const std::vector<mesh_vert_t> downBlockVertices
		{
			0.0f, 0.0f, 1.0f,
			0.0f, 0.0f, 0.0f,
			1.0f, 0.0f, 0.0f,
			1.0f, 0.0f, 1.0f,
		};
		inline static const std::vector<mesh_vert_t> upBlockVertices
		{
			0.0f, 1.0f, 0.0f,
			0.0f, 1.0f, 1.0f,
			1.0f, 1.0f, 1.0f,
			1.0f, 1.0f, 0.0f,
		};
		inline static const std::vector<mesh_vert_t> backBlockVertices
		{
			0.0f, 0.0f, 0.0f,
			0.0f, 1.0f, 0.0f,
			1.0f, 1.0f, 0.0f,
			0.0f, 1.0f, 0.0f,
		};
		inline static const std::vector<mesh_vert_t> forwardBlockVertices
		{
			1.0f, 1.0f, 0.0f,
			1.0f, 1.0f, 1.0f,
			0.0f, 1.0f, 1.0f,
			0.0f, 0.0f, 1.0f,
		};

		// TODO: make method for each side

		inline static void renderBlockSide(Mesh& mesh, size_t& vertexIndex,
			const size_t x, const size_t y, const size_t z,
			const std::vector<mesh_vert_t>& blockVertices)
		{
			const mesh_vert_t vertices[]
			{
				x + blockVertices[0], y + blockVertices[1], z + blockVertices[2],
				x + blockVertices[3], y + blockVertices[4], z + blockVertices[5],
				x + blockVertices[6], y + blockVertices[7], z + blockVertices[8],
				x + blockVertices[9], y + blockVertices[10], z + blockVertices[11],
			};
			mesh.vertices.insert(mesh.vertices.end(), std::begin(vertices), std::end(vertices));

			const mesh_ind_t indices[]
			{
				vertexIndex, vertexIndex + 1, vertexIndex + 2, vertexIndex, vertexIndex + 2, vertexIndex + 3,
			};
			mesh.indices.insert(mesh.indices.end(), std::begin(indices), std::end(indices));

			vertexIndex += 4;
		}
	public:
		void generate(const Registry& registry, const Cluster& cluster,
			const Vec3<size_t>& position, Mesh& mesh) override
		{
			auto vertexIndex = mesh.vertices.size() / 3;

			// TODO: check if renderer is BlockRederer type

			if (position.x == 0)
			{
				if (!registry.get(cluster.left.getIDS().get(sectorSafeLength, position.y, position.z)).renderer)
					renderBlockSide(mesh, vertexIndex, position.x, position.y, position.z, leftBlockVertices);
				if (!registry.get(cluster.center.getIDS().get(position.x + rightDir, position.y, position.z)).renderer)
					renderBlockSide(mesh, vertexIndex, position.x, position.y, position.z, rightBlockVertices);
			}
			else if (position.x == sectorSafeLength)
			{
				if (!registry.get(cluster.center.getIDS().get(position.x + leftDir, position.y, position.z)).renderer)
					renderBlockSide(mesh, vertexIndex, position.x, position.y, position.z, leftBlockVertices);
				if (!registry.get(cluster.right.getIDS().get(zeroDir, position.y, position.z)).renderer)
					renderBlockSide(mesh, vertexIndex, position.x, position.y, position.z, rightBlockVertices);
			}
			else
			{
				if (!registry.get(cluster.center.getIDS().get(position.x + leftDir, position.y, position.z)).renderer)
					renderBlockSide(mesh, vertexIndex, position.x, position.y, position.z, leftBlockVertices);
				if (!registry.get(cluster.center.getIDS().get(position.x + rightDir, position.y, position.z)).renderer)
					renderBlockSide(mesh, vertexIndex, position.x, position.y, position.z, rightBlockVertices);
			}

			if (position.y == 0)
			{
				if (!registry.get(cluster.down.getIDS().get(position.x, sectorSafeLength, position.z)).renderer)
					renderBlockSide(mesh, vertexIndex, position.x, position.y, position.z, downBlockVertices);
				if (!registry.get(cluster.center.getIDS().get(position.x, position.y + upDir, position.z)).renderer)
					renderBlockSide(mesh, vertexIndex, position.x, position.y, position.z, upBlockVertices);
			}
			else if (position.y == sectorSafeLength)
			{
				if (!registry.get(cluster.center.getIDS().get(position.x, position.y + downDir, position.z)).renderer)
					renderBlockSide(mesh, vertexIndex, position.x, position.y, position.z, downBlockVertices);
				if (!registry.get(cluster.up.getIDS().get(position.x, zeroDir, position.z)).renderer)
					renderBlockSide(mesh, vertexIndex, position.x, position.y, position.z, upBlockVertices);
			}
			else
			{
				if (!registry.get(cluster.center.getIDS().get(position.x, position.y + downDir, position.z)).renderer)
					renderBlockSide(mesh, vertexIndex, position.x, position.y, position.z, downBlockVertices);
				if (!registry.get(cluster.center.getIDS().get(position.x, position.y + upDir, position.z)).renderer)
					renderBlockSide(mesh, vertexIndex, position.x, position.y, position.z, upBlockVertices);
			}

			if (position.z == 0)
			{
				if (!registry.get(cluster.back.getIDS().get(position.x, position.y, sectorSafeLength)).renderer)
					renderBlockSide(mesh, vertexIndex, position.x, position.y, position.z, backBlockVertices);
				if (!registry.get(cluster.center.getIDS().get(position.x, position.y, position.z + forwardDir)).renderer)
					renderBlockSide(mesh, vertexIndex, position.x, position.y, position.z, forwardBlockVertices);
			}
			else if (position.z == sectorSafeLength)
			{
				if (!registry.get(cluster.center.getIDS().get(position.x, position.y, position.z + backDir)).renderer)
					renderBlockSide(mesh, vertexIndex, position.x, position.y, position.z, backBlockVertices);
				if (!registry.get(cluster.forward.getIDS().get(position.x, position.y, zeroDir)).renderer)
					renderBlockSide(mesh, vertexIndex, position.x, position.y, position.z, forwardBlockVertices);
			}
			else
			{
				if (!registry.get(cluster.center.getIDS().get(position.x, position.y, position.z + backDir)).renderer)
					renderBlockSide(mesh, vertexIndex, position.x, position.y, position.z, backBlockVertices);
				if (!registry.get(cluster.center.getIDS().get(position.x, position.y, position.z + forwardDir)).renderer)
					renderBlockSide(mesh, vertexIndex, position.x, position.y, position.z, forwardBlockVertices);
			}
		}
	};
}
