#pragma once
#include <voxel/mesh.hpp>

namespace VOXEL_NAMESPACE
{
	class Cluster;
	class Register;

	class Renderer
	{
	public:
		virtual void generate(Mesh& mesh, 
			const Register& _register, const Cluster& cluster,
			const size_t x, const size_t y, const size_t z) = 0;
	};
}
