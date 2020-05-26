#pragma once
#include <voxel/terrain.hpp>

#include <mutex>
#include <thread>

namespace VOXEL_NAMESPACE
{
	template<class T = Sector>
	class AsyncTerrain : public Terrain<T>
	{
	protected:
		bool isRunning;
		std::mutex updateMutex;
		std::thread updateThread;

		inline void update(const Registry& registry)
		{
			std::chrono::steady_clock::time_point lastTime;

			while (isRunning)
			{
				updateMutex.lock();

				auto time = std::chrono::high_resolution_clock::now();
				auto deltaTime = std::chrono::duration_cast<
					std::chrono::duration<time_t>>(time - lastTime);
				lastTime = time;
				Terrain<T>::update(registry, deltaTime.count());

				if(sleepDelay > 0)
					std::this_thread::sleep_for(std::chrono::milliseconds(sleepDelay));

				updateMutex.unlock();
			}
		}
	public:
		int sleepDelay;

		AsyncTerrain(const std::map<Vec3<size_t>, T>& sectors = {},
			const int _sleepDelay = 1) :
			Terrain<T>(sectors),
			sleepDelay(_sleepDelay),
			isRunning(false),
			updateMutex(),
			updateThread()
		{}
		virtual ~AsyncTerrain()
		{
			if (isRunning)
				stopUpdate();
		}

		AsyncTerrain(const AsyncTerrain<T>&) = delete;

		inline void lockUpdate() noexcept
		{
			updateMutex.lock();
		}
		inline void unlockUpdate() noexcept
		{
			updateMutex.unlock();
		}

		inline void startUpdate(const Registry& registry)
		{
			if (isRunning)
				throw std::runtime_error("Thread is already running");

			isRunning = true;
			updateThread = std::thread(&AsyncTerrain<T>::update, this, registry);
		}
		inline void stopUpdate()
		{
			if (!isRunning)
				throw std::runtime_error("Thread is not running");

			isRunning = false;

			if(updateThread.get_id() != std::this_thread::get_id() && updateThread.joinable())
				updateThread.join();
		}
	};
}
