#include <core/point.h>
#include <core/vector.h>
#include <core/scalar.h>

namespace rt {

	Vector Point::operator-(const Point & b) const
	{
		Vector result;
		result.x = x - b.x;
		result.y = y - b.y;
		result.z = z - b.z;
		return result;
	}

	Point operator*(float scalar, const Point & b)
	{
		Point result;
		result.x = scalar * b.x;
		result.y = scalar * b.y;
		result.z = scalar * b.z;
		return result;
	}

	Point operator*(const Point & a, float scalar)
	{
		Point result;
		result.x = scalar * a.x;
		result.y = scalar * a.y;
		result.z = scalar * a.z;
		return result;
	}

	Point min(const Point & a, const Point & b)
	{
		Point result;
		result.x = min(a.x, b.x);
		result.y = min(a.y, b.y);
		result.z = min(a.z, b.z);
		return result;
	}

	Point max(const Point & a, const Point & b)
	{
		Point result;
		result.x = max(a.x, b.x);
		result.y = max(a.y, b.y);
		result.z = max(a.z, b.z);
		return result;
	}
}


