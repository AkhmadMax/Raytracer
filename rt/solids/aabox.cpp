#include <rt\solids\aabox.h>
#include <rt\bbox.h>
#include <rt\intersection.h>

namespace rt {
	AABox::AABox(const Point & corner1, const Point & corner2, CoordMapper * texMapper, Material * material)
	{
	}
	BBox AABox::getBounds() const
	{
		return BBox();
	}
	Intersection AABox::intersect(const Ray & ray, float previousBestDistance) const
	{
		return Intersection();
	}
	Point AABox::sample() const
	{
		return Point();
	}
	float AABox::getArea() const
	{
		return 0.0f;
	}
}