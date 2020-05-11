#pragma once
#include <vector>

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
}
