#include <rt\solids\disc.h>
#include <rt\bbox.h>
#include <rt\intersection.h>
#include <core\assert.h>

namespace rt {
	Disc::Disc(const Point & center, const Vector & normal, float radius, CoordMapper * texMapper, Material * material) :
		center(center), normal(normal), radius(radius), texMapper(texMapper), material(material)
	{
	}
	BBox Disc::getBounds() const
	{
		NOT_IMPLEMENTED;
	}
	Intersection Disc::intersect(const Ray & ray, float previousBestDistance) const
	{
		Intersection intersection;

		float t = dot(normal, (center - ray.o)) / dot(ray.d, normal);

		Point hitPoint = ray.o + t * ray.d;

		bool withinRadius = false;

		if ((hitPoint - center).lensqr() < sqr(radius))
			withinRadius = true;


		if (t > 0 && t < previousBestDistance && withinRadius)
		{
			intersection.distance = t;
			intersection.solid = this;
			intersection._normal = normal;
			return intersection;
		}

		else
			return intersection.failure();
	}
	Point Disc::sample() const
	{
		return Point();
	}
	float Disc::getArea() const
	{
		return 0.0f;
	}
}