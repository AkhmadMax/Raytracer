#include <rt/solids/sphere.h>
#include <rt/bbox.h>
#include <rt/intersection.h>

namespace rt {

	Sphere::Sphere(const Point & center, float radius, CoordMapper * texMapper, Material * material)
	{
	}
	BBox Sphere::getBounds() const
	{
		return BBox();
	}
	Intersection Sphere::intersect(const Ray & ray, float previousBestDistance) const
	{
		return Intersection();
	}
	Point Sphere::sample() const
	{
		return Point();
	}
	float Sphere::getArea() const
	{
		return 0.0f;
	}
}