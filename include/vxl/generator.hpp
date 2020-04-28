#pragma once
#include <vxl/sector.hpp>

// TODO: switch to FastNoise2
// https://github.com/Auburns/FastNoise2
#include <FastNoiseSIMD/FastNoiseSIMD.h>

#include <cstdlib>
#include <stdexcept>

namespace vxl
{
	class Generator
	{
	protected:
		FastNoiseSIMD* m_fastNoise;
	public:
		Generator() :
			m_fastNoise(FastNoiseSIMD::NewFastNoiseSIMD())
		{}
		virtual ~Generator()
		{
			delete m_fastNoise;
		}

		template<class V, class M>
		void generateRandom(Sector<V, M>& sector, const V voxel, const int32_t chance = 50, const uint32_t seed = 1337)
		{
			if (chance < 0 || chance > 100)
				throw std::range_error("Chance out of range");

			srand(seed);

			const auto modulo = 10000 / chance;

			for (size_t i = 0; i < sector.size(); i++)
			{
				if(rand() % modulo < 100)
					sector.voxelAtUnsafe(i) = voxel;
			}
		}
	};
}