#pragma once
#include <voxel/defines.hpp>
#include <voxel/vec2.hpp>
#include <stdexcept>

namespace VOXEL_NAMESPACE
{
	template<class T>
	class Array2
	{
	protected:
		size_t count;
		Vec2<size_t> size;
		T* data;
	public:
		Array2(const Vec2<size_t>& _size,
			const T& value = T()) :
			count(_size.x * _size.y),
			size(_size)
		{
			data = new T[count];
			std::uninitialized_fill_n(data, count, value);
		}
		Array2(const Array2& array) :
			count(array.count),
			size(array.size)
		{
			data = new T[count];
			std::uninitialized_copy_n(array.data, count, data);
		}
		virtual ~Array2()
		{
			delete[] data;
			data = nullptr;
		}

		inline const size_t getCount() const noexcept
		{
			return count;
		}

		inline const Vec2<size_t>& getSize() const noexcept
		{
			return size;
		}

		inline T* getData() noexcept
		{
			return data;
		}
		inline const T* getData() const noexcept
		{
			return data;
		}

		inline T& get(
			const size_t index) noexcept
		{
			return data[index];
		}
		inline const T& get(
			const size_t index) const noexcept
		{
			return data[index];
		}
		inline T& get(
			const Vec2<size_t>& position) noexcept
		{
			return data[position.x + size.x * position.y];
		}
		inline T& get(
			const size_t x, const size_t y) noexcept
		{
			return data[x + size.x * y];
		}
		inline const T& get(
			const Vec2<size_t>& position) const noexcept
		{
			return data[position.x + size.x * position.y];
		}
		inline const T& get(
			const size_t x, const size_t y) const noexcept
		{
			return data[x + size.x * y];
		}

		inline void set(
			const size_t index, const T& value) noexcept
		{
			data[index] = T(value);
		}
		inline void set(
			const Vec2<size_t>& position, const T& value) noexcept
		{
			data[position.x + size.x * position.y] = T(value);
		}
		inline void set(
			const size_t x, const size_t y, const T& value) noexcept
		{
			data[x + size.x * y] = T(value);
		}

		inline T& getSafe(
			const size_t index)
		{
			if (index >= count)
				throw std::out_of_range("Out of size range");
			return data[index];
		}
		inline const T& getSafe(
			const size_t index) const
		{
			if (index >= count)
				throw std::out_of_range("Out of size range");
			return data[index];
		}
		inline T& getSafe(
			const Vec2<size_t>& position)
		{
			if (position.x >= size.x || position.y >= size.y)
				throw std::out_of_range("Out of size range");
			return data[position.x + size.x * position.y];
		}
		inline T& getSafe(
			const size_t x, const size_t y)
		{
			if (x >= size.x || y >= size.y)
				throw std::out_of_range("Out of size range");
			return data[x + size.x * y];
		}
		inline const T& getSafe(
			const Vec2<size_t>& position) const
		{
			if (position.x >= size.x || position.y >= size.y)
				throw std::out_of_range("Out of size range");
			return data[position.x + size.x * position.y];
		}
		inline const T& getSafe(
			const size_t x, const size_t y) const
		{
			if (x >= size.x || y >= size.y)
				throw std::out_of_range("Out of size range");
			return data[x + size.x * y];
		}

		inline void setSafe(
			const size_t index, const T& value)
		{
			if (index >= count)
				throw std::out_of_range("Out of size range");
			data[index] = T(value);
		}
		inline void setSafe(
			const Vec2<size_t>& position, const T& value)
		{
			if (position.x >= size.x || position.y >= size.y)
				throw std::out_of_range("Out of size range");
			data[position.x + size.x * position.y] = T(value);
		}
		inline void setSafe(
			const size_t x, const size_t y, const T& value)
		{
			if (x >= size.x || y >= size.y)
				throw std::out_of_range("Out of size range");
			data[x + size.x * y] = T(value);
		}

		inline const bool getNoex(
			const size_t index, T& value) noexcept
		{
			if (index >= count)
				return false;
			value = data[index];
			return true;
		}
		inline const bool getNoex(
			const size_t index, const T& value) const noexcept
		{
			if (index >= count)
				return false;
			value = data[index];
			return true;
		}
		inline const bool getNoex(
			const Vec2<size_t>& position, T& value) noexcept
		{
			if (position.x >= size.x || position.y >= size.y)
				return false;
			value = data[position.x + size.x * position.y];
			return true;
		}
		inline const bool getNoex(
			const size_t x, const size_t y, T& value) noexcept
		{
			if (x >= size.x || y >= size.y)
				return false;
			value = data[x + size.x * y];
			return true;
		}
		inline const bool getNoex(
			const Vec2<size_t>& position, const T& value) const noexcept
		{
			if (position.x >= size.x || position.y >= size.y)
				return false;
			value = data[position.x + size.x * position.y];
			return true;
		}
		inline const bool getNoex(
			const size_t x, const size_t y, const T& value) const noexcept
		{
			if (x >= size.x || y >= size.y)
				return false;
			value = data[x + size.x * y];
			return true;
		}

		inline const bool setNoex(
			const size_t index, const T& value) noexcept
		{
			if (index >= count)
				return false;
			data[index] = T(value);
			return true;
		}
		inline const bool setNoex(
			const Vec2<size_t>& position, const T& value) noexcept
		{
			if (position.x >= size.x || position.y >= size.y)
				return false;
			data[position.x + size.x * position.y] = T(value);
			return true;
		}
		inline const bool setNoex(
			const size_t x, const size_t y, const T& value) noexcept
		{
			if (x >= size.x || y >= size.y)
				return false;
			data[x + size.x * y] = T(value);
			return true;
		}

		inline void fill(const T& value = T()) noexcept
		{
			std::uninitialized_fill_n(data, size, value);
		}
	};

	inline const size_t positionToIndex(
		const Vec2<size_t>& position) const noexcept
	{
		return position.x + size.x * position.y;
	}
	inline void indexToPosition(
		const size_t index, size_t& x, size_t& y) const noexcept
	{
		y = index / size.x;
		x = index - y * size.x;
	}
}
