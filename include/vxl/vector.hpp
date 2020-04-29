#pragma once
#include <vector>
#include <stdexcept>

namespace vxl
{
	template<class T, class A = std::allocator<T>>
	class Vector2;
	template<class T, class A = std::allocator<T>>
	class Vector3;

	template<class T, class A = std::allocator<T>>
	class Vector2
	{
	protected:
		size_t m_sizeX;
		size_t m_sizeY;

		std::vector<T, A> m_vector;
	public:
		Vector2(const size_t sizeX, const size_t sizeY, const std::vector<T, A>& vector) :
			m_sizeX(sizeX),
			m_sizeY(sizeY),
			m_vector(vector)
		{
			if (vector.size() != sizeX * sizeY)
				throw std::runtime_error("Incorrect vector size");
		}
		Vector2(const size_t sizeX, const size_t sizeY, const T& value = T()) :
			m_sizeX(sizeX),
			m_sizeY(sizeY),
			m_vector(sizeX * sizeY, value)
		{}
		Vector2(const size_t sizeXY, const T& value = T()) :
			m_sizeX(sizeXY),
			m_sizeY(sizeXY),
			m_vector(sizeXY * sizeXY, value)
		{}

		inline size_t size() const noexcept
		{
			return m_vector.size();
		}
		inline size_t sizeX() const noexcept
		{
			return m_sizeX;
		}
		inline size_t sizeY() const noexcept
		{
			return m_sizeY;
		}

		inline void resize(const size_t sizeX, const size_t sizeY)
		{
			m_vector.resize(sizeX * sizeY);
			m_sizeX = sizeX;
			m_sizeY = sizeY;
		}
		inline void resize(const size_t sizeX, const size_t sizeY, const T& value)
		{
			m_vector.resize(sizeX * sizeY, value);
			m_sizeX = sizeX;
			m_sizeY = sizeY;
		}
		inline void resize(const size_t sizeXY)
		{
			m_vector.resize(sizeXY * sizeXY);
			m_sizeX = sizeXY;
			m_sizeY = sizeXY;
		}
		inline void resize(const size_t sizeXY, const T& value)
		{
			m_vector.resize(sizeXY * sizeXY, value);
			m_sizeX = sizeXY;
			m_sizeY = sizeXY;
		}

		inline T& at(const size_t position)
		{
			return m_vector.at(position);
		}
		inline const T& at(const size_t position) const
		{
			return m_vector.at(position);
		}

		inline T& at(const size_t x, const size_t y)
		{
			return m_vector.at(x + y * m_sizeX);
		}
		inline const T& at(const size_t x, const size_t y) const
		{
			return m_vector.at(x + y * m_sizeX);
		}

		inline T& atUnsafe(const size_t position) noexcept
		{
			return m_vector[position];
		}
		inline const T& atUnsafe(const size_t position) const noexcept
		{
			return m_vector[position];
		}

		inline T& atUnsafe(const size_t x, const size_t y)  noexcept
		{
			return m_vector[x + y * m_sizeX];
		}
		inline const T& atUnsafe(const size_t x, const size_t y) const noexcept
		{
			return m_vector[x + y * m_sizeX];
		}

		inline  T* data() noexcept
		{
			return m_vector.data();
		}
		inline const T* data() const noexcept
		{
			return m_vector.data();
		}

		inline  std::vector<T, A>& vector() noexcept
		{
			return m_vector;
		}
		inline const std::vector<T, A>& vector() const noexcept
		{
			return m_vector;
		}
	};

	template<class T, class A = std::allocator<T>>
	class Vector3
	{
	protected:
		size_t m_sizeX;
		size_t m_sizeY;
		size_t m_sizeZ;
		size_t m_sizeXY;

