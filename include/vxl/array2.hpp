#pragma once
#include <vector>
#include <stdexcept>

namespace vxl
{
	template<class T, class A = std::allocator<T>>
	class Vector2
	{
	protected:
		size_t sizeX;
		size_t sizeY;

		std::vector<T, A> vector;
	public:
		Vector2(const size_t _sizeX, const size_t _sizeY, const std::vector<T, A>& _vector) :
			sizeX(_sizeX),
			sizeY(_sizeY),
			vector(_vector)
		{
			if (_vector.size() != _sizeX * _sizeY)
				throw std::runtime_error("Incorrect vector size");
		}
		Vector2(const size_t _sizeX, const size_t _sizeY, const T& value = T()) :
			sizeX(_sizeX),
			sizeY(_sizeY),
			vector(_sizeX * _sizeY, value)
		{}
		Vector2(const size_t sizeXY, const T& value = T()) :
			sizeX(sizeXY),
			sizeY(sizeXY),
			vector(sizeXY* sizeXY, value)
		{}

		inline size_t getSize() const noexcept
		{
			return vector.size();
		}
		inline size_t getSizeX() const noexcept
		{
			return sizeX;
		}
		inline size_t getSizeY() const noexcept
		{
			return sizeY;
		}

		inline void resize(const size_t _sizeX, const size_t _sizeY)
		{
			vector.resize(_sizeX * _sizeY);
			sizeX = _sizeX;
			sizeY = _sizeY;
		}
		inline void resize(const size_t _sizeX, const size_t _sizeY, const T& value)
		{
			vector.resize(_sizeX * _sizeY, value);
			sizeX = _sizeX;
			sizeY = _sizeY;
		}
		inline void resize(const size_t sizeXY)
		{
			vector.resize(sizeXY * sizeXY);
			sizeX = sizeXY;
			sizeY = sizeXY;
		}
		inline void resize(const size_t sizeXY, const T& value)
		{
			vector.resize(sizeXY * sizeXY, value);
			sizeX = sizeXY;
			sizeY = sizeXY;
		}

		inline T& at(const size_t position)
		{
			return vector.at(position);
		}
		inline const T& at(const size_t position) const
		{
			return vector.at(position);
		}

		inline T& at(const size_t x, const size_t y)
		{
			if (x >= sizeX || y >= sizeY)
				throw std::out_of_range("Out of size range");
			return vector[x + y * sizeX];
		}
		inline const T& at(const size_t x, const size_t y) const
		{
			if (x >= sizeX || y >= sizeY)
				throw std::out_of_range("Out of size range");
			return vector[x + y * sizeX];
		}

		inline T& atUnsafe(const size_t position) noexcept
		{
			return vector[position];
		}
		inline const T& atUnsafe(const size_t position) const noexcept
		{
			return vector[position];
		}

		inline T& atUnsafe(const size_t x, const size_t y)  noexcept
		{
			return vector[x + y * sizeX];
		}
		inline const T& atUnsafe(const size_t x, const size_t y) const noexcept
		{
			return vector[x + y * sizeX];
		}

		inline  T* getData() noexcept
		{
			return vector.data();
		}
		inline const T* getData() const noexcept
		{
			return vector.data();
		}

		inline std::vector<T, A>& getVector() noexcept
		{
			return vector;
		}
		inline const std::vector<T, A>& getVector() const noexcept
		{
			return vector;
		}
	};
}
