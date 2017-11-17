#include <rt\solids\quad.h>
#include <rt\bbox.h>
#include <rt\intersection.h>

namespace rt {
	Quad::Quad(const Point & v1, const Vector & span1, const Vector & span2, CoordMapper * texMapper, Material * material)
	{
	}
	BBox Quad::getBounds() const
	{
		return BBox();
	}
	Intersection Quad::intersect(const Ray & ray, float previousBestDistance) const
	{
		return Intersection();
	}
	Point Quad::sample() const
	{
		return Point();
	}
	float Quad::getArea() const
	{
		return 0.0f;
	}
}