		std::vector<T, A> m_vector;
	public:
		Vector3(const size_t sizeX, const size_t sizeY, const size_t sizeZ, const std::vector<T, A>& vector) :
			m_sizeX(sizeX),
			m_sizeY(sizeY),
			m_sizeZ(sizeZ),
			m_sizeXY(sizeX * sizeY),
			m_vector(vector)
		{
			if (vector.size() != sizeX * sizeY * sizeZ)
				throw std::runtime_error("Incorrect vector size");
		}
		Vector3(const size_t sizeX, const size_t sizeY, const size_t sizeZ, const T& value = T()) :
			m_sizeX(sizeX),
			m_sizeY(sizeY),
			m_sizeZ(sizeZ),
			m_sizeXY(sizeX * sizeY),
			m_vector(sizeX * sizeY * sizeZ, value)
		{}
		Vector3(const size_t sizeXYZ, const T& value = T()) :
			m_sizeX(sizeXYZ),
			m_sizeY(sizeXYZ),
			m_sizeZ(sizeXYZ),
			m_sizeXY(sizeXYZ * sizeXYZ),
			m_vector(sizeXYZ * sizeXYZ * sizeXYZ, value)
		{}

		inline size_t size() const noexcept
		{
			return m_vector.size();
		}
		inline size_t sizeX() const noexcept
		{
			return m_sizeX;
		}
		inline size_t sizeY() const noexcept
		{
			return m_sizeY;
		}
		inline size_t sizeZ() const noexcept
		{
			return m_sizeZ;
		}
		inline size_t sizeXY() const noexcept
		{
			return m_sizeXY;
		}

		inline void resize(const size_t sizeX, const size_t sizeY, const size_t sizeZ)
		{
			m_vector.resize(sizeX * sizeY * sizeZ);
			m_sizeX = sizeX;
			m_sizeY = sizeY;
			m_sizeZ = sizeZ;
			m_sizeXY = sizeX * sizeY;
		}
		inline void resize(const size_t sizeX, const size_t sizeY, const size_t sizeZ, const T& value)
		{
			m_vector.resize(sizeX * sizeY * sizeZ, value);
			m_sizeX = sizeX;
			m_sizeY = sizeY;
			m_sizeZ = sizeZ;
			m_sizeXY = sizeX * sizeY;
		}
		inline void resize(const size_t sizeXYZ)
		{
			m_vector.resize(sizeXYZ * sizeXYZ * sizeXYZ);
			m_sizeX = sizeXYZ;
			m_sizeY = sizeXYZ;
			m_sizeZ = sizeXYZ;
			m_sizeXY = sizeXYZ * sizeXYZ;
		}
		inline void resize(const size_t sizeXYZ, const T& value)
		{
			m_vector.resize(sizeXYZ * sizeXYZ * sizeXYZ, value);
			m_sizeX = sizeXYZ;
			m_sizeY = sizeXYZ;
			m_sizeZ = sizeXYZ;
			m_sizeXY = sizeXYZ * sizeXYZ;
		}

		inline T& at(const size_t position)
		{
			return m_vector.at(position);
		}
		inline const T& at(const size_t position) const
		{
			return m_vector.at(position);
		}

		inline T& at(const size_t x, const size_t y, const size_t z)
		{
			return m_vector.at(x + y * m_sizeX + z * m_sizeXY);
		}
		inline const T& at(const size_t x, const size_t y, const size_t z) const
		{
			return m_vector.at(x + y * m_sizeX + z * m_sizeXY);
		}

		inline T& atUnsafe(const size_t position) noexcept
		{
			return m_vector[position];
		}
		inline const T& atUnsafe(const size_t position) const noexcept
		{
			return m_vector[position];
		}

		inline T& atUnsafe(const size_t x, const size_t y, const size_t z)  noexcept
		{
			return m_vector[x + y * m_sizeX + z * m_sizeXY];
		}
		inline const T& atUnsafe(const size_t x, const size_t y, const size_t z) const noexcept
		{
			return m_vector[x + y * m_sizeX + z * m_sizeXY];
		}

		inline T* data() noexcept
		{
			return m_vector.data();
		}
		inline const T* data() const noexcept
		{
			return m_vector.data();
		}

		inline std::vector<T, A>& vector() noexcept
		{
			return m_vector;
		}
		inline const std::vector<T, A>& vector() const noexcept
		{
			return m_vector;
		}
	};
}
