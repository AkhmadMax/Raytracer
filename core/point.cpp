#include <core/point.h>
#include <core/vector.h>


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

}

