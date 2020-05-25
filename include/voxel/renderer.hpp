#pragma once
#include <voxel/vec3.hpp>
#include <voxel/mesh.hpp>

namespace VOXEL_NAMESPACE
{
	class Cluster;
	class Register;

	class Renderer
	{
	public:
		virtual void generate(const Register& _register, const Cluster& cluster,
			 const Vec3<size_t>& position, Mesh& mesh) = 0;
	};
}
