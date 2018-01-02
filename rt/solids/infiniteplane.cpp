#include <rt\solids\infiniteplane.h>
#include <rt\bbox.h>
#include <rt\intersection.h>
#include <core\assert.h>


namespace rt {
	InfinitePlane::InfinitePlane(const Point & origin, const Vector & normal, CoordMapper * texMapper, Material * material)
		: origin(origin), normal(normal), texMapper(texMapper), material(material)
	{
	}
	BBox InfinitePlane::getBounds() const
	{
		NOT_IMPLEMENTED;
	}
	Intersection InfinitePlane::intersect(const Ray & ray, float previousBestDistance) const
	{
		Intersection intersection;

		float t = dot(normal, (origin - ray.o)) / dot(ray.d, normal);

		if (t > 0 && t < previousBestDistance)
		{
			intersection.distance = t;
			intersection.solid = this;
			intersection._normal = normal;
			return intersection;
		}

		else
			return intersection.failure();
	}
	Point InfinitePlane::sample() const
	{
		NOT_IMPLEMENTED;
	}
	float InfinitePlane::getArea() const
	{
		return 0.0f;
	}
}