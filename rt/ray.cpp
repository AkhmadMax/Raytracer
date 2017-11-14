#include "ray.h"
#include <core/Point.h>


namespace rt {

	Ray::Ray(const Point & o, const Vector & d)
	{
		this->o = o;
		this->d = d;
	}

	Point Ray::getPoint(float distance) const
	{
		Point result;
		result = o + d * distance;
		return result;
	}
}