#include <rt\solids\disc.h>
#include <rt\bbox.h>
#include <rt\intersection.h>

namespace rt {
	Disc::Disc(const Point & center, const Vector & normal, float radius, CoordMapper * texMapper, Material * material)
	{
	}
	BBox Disc::getBounds() const
	{
		return BBox();
	}
	Intersection Disc::intersect(const Ray & ray, float previousBestDistance) const
	{
		return Intersection();
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