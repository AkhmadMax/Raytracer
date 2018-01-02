#include "intersection.h"

namespace rt 
{
	Intersection Intersection::failure()
	{
		return Intersection();
	}

	Intersection::Intersection(float distance, const Ray & ray, const Solid * solid, const Vector & normal, const Point & uv)
	{
		solid = NULL;
	}

	Point Intersection::hitPoint() const
	{
		return ray.o + ray.d * distance;
	}

	Vector Intersection::normal() const
	{
		return _normal;
	}

	Intersection::operator bool()
	{
		if (distance > 0)
			return true;
		else
			return false;
	}
}