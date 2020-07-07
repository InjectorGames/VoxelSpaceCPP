#pragma once
#include <voxel/structure.hpp>

// TODO: switch to FastNoise2
// https://github.com/Auburns/FastNoise2
#include <FastNoise.h>
#include <FastNoiseSIMD/FastNoiseSIMD.h>

namespace VOXEL_NAMESPACE
{
	// TODO: make this class abstract as mesh generator
	class Generator
	{
	protected:
		int seed;
		FastNoise noise;
		FastNoiseSIMD* noiseSIMD;
	public:
		Generator(const int _seed = 1337) :
			seed(_seed),
			noise(),
			noiseSIMD(FastNoiseSIMD::NewFastNoiseSIMD(seed))
		{}
		virtual ~Generator()
		{
			delete noiseSIMD;
			noiseSIMD = nullptr;
		}

		inline const int getSeed() const noexcept
		{
			return seed;
		}
		inline void setSeed(const int _seed) noexcept
		{
			seed = _seed;
			noise.SetSeed(seed);
			noiseSIMD->SetSeed(seed);
		}

		inline void generateRandom(
			Array3<id_t>& ids,
			const id_t id,
			const int32_t chance = 50) const
		{
			if (chance < 0 || chance > 100)
				throw std::range_error("Chance out of range");

			// TODO: use white noise instead
			srand(static_cast<uint32_t>(seed));
			const auto modulo = 10000 / chance;

			for (size_t i = 0; i < sectorSize; i++)
			{
				if(rand() % modulo < 100)
					ids.set(i, id);
			}
		}
	};
}