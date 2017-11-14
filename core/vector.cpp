#include <core/vector.h>
#include <core/scalar.h>
#include <core/point.h>

namespace rt {

	Vector Vector::operator+(const Vector & b) const
	{
		Vector result;
		result.x = x + b.x;
		result.y = y + b.y;
		result.z = z + b.z;
		return result;
	}

	Vector Vector::operator-(const Vector & b) const
	{
		Vector result;
		result.x = x - b.x;
		result.y = y - b.y;
		result.z = z - b.z;
		return result;
	}

	Vector Vector::operator-() const
	{
		return Vector(-x, -y, -z);
	}

	Vector Vector::normalize() const
	{
		Vector normalized;
		float length = Vector::length();
		normalized.x = x / length;
		normalized.y = y / length;
		normalized.z = z / length;
		return normalized;
	}

	float Vector::lensqr() const
	{
		return x*x + y*y + z*z;
	}

	float Vector::length() const
	{
		return sqrt(x*x + y*y + z*z);
	}

	Vector min(const Vector & a, const Vector & b)
	{
		Vector result;
		result.x = min(a.x, b.x);
		result.y = min(a.y, b.y);
		result.z = min(a.z, b.z);
		return result;
	}

	Vector max(const Vector & a, const Vector & b)
	{
		Vector result;
		result.x = max(a.x, b.x);
		result.y = max(a.y, b.y);
		result.z = max(a.z, b.z);
		return result;
	}

	Vector cross(const Vector & a, const Vector & b)
	{
		Vector result;
		result.x = a.y * b.z - b.y * a.z;
		result.y = a.z * b.x - b.z * a.x;
		result.z = a.x * b.y - b.x * a.y;
		return result;
	}


	float dot(const Vector & a, const Vector & b)
	{
		return a.x * b.x + a.y * b.y + a.z * b.z;
	}

	Point operator+(const Point & a, const Vector & b)
	{
		Point result;
		result.x = a.x + b.x;
		result.y = a.y + b.y;
		result.z = a.z + b.z;
		return result;
	}

	Point operator+(const Vector & a, const Point & b)
	{
		Point result;
		result.x = a.x + b.x;
		result.y = a.y + b.y;
		result.z = a.z + b.z;
		return result;
	}

	Point operator-(const Point & a, const Vector & b)
	{
		Point result;
		result.x = a.x - b.x;
		result.y = a.y - b.y;
		result.z = a.z - b.z;
		return result;
	}

	Vector operator*(const Vector& a, float scalar)
	{
		Vector result;
		result.x = a.x * scalar;
		result.y = a.y * scalar;
		result.z = a.z * scalar;
		return result;
	}

	Vector operator*(float scalar, const Vector& b)
	{
		Vector result;
		result.x = b.x * scalar;
		result.y = b.y * scalar;
		result.z = b.z * scalar;
		return result;
	}

	Point operator*(const Float4 & scale, const Point & p)
	{
		return Point();
	}

}
