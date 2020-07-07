#pragma once
#include <voxel/generator.hpp>

#include <thread>

namespace VOXEL_NAMESPACE
{
	class AsyncGenerator : public Generator
	{
	protected:
		std::thread generatorThread;
	public:
		AsyncGenerator()
		{

		}
		virtual ~AsyncGenerator()
		{}

		AsyncStructure(const AsyncStructure<T>&) = delete;
	};
}
