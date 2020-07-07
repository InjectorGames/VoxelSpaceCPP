#pragma once
#include <voxel/renderer.hpp>

namespace VOXEL_NAMESPACE
{
	class BlockRenderer : public Renderer
	{
	protected:
		inline static void renderLeft(
			const Vec3<size_t>& position,
			const size_t vertexIndex,
			Mesh& mesh)
		{
			const mesh_vert_t vertices[]
			{
				static_cast<mesh_vert_t>(position.x),
				static_cast<mesh_vert_t>(position.y),
				static_cast<mesh_vert_t>(position.z + 1),

				static_cast<mesh_vert_t>(position.x),
				static_cast<mesh_vert_t>(position.y + 1),
				static_cast<mesh_vert_t>(position.z + 1),

				static_cast<mesh_vert_t>(position.x),
				static_cast<mesh_vert_t>(position.y + 1),
				static_cast<mesh_vert_t>(position.z),

				static_cast<mesh_vert_t>(position.x),
				static_cast<mesh_vert_t>(position.y),
				static_cast<mesh_vert_t>(position.z),
			};
			mesh.vertices.insert(mesh.vertices.end(), std::begin(vertices), std::end(vertices));

#if defined(VOXEL_USE_MESH_NORM)
			static const mesh_vert_t normals[]
			{
				static_cast<mesh_vert_t>(leftDir),
				static_cast<mesh_vert_t>(0),
				static_cast<mesh_vert_t>(0),

				static_cast<mesh_vert_t>(leftDir),
				static_cast<mesh_vert_t>(0),
				static_cast<mesh_vert_t>(0),

				static_cast<mesh_vert_t>(leftDir),
				static_cast<mesh_vert_t>(0),
				static_cast<mesh_vert_t>(0),

				static_cast<mesh_vert_t>(leftDir),
				static_cast<mesh_vert_t>(0),
				static_cast<mesh_vert_t>(0),
			};
			mesh.vertices.insert(mesh.vertices.end(), std::begin(normals), std::end(normals));
#endif

			const mesh_ind_t indices[]
			{
				static_cast<mesh_ind_t>(vertexIndex),
				static_cast<mesh_ind_t>(vertexIndex + 1),
				static_cast<mesh_ind_t>(vertexIndex + 2),
				static_cast<mesh_ind_t>(vertexIndex),
				static_cast<mesh_ind_t>(vertexIndex + 2),
				static_cast<mesh_ind_t>(vertexIndex + 3),
			};
			mesh.indices.insert(mesh.indices.end(), std::begin(indices), std::end(indices));
		}
		inline static void renderRight(
			const Vec3<size_t>& position,
			const size_t vertexIndex,
			Mesh& mesh)
		{
			const mesh_vert_t vertices[]
			{
				static_cast<mesh_vert_t>(position.x + 1),
				static_cast<mesh_vert_t>(position.y),
				static_cast<mesh_vert_t>(position.z),

				static_cast<mesh_vert_t>(position.x + 1),
				static_cast<mesh_vert_t>(position.y + 1),
				static_cast<mesh_vert_t>(position.z),

				static_cast<mesh_vert_t>(position.x + 1),
				static_cast<mesh_vert_t>(position.y + 1),
				static_cast<mesh_vert_t>(position.z + 1),

				static_cast<mesh_vert_t>(position.x),
				static_cast<mesh_vert_t>(position.y + 1),
				static_cast<mesh_vert_t>(position.z),
			};
			mesh.vertices.insert(mesh.vertices.end(), std::begin(vertices), std::end(vertices));

#if defined(VOXEL_USE_MESH_NORM)
			static const mesh_vert_t normals[]
			{
				static_cast<mesh_vert_t>(rightDir),
				static_cast<mesh_vert_t>(0),
				static_cast<mesh_vert_t>(0),

				static_cast<mesh_vert_t>(rightDir),
				static_cast<mesh_vert_t>(0),
				static_cast<mesh_vert_t>(0),

				static_cast<mesh_vert_t>(rightDir),
				static_cast<mesh_vert_t>(0),
				static_cast<mesh_vert_t>(0),

				static_cast<mesh_vert_t>(rightDir),
				static_cast<mesh_vert_t>(0),
				static_cast<mesh_vert_t>(0),
			};
			mesh.vertices.insert(mesh.vertices.end(), std::begin(normals), std::end(normals));
#endif

			const mesh_ind_t indices[]
			{
				static_cast<mesh_ind_t>(vertexIndex),
				static_cast<mesh_ind_t>(vertexIndex + 1),
				static_cast<mesh_ind_t>(vertexIndex + 2),
				static_cast<mesh_ind_t>(vertexIndex),
				static_cast<mesh_ind_t>(vertexIndex + 2),
				static_cast<mesh_ind_t>(vertexIndex + 3),
			};
			mesh.indices.insert(mesh.indices.end(), std::begin(indices), std::end(indices));
		}
		inline static void renderDown(
			const Vec3<size_t>& position,
			const size_t vertexIndex,
			Mesh& mesh)
		{
			const mesh_vert_t vertices[]
			{
				static_cast<mesh_vert_t>(position.x),
				static_cast<mesh_vert_t>(position.y),
				static_cast<mesh_vert_t>(position.z + 1),

				static_cast<mesh_vert_t>(position.x),
				static_cast<mesh_vert_t>(position.y),
				static_cast<mesh_vert_t>(position.z),

				static_cast<mesh_vert_t>(position.x + 1),
				static_cast<mesh_vert_t>(position.y),
				static_cast<mesh_vert_t>(position.z),

				static_cast<mesh_vert_t>(position.x + 1),
				static_cast<mesh_vert_t>(position.y),
				static_cast<mesh_vert_t>(position.z + 1),
			};
			mesh.vertices.insert(mesh.vertices.end(), std::begin(vertices), std::end(vertices));

#if defined(VOXEL_USE_MESH_NORM)
			static const mesh_vert_t normals[]
			{
				static_cast<mesh_vert_t>(0),
				static_cast<mesh_vert_t>(downDir),
				static_cast<mesh_vert_t>(0),

				static_cast<mesh_vert_t>(0),
				static_cast<mesh_vert_t>(downDir),
				static_cast<mesh_vert_t>(0),

				static_cast<mesh_vert_t>(0),
				static_cast<mesh_vert_t>(downDir),
				static_cast<mesh_vert_t>(0),

				static_cast<mesh_vert_t>(0),
				static_cast<mesh_vert_t>(downDir),
				static_cast<mesh_vert_t>(0),
			};
			mesh.vertices.insert(mesh.vertices.end(), std::begin(normals), std::end(normals));
#endif

			const mesh_ind_t indices[]
			{
				static_cast<mesh_ind_t>(vertexIndex),
				static_cast<mesh_ind_t>(vertexIndex + 1),
				static_cast<mesh_ind_t>(vertexIndex + 2),
				static_cast<mesh_ind_t>(vertexIndex),
				static_cast<mesh_ind_t>(vertexIndex + 2),
				static_cast<mesh_ind_t>(vertexIndex + 3),
			};
			mesh.indices.insert(mesh.indices.end(), std::begin(indices), std::end(indices));
		}
		inline static void renderUp(
			const Vec3<size_t>& position,
			const size_t vertexIndex,
			Mesh& mesh)
		{
			const mesh_vert_t vertices[]
			{
				static_cast<mesh_vert_t>(position.x),
				static_cast<mesh_vert_t>(position.y + 1),
				static_cast<mesh_vert_t>(position.z),

				static_cast<mesh_vert_t>(position.x),
				static_cast<mesh_vert_t>(position.y + 1),
				static_cast<mesh_vert_t>(position.z + 1),

				static_cast<mesh_vert_t>(position.x + 1),
				static_cast<mesh_vert_t>(position.y + 1),
				static_cast<mesh_vert_t>(position.z + 1),

				static_cast<mesh_vert_t>(position.x + 1),
				static_cast<mesh_vert_t>(position.y + 1),
				static_cast<mesh_vert_t>(position.z),
			};
			mesh.vertices.insert(mesh.vertices.end(), std::begin(vertices), std::end(vertices));

#if defined(VOXEL_USE_MESH_NORM)
			static const mesh_vert_t normals[]
			{
				static_cast<mesh_vert_t>(0),
				static_cast<mesh_vert_t>(upDir),
				static_cast<mesh_vert_t>(0),

				static_cast<mesh_vert_t>(0),
				static_cast<mesh_vert_t>(upDir),
				static_cast<mesh_vert_t>(0),

				static_cast<mesh_vert_t>(0),
				static_cast<mesh_vert_t>(upDir),
				static_cast<mesh_vert_t>(0),

				static_cast<mesh_vert_t>(0),
				static_cast<mesh_vert_t>(upDir),
				static_cast<mesh_vert_t>(0),
			};
			mesh.vertices.insert(mesh.vertices.end(), std::begin(normals), std::end(normals));
#endif

			const mesh_ind_t indices[]
			{
				static_cast<mesh_ind_t>(vertexIndex),
				static_cast<mesh_ind_t>(vertexIndex + 1),
				static_cast<mesh_ind_t>(vertexIndex + 2),
				static_cast<mesh_ind_t>(vertexIndex),
				static_cast<mesh_ind_t>(vertexIndex + 2),
				static_cast<mesh_ind_t>(vertexIndex + 3),
			};
			mesh.indices.insert(mesh.indices.end(), std::begin(indices), std::end(indices));
		}
		inline static void renderBack(
			const Vec3<size_t>& position,
			const size_t vertexIndex,
			Mesh& mesh)
		{
			const mesh_vert_t vertices[]
			{
				static_cast<mesh_vert_t>(position.x),
				static_cast<mesh_vert_t>(position.y),
				static_cast<mesh_vert_t>(position.z),

				static_cast<mesh_vert_t>(position.x),
				static_cast<mesh_vert_t>(position.y + 1),
				static_cast<mesh_vert_t>(position.z),

				static_cast<mesh_vert_t>(position.x + 1),
				static_cast<mesh_vert_t>(position.y + 1),
				static_cast<mesh_vert_t>(position.z),

				static_cast<mesh_vert_t>(position.x),
				static_cast<mesh_vert_t>(position.y + 1),
				static_cast<mesh_vert_t>(position.z),
			};
			mesh.vertices.insert(mesh.vertices.end(), std::begin(vertices), std::end(vertices));

#if defined(VOXEL_USE_MESH_NORM)
			static const mesh_vert_t normals[]
			{
				static_cast<mesh_vert_t>(0),
				static_cast<mesh_vert_t>(0),
				static_cast<mesh_vert_t>(backDir),

				static_cast<mesh_vert_t>(0),
				static_cast<mesh_vert_t>(0),
				static_cast<mesh_vert_t>(backDir),

				static_cast<mesh_vert_t>(0),
				static_cast<mesh_vert_t>(0),
				static_cast<mesh_vert_t>(backDir),

				static_cast<mesh_vert_t>(0),
				static_cast<mesh_vert_t>(0),
				static_cast<mesh_vert_t>(backDir),
			};
			mesh.vertices.insert(mesh.vertices.end(), std::begin(normals), std::end(normals));
#endif

			const mesh_ind_t indices[]
			{
				static_cast<mesh_ind_t>(vertexIndex),
				static_cast<mesh_ind_t>(vertexIndex + 1),
				static_cast<mesh_ind_t>(vertexIndex + 2),
				static_cast<mesh_ind_t>(vertexIndex),
				static_cast<mesh_ind_t>(vertexIndex + 2),
				static_cast<mesh_ind_t>(vertexIndex + 3),
			};
			mesh.indices.insert(mesh.indices.end(), std::begin(indices), std::end(indices));
		}
		inline static void renderForward(
			const Vec3<size_t>& position,
			const size_t vertexIndex,
			Mesh& mesh)
		{
			const mesh_vert_t vertices[]
			{
				static_cast<mesh_vert_t>(position.x + 1),
				static_cast<mesh_vert_t>(position.y + 1),
				static_cast<mesh_vert_t>(position.z),

				static_cast<mesh_vert_t>(position.x + 1),
				static_cast<mesh_vert_t>(position.y + 1),
				static_cast<mesh_vert_t>(position.z + 1),

				static_cast<mesh_vert_t>(position.x),
				static_cast<mesh_vert_t>(position.y + 1),
				static_cast<mesh_vert_t>(position.z + 1),

				static_cast<mesh_vert_t>(position.x),
				static_cast<mesh_vert_t>(position.y),
				static_cast<mesh_vert_t>(position.z + 1),
			};
			mesh.vertices.insert(mesh.vertices.end(), std::begin(vertices), std::end(vertices));

#if defined(VOXEL_USE_MESH_NORM)
			static const mesh_vert_t normals[]
			{
				static_cast<mesh_vert_t>(0),
				static_cast<mesh_vert_t>(0),
				static_cast<mesh_vert_t>(forwardDir),

				static_cast<mesh_vert_t>(0),
				static_cast<mesh_vert_t>(0),
				static_cast<mesh_vert_t>(forwardDir),

				static_cast<mesh_vert_t>(0),
				static_cast<mesh_vert_t>(0),
				static_cast<mesh_vert_t>(forwardDir),

				static_cast<mesh_vert_t>(0),
				static_cast<mesh_vert_t>(0),
				static_cast<mesh_vert_t>(forwardDir),
			};
			mesh.vertices.insert(mesh.vertices.end(), std::begin(normals), std::end(normals));
#endif

			const mesh_ind_t indices[]
			{
				static_cast<mesh_ind_t>(vertexIndex),
				static_cast<mesh_ind_t>(vertexIndex + 1),
				static_cast<mesh_ind_t>(vertexIndex + 2),
				static_cast<mesh_ind_t>(vertexIndex),
				static_cast<mesh_ind_t>(vertexIndex + 2),
				static_cast<mesh_ind_t>(vertexIndex + 3),
			};
			mesh.indices.insert(mesh.indices.end(), std::begin(indices), std::end(indices));
		}
	public:
		void render(
			const Registry& registry,
			const Cluster& cluster,
			const Vec3<size_t>& position,
			size_t& vertexIndex,
			Mesh& mesh) override
		{
			// TODO: check if renderer is BlockRederer type
			// optimize nullptr side checks

			if (position.x == 0)
			{
				if (!cluster.left || 
					!registry.get(cluster.left->getIDS().get(sectorSafeLength, position.y, position.z)).renderer)
				{
					renderLeft(position, vertexIndex, mesh);
					vertexIndex += quadVertCount;
				}

				if (!cluster.center || 
					!registry.get(cluster.center->getIDS().get(position.x + rightDir, position.y, position.z)).renderer)
				{
					renderRight(position, vertexIndex, mesh);
					vertexIndex += quadVertCount;
				}
			}
			else if (position.x == sectorSafeLength)
			{
				if (!cluster.center ||
					!registry.get(cluster.center->getIDS().get(position.x + leftDir, position.y, position.z)).renderer)
				{
					renderLeft(position, vertexIndex, mesh);
					vertexIndex += quadVertCount;
				}
				if (!cluster.right || 
					!registry.get(cluster.right->getIDS().get(zeroDir, position.y, position.z)).renderer)
				{
					renderRight(position, vertexIndex, mesh);
					vertexIndex += quadVertCount;
				}
			}
			else
			{
				if (!cluster.center ||
					!registry.get(cluster.center->getIDS().get(position.x + leftDir, position.y, position.z)).renderer)
				{
					renderLeft(position, vertexIndex, mesh);
					vertexIndex += quadVertCount;
				}
				if (!cluster.center ||
					!registry.get(cluster.center->getIDS().get(position.x + rightDir, position.y, position.z)).renderer)
				{
					renderRight(position, vertexIndex, mesh);
					vertexIndex += quadVertCount;
				}
			}

			if (position.y == 0)
			{
				if (!cluster.down ||
					!registry.get(cluster.down->getIDS().get(position.x, sectorSafeLength, position.z)).renderer)
				{
					renderDown(position, vertexIndex, mesh);
					vertexIndex += quadVertCount;
				}
				if (!cluster.center || 
					!registry.get(cluster.center->getIDS().get(position.x, position.y + upDir, position.z)).renderer)
				{
					renderUp(position, vertexIndex, mesh);
					vertexIndex += quadVertCount;
				}
			}
			else if (position.y == sectorSafeLength)
			{
				if (!cluster.center || 
					!registry.get(cluster.center->getIDS().get(position.x, position.y + downDir, position.z)).renderer)
				{
					renderDown(position, vertexIndex, mesh);
					vertexIndex += quadVertCount;
				}
				if (!cluster.up || 
					!registry.get(cluster.up->getIDS().get(position.x, zeroDir, position.z)).renderer)
				{
					renderUp(position, vertexIndex, mesh);
					vertexIndex += quadVertCount;
				}
			}
			else
			{
				if (!cluster.center || 
					!registry.get(cluster.center->getIDS().get(position.x, position.y + downDir, position.z)).renderer)
				{
					renderDown(position, vertexIndex, mesh);
					vertexIndex += quadVertCount;
				}
				if (!cluster.center || 
					!registry.get(cluster.center->getIDS().get(position.x, position.y + upDir, position.z)).renderer)
				{
					renderUp(position, vertexIndex, mesh);
					vertexIndex += quadVertCount;
				}
			}

			if (position.z == 0)
			{
				if (!cluster.back ||
					!registry.get(cluster.back->getIDS().get(position.x, position.y, sectorSafeLength)).renderer)
				{
					renderBack(position, vertexIndex, mesh);
					vertexIndex += quadVertCount;
				}
				if (!cluster.center ||
					!registry.get(cluster.center->getIDS().get(position.x, position.y, position.z + forwardDir)).renderer)
				{
					renderForward(position, vertexIndex, mesh);
					vertexIndex += quadVertCount;
				}
			}
			else if (position.z == sectorSafeLength)
			{
				if (!cluster.center ||
					!registry.get(cluster.center->getIDS().get(position.x, position.y, position.z + backDir)).renderer)
				{
					renderBack(position, vertexIndex, mesh);
					vertexIndex += quadVertCount;
				}
				if (!cluster.forward ||
					!registry.get(cluster.forward->getIDS().get(position.x, position.y, zeroDir)).renderer)
				{
					renderForward(position, vertexIndex, mesh);
					vertexIndex += quadVertCount;
				}
			}
			else
			{
				if (!cluster.center || 
					!registry.get(cluster.center->getIDS().get(position.x, position.y, position.z + backDir)).renderer)
				{
					renderBack(position, vertexIndex, mesh);
					vertexIndex += quadVertCount;
				}
				if (!cluster.center || 
					!registry.get(cluster.center->getIDS().get(position.x, position.y, position.z + forwardDir)).renderer)
				{
					renderForward(position, vertexIndex, mesh);
					vertexIndex += quadVertCount;
				}
			}
		}
	};
}
