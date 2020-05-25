#pragma once
#include <voxel/defines.hpp>

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
		Vec3(const Vec3<T>& vector) :
			x(vector.x),
			y(vector.y),
			z(vector.z)
		{}

		inline const Vec3 operator+(const Vec3& other)
		{
			return Vec3(x + other.x, y + other.y, z + other.z);
		}
		inline const Vec3 operator-(const Vec3& other)
		{
			return Vec3(x - other.x, y - other.y, z - other.z);
		}
	};
}