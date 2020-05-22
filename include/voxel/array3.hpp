#pragma once
#include <voxel/defines.hpp>
#include <stdexcept>

namespace VOXEL_NAMESPACE
{
	template<class T>
	class Array3
	{
	protected:
		size_t size;
		size_t sizeX;
		size_t sizeY;
		size_t sizeZ;
		size_t sizeXY;
		T* data;
	public:
		Array3(const size_t _sizeX,
			const size_t _sizeY,
			const size_t _sizeZ,
			const T& value = T()) :
			size(_sizeX * _sizeY * _sizeZ),
			sizeX(_sizeX),
			sizeY(_sizeY),
			sizeZ(_sizeZ),
			sizeXY(_sizeX * _sizeY)
		{
			data = new T[size];
			std::uninitialized_fill_n(data, size, value);
		}
		Array3(const Array3& array) :
			size(array.size),
			sizeX(array.sizeX),
			sizeY(array.sizeY),
			sizeZ(array.sizeZ),
			sizeXY(array.sizeXY)
		{
			data = new T[size];
			std::uninitialized_copy_n(array.data, size, data);
		}
		virtual ~Array3()
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
		inline const size_t getSizeZ() const noexcept
		{
			return sizeZ;
		}
		inline const size_t getSizeXY() const noexcept
		{
			return sizeXY;
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

		inline T& getSafe(const size_t x, const size_t y, const size_t z)
		{
			if (x >= sizeX || y >= sizeY || z >= sizeZ)
				throw std::out_of_range("Out of size range");
			return data[x + y * sizeX + z * sizeXY];
		}
		inline const T& getSafe(const size_t x, const size_t y, const size_t z) const
		{
			if (x >= sizeX || y >= sizeY || z >= sizeZ)
				throw std::out_of_range("Out of size range");
			return data[x + y * sizeX + z * sizeXY];
		}
		inline void setSafe(const size_t x, const size_t y, const size_t z, const T& value)
		{
			if (x >= sizeX || y >= sizeY || z >= sizeZ)
				throw std::out_of_range("Out of size range");
			data[x + y * sizeX + z * sizeXY] = T(value);
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

		inline T& get(const size_t x, const size_t y, const size_t z) noexcept
		{
			return data[x + y * sizeX + z * sizeXY];
		}
		inline const T& get(const size_t x, const size_t y, const size_t z) const noexcept
		{
			return data[x + y * sizeX + z * sizeXY];
		}
		inline void set(const size_t x, const size_t y, const size_t z, const T& value) noexcept
		{
			data[x + y * sizeX + z * sizeXY] = T(value);
		}

		inline void fill(const T& value = T()) noexcept
		{
			std::uninitialized_fill_n(data, size, value);
		}
	};
}
