#pragma once
#include <vxl/sector.hpp>

// TODO: switch to FastNoise2
// https://github.com/Auburns/FastNoise2
#include <FastNoiseSIMD/FastNoiseSIMD.h>

#include <stdexcept>

namespace vxl
{
	class Generator
	{
	protected:
		FastNoiseSIMD* fastNoise;
	public:
		Generator()
		{
			fastNoise = FastNoiseSIMD::NewFastNoiseSIMD();
		}
		virtual ~Generator()
		{
			delete fastNoise;
		}

		template<class TID, class TMD>
		void generateRandom(Sector<TID, TMD>& sector, const TID id, const int32_t chance = 50, const uint32_t seed = 1337)
		{
			if (chance < 0 || chance > 100)
				throw std::range_error("Chance out of range");

			srand(seed);

			const auto modulo = 10000 / chance;

			for (size_t i = 0; i < sector.getSize(); i++)
			{
				if(rand() % modulo < 100)
					sector.idAtUnsafe(i) = id;
			}
		}
	};
}