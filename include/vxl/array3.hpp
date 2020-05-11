#pragma once
#include <vector>
#include <stdexcept>

namespace vxl
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
			sizeXY(_sizeX* _sizeY)
		{
			data = new T[size];
			std::fill_n(data, size, value);
		}
		Array3(const size_t sizeXYZ,
			const T& value = T()) :
			size(sizeXYZ * sizeXYZ * sizeXYZ),
			sizeX(sizeXYZ),
			sizeY(sizeXYZ),
			sizeZ(sizeXYZ),
			sizeXY(sizeXYZ* sizeXYZ)
		{
			data = new T[size];
			std::fill_n(data, size, value);
		}
		virtual ~Array3()
		{
			delete[] data;
			data = nullptr;
		}

		inline size_t getSize() const noexcept
		{
			return size;
		}
		inline size_t getSizeX() const noexcept
		{
			return sizeX;
		}
		inline size_t getSizeY() const noexcept
		{
			return sizeY;
		}
		inline size_t getSizeZ() const noexcept
		{
			return sizeZ;
		}
		inline size_t getSizeXY() const noexcept
		{
			return sizeXY;
		}
		inline T* getData() const noexcept
		{
			return data;
		}

		inline T& at(const size_t position)
		{
			if (position >= size)
				throw std::out_of_range("Out of size range");
			return data[position];
		}
		inline const T& at(const size_t position) const
		{
			if (position >= size)
				throw std::out_of_range("Out of size range");
			return data[position];
		}
		inline T& at(const size_t x, const size_t y, const size_t z)
		{
			if (x >= sizeX || y >= sizeY || z >= sizeZ)
				throw std::out_of_range("Out of size range");
			return data[x + y * sizeX + z * sizeXY];
		}
		inline const T& at(const size_t x, const size_t y, const size_t z) const
		{
			if (x >= sizeX || y >= sizeY || z >= sizeZ)
				throw std::out_of_range("Out of size range");
			return data[x + y * sizeX + z * sizeXY];
		}

		inline T& atUnsafe(const size_t position) noexcept
		{
			return data[position];
		}
		inline const T& atUnsafe(const size_t position) const noexcept
		{
			return data[position];
		}
		inline T& atUnsafe(const size_t x, const size_t y, const size_t z)  noexcept
		{
			return data[x + y * sizeX + z * sizeXY];
		}
		inline const T& atUnsafe(const size_t x, const size_t y, const size_t z) const noexcept
		{
			return data[x + y * sizeX + z * sizeXY];
		}

		inline void fill(const T& value = T())
		{
			std::fill_n(data, size, value);
		}
	};
}
