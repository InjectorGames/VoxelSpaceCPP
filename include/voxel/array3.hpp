#pragma once
#include <voxel/vec3.hpp>
#include <stdexcept>

namespace VOXEL_NAMESPACE
{
	template<class T>
	class Array3
	{
	protected:
		size_t count;
		Vec3<size_t> size;
		T* data;
	public:
		Array3(const Vec3<size_t>& _size,
			const T& value = T()) :
			count(_size.x* _size.y* _size.z),
			size(_size)
		{
			data = new T[count];
			std::uninitialized_fill_n(data, count, value);
		}
		Array3(const size_t _sizeX,
			const size_t _sizeY,
			const size_t _sizeZ,
			const T& value = T()) :
			count(_sizeX * _sizeY * _sizeZ),
			size(_sizeX, _sizeY, _sizeZ)
		{
			data = new T[count];
			std::uninitialized_fill_n(data, count, value);
		}
		Array3(const Array3<T>& array) :
			count(array.count),
			size(array.size)
		{
			data = new T[count];
			std::uninitialized_copy_n(array.data, count, data);
		}
		virtual ~Array3()
		{
			delete[] data;
			data = nullptr;
		}

		inline const size_t getCount() const noexcept
		{
			return count;
		}

		inline const Vec3<size_t>& getSize() const noexcept
		{
			return size;
		}
		inline const size_t getSizeX() const noexcept
		{
			return size.x;
		}
		inline const size_t getSizeY() const noexcept
		{
			return size.y;
		}
		inline const size_t getSizeZ() const noexcept
		{
			return size.z;
		}

		inline T* getData() noexcept
		{
			return data;
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

		inline T& getSafe(const Vec3<size_t>& position)
		{
			if (position.x >= size.x || position.y >= size.y || position.z >= size.z)
				throw std::out_of_range("Out of size range");
			return data[position.x + size.x * (position.y + size.y * position.z)];
		}
		inline T& getSafe(const size_t x, const size_t y, const size_t z)
		{
			if (x >= size.x || y >= size.y || z >= size.z)
				throw std::out_of_range("Out of size range");
			return data[x + size.x * (y + size.y * z)];
		}
		
		inline const T& getSafe(const Vec3<size_t>& position) const
		{
			if (position.x >= size.x || position.y >= size.y || position.z >= size.z)
				throw std::out_of_range("Out of size range");
			return data[position.x + size.x * (position.y + size.y * position.z)];
		}
		inline const T& getSafe(const size_t x, const size_t y, const size_t z) const
		{
			if (x >= size.x || y >= size.y || z >= size.z)
				throw std::out_of_range("Out of size range");
			return data[x + size.x * (y + size.y * z)];
		}
		
		inline void setSafe(const Vec3<size_t>& position, const T& value)
		{
			if (position.x >= sizeX || position.y >= sizeY || position.z >= sizeZ)
				throw std::out_of_range("Out of size range");
			data[position.x + sizeX * (position.y + sizeY * position.z)] = T(value);
		}
		inline void setSafe(const size_t x, const size_t y, const size_t z, const T& value)
		{
			if (x >= size.x || y >= size.y || z >= size.z)
				throw std::out_of_range("Out of size range");
			data[x + size.x * (y + size.y * z)] = T(value);
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

		inline T& get(const Vec3<size_t>& position) noexcept
		{
			return data[position.x + size.x * (position.y + size.y * position.z)];
		}
		inline T& get(const size_t x, const size_t y, const size_t z) noexcept
		{
			return data[x + size.x * (y + size.y * z)];
		}

		inline const T& get(const Vec3<size_t>& position) const noexcept
		{
			return data[position.x + size.x * (position.y + size.y * position.z)];
		}
		inline const T& get(const size_t x, const size_t y, const size_t z) const noexcept
		{
			return data[x + size.x * (y + size.y * z)];
		}

		inline void set(const Vec3<size_t>& position, const T& value) noexcept
		{
			data[position.x + size.x * (position.y + size.y * position.z)] = T(value);
		}
		inline void set(const size_t x, const size_t y, const size_t z, const T& value) noexcept
		{
			data[x + size.x * (y + size.y * z)] = T(value);
		}

		inline void fill(const T& value = T()) noexcept
		{
			std::uninitialized_fill_n(data, size, value);
		}

		inline const size_t positionToIndex(const Vec3<size_t>& position) const noexcept
		{
			return position.x + size.x * (position.y + size.y * position.z);
		}
		inline const size_t positionToIndex(
			const size_t x, const size_t y, const size_t z) const noexcept
		{
			return x + size.x * (y + size.y * z);
		}

		inline const size_t positionToIndexSafe(const Vec3<size_t>& position) const
		{
			if (position.x >= size.x || position.y >= size.y || position.z >= size.z)
				throw std::out_of_range("Out of size range");
			return position.x + size.x * (position.y + size.y * position.z);
		}
		inline const size_t positionToIndexSafe(
			const size_t x, const size_t y, const size_t z) const
		{
			if (x >= size.x || y >= size.y || z >= size.z)
				throw std::out_of_range("Out of size range");
			return x + size.x * (y + size.y * z);
		}

		inline const bool positionToIndexNoex(const Vec3<size_t>& position,
			size_t& index) const noexcept
		{
			if (position.x >= size.x || position.y >= size.y || position.z >= size.z)
				return false;
			index = position.x + size.x * (position.y + size.y * position.z);
			return true;
		}
		inline const bool positionToIndexNoex(
			const size_t x, const size_t y, const size_t z,
			size_t& index) const noexcept
		{
			if (x >= size.x || y >= size.y || z >= size.z)
				return false;
			index = x + size.x * (y + size.y * z);
			return true;
		}

		inline const Vec3<size_t> indexToPosition(size_t index) const noexcept
		{
			Vec3<size_t> position;
			position.z = index / (size.x * size.y);
			index -= position.z * (size.x * size.y);
			position.y = index / size.x;
			position.x = index - position.y * size.x;
			return position;
		}
		inline const Vec3<size_t> indexToPositionSafe(size_t index) const
		{
			if (index >= size)
				throw std::out_of_range("Out of size range");
			Vec3<size_t> position;
			position.z = index / (size.x * size.y);
			index -= position.z * (size.x * size.y);
			position.y = index / size.x;
			position.x = index - position.y * size.x;
			return position;
		}
		inline const bool indexToPositionNoex(size_t index,
			Vec3<size_t>& position) const noexcept
		{
			if (index >= size)
				return false;
			position.z = index / (size.x * size.y);
			index -= position.z * (size.x * size.y);
			position.y = index / size.x;
			position.x = index - position.y * size.x;
			return true;
		}
	};
}
