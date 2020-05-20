#pragma once
#include <stdexcept>

namespace voxel
{
	template<class T>
	class Array2
	{
	protected:
		size_t size;
		size_t sizeX;
		size_t sizeY;
		T* data;
	public:
		Array2(const size_t _sizeX,
			const size_t _sizeY,
			const T& value = T()) :
			sizeX(_sizeX),
			sizeY(_sizeY)
		{
			data = new T[size];
			std::fill_n(data, size, value);
		}
		virtual ~Array2()
		{
			delete[] data;
			data = nullptr;
		}

		inline const size_t getSize() const noexcept
		{
			return size;
		}
		inline const size_t getSizeX() const noexcept
		{
			return sizeX;
		}
		inline const size_t getSizeY() const noexcept
		{
			return sizeY;
		}

		inline T& getSafe(const size_t index)
		{
			if (index >= size)
				throw std::out_of_range("Out of size range");
			return data[index];
		}
		inline const T& getSafe(const size_t index) const
		{
			if (index >= size)
				throw std::out_of_range("Out of size range");
			return data[index];
		}
		inline void setSafe(const size_t index, const T& value)
		{
			if (index >= size)
				throw std::out_of_range("Out of size range");
			data[index] = value;
		}

		inline T& getSafe(const size_t x, const size_t y)
		{
			if (x >= sizeX || y >= sizeY)
				throw std::out_of_range("Out of size range");
			return data[x + y * sizeX];
		}
		inline const T& getSafe(const size_t x, const size_t y) const
		{
			if (x >= sizeX || y >= sizeY)
				throw std::out_of_range("Out of size range");
			return data[x + y * sizeX];
		}
		inline void setSafe(const size_t x, const size_t y, const T& value)
		{
			if (x >= sizeX || y >= sizeY)
				throw std::out_of_range("Out of size range");
			data[x + y * sizeX] = value;
		}

		inline T& get(const size_t index) noexcept
		{
			return data[index];
		}
		inline const T& get(const size_t index) const noexcept
		{
			return data[index];
		}
		inline void set(const size_t index, const T& value) noexcept
		{
			data[index] = value;
		}

		inline T& get(const size_t x, const size_t y) noexcept
		{
			return data[x + y * sizeX];
		}
		inline const T& get(const size_t x, const size_t y) const noexcept
		{
			return data[x + y * sizeX];
		}
		inline void set(const size_t x, const size_t y, const T& value) noexcept
		{
			data[x + y * sizeX] = value;
		}

		inline const T* getData() const noexcept
		{
			return data;
		}
	};
}
