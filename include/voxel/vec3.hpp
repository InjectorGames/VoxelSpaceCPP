#pragma once

#if !defined(VOXEL_NAMESPACE)
#define VOXEL_NAMESPACE voxel
#endif

namespace VOXEL_NAMESPACE
{
	template<class T>
	struct Vec3
	{
		T x;
		T y;
		T z;

		Vec3(const T _x = T(),
			const T _y = T(),
			const T _z = T()) :
			x(_x),
			y(_y),
			z(_z)
		{}

		inline const Vec3 operator+(const Vec3<T>& other) const noexcept
		{
			return Vec3(x + other.x, y + other.y, z + other.z);
		}
		inline const Vec3 operator-(const Vec3<T>& other) const noexcept
		{
			return Vec3(x - other.x, y - other.y, z - other.z);
		}
		inline const bool operator<(const Vec3<T>& other) const noexcept
		{
			if (x < other.x) return true;
			if (x > other.x) return false;
			if (y < other.y) return true;
			if (y > other.y) return false;
			if (z < other.z) return true;
			if (z > other.z) return false;
			return false;
		}
		inline const bool operator>(const Vec3<T>& other) const noexcept
		{
			if (x > other.x) return true;
			if (x < other.x) return false;
			if (y > other.y) return true;
			if (y < other.y) return false;
			if (z > other.z) return true;
			if (z < other.z) return false;
			return false;
		}
		inline const bool operator==(const Vec3<T>& other) const noexcept
		{
			return x == other.x && y == other.y && z == other.z;
		}
		inline const bool operator!=(const Vec3<T>& other)  const noexcept
		{
			return x != other.x && y != other.y && z != other.z;
		}
	};

	template<class T, class R = float>
	inline static R distance(const Vec3<T>& a, const Vec3<T>& b) noexcept
	{
		return std::sqrt(static_cast<R>(
			(b.x - a.x) * (b.x - a.x) +
			(b.y - a.y) * (b.y - a.y) +
			(b.z - a.z) * (b.z - a.z)));
	}
}