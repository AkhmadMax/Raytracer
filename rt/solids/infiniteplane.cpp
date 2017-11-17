#include <rt\solids\infiniteplane.h>
#include <rt\bbox.h>
#include <rt\intersection.h>


namespace rt {
	InfinitePlane::InfinitePlane(const Point & origin, const Vector & normal, CoordMapper * texMapper, Material * material)
	{
	}
	BBox InfinitePlane::getBounds() const
	{
		return BBox();
	}
	Intersection InfinitePlane::intersect(const Ray & ray, float previousBestDistance) const
	{
		return Intersection();
	}
	Point InfinitePlane::sample() const
	{
		return Point();
	}
	float InfinitePlane::getArea() const
	{
		return 0.0f;
	}
}