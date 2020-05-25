#pragma once
#include <stdexcept>

namespace VOXEL_NAMESPACE
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
			std::uninitialized_fill_n(data, size, value);
		}
		Array2(const Array2& array) :
			size(array.size),
			sizeX(array.sizeX),
			sizeY(array.sizeY)
		{
			data = new T[size];
			std::uninitialized_copy_n(array.data, size, data);
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

		inline const T* getData() const noexcept
		{
			return data;
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
			data[index] = T(value);
		}

		inline T& getSafe(const size_t x, const size_t y)
		{
			if (x >= sizeX || y >= sizeY)
				throw std::out_of_range("Out of size range");
			return data[x + sizeX * y];
		}
		inline const T& getSafe(const size_t x, const size_t y) const
		{
			if (x >= sizeX || y >= sizeY)
				throw std::out_of_range("Out of size range");
			return data[x + sizeX * y];
		}
		inline void setSafe(const size_t x, const size_t y, const T& value)
		{
			if (x >= sizeX || y >= sizeY)
				throw std::out_of_range("Out of size range");
			data[x + sizeX * y] = T(value);
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
			data[index] = T(value);
		}

		inline T& get(const size_t x, const size_t y) noexcept
		{
			return data[x + sizeX * y];
		}
		inline const T& get(const size_t x, const size_t y) const noexcept
		{
			return data[x + sizeX * y];
		}
		inline void set(const size_t x, const size_t y, const T& value) noexcept
		{
			data[x + sizeX * y] = T(value);
		}

		inline void fill(const T& value = T()) noexcept
		{
			std::uninitialized_fill_n(data, size, value);
		}

		inline const size_t positionToIndex(
			const size_t x, const size_t y) const noexcept
		{
			return x + sizeX * y;
		}
		inline void indexToPosition(
			const size_t index, size_t& x, size_t& y) const noexcept
		{
			y = index / sizeX;
			x = index - y * sizeX;
		}
	};
}
