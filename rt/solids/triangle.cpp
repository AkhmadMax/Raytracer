#include <rt\solids\triangle.h>
#include <rt\bbox.h>
#include <rt\intersection.h>

namespace rt {
	Triangle::Triangle(Point vertices[3], CoordMapper * texMapper, Material * material)
	{
	}
	Triangle::Triangle(const Point & v1, const Point & v2, const Point & v3, CoordMapper * texMapper, Material * material)
	{
	}
	BBox Triangle::getBounds() const
	{
		return BBox();
	}
	Intersection Triangle::intersect(const Ray & ray, float previousBestDistance) const
	{
		return Intersection();
	}
	Point Triangle::sample() const
	{
		return Point();
	}
	float Triangle::getArea() const
	{
		return 0.0f;
	}
}