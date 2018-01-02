#include <rt\bbox.h>
#include <rt\ray.h>
#include <core\assert.h>
#include <core\scalar.h>
#include <core\point.h>

namespace rt {

	BBox BBox::empty()
	{
		BBox bbox;
		bbox.min = Point(FLT_MAX, FLT_MAX, FLT_MAX);
		bbox.max = Point(-FLT_MAX, -FLT_MAX, -FLT_MAX);
		return bbox;
	}
	BBox BBox::full()
	{
		BBox bbox;
		bbox.min = Point(-FLT_MAX, -FLT_MAX, -FLT_MAX);
		bbox.max = Point(FLT_MAX, FLT_MAX, FLT_MAX);
		return bbox;
	}
	void BBox::extend(const Point & point)
	{
		min = rt::min(min, point);
		max = rt::max(max, point);
	}
	void BBox::extend(const BBox & bbox)
	{
		min = rt::min(min, bbox.min);
		max = rt::max(max, bbox.max);
	}
	std::pair<float, float> BBox::intersect(const Ray & ray) const
	{
		float x1 = (min.x - ray.o.x) / ray.d.x;
		float x2 = (max.x - ray.o.x) / ray.d.x;
		float y1 = (min.y - ray.o.y) / ray.d.y;
		float y2 = (max.y - ray.o.y) / ray.d.y;
		float z1 = (min.z - ray.o.z) / ray.d.z;
		float z2 = (max.z - ray.o.z) / ray.d.z;

		float xMin = (x1 < x2) ? x1 : x2;
		float xMax = (x1 > x2) ? x1 : x2;

		float yMin = (y1 < y2) ? y1 : y2;
		float yMax = (y1 > y2) ? y1 : y2;

		float zMin = (z1 < z2) ? z1 : z2;
		float zMax = (z1 > z2) ? z1 : z2;
		
		float t0 = std::max(xMin, std::max(yMin, zMin));
		float t1 = std::min(xMax, std::min(yMax, zMax));

		return std::make_pair(0, 0);
	}
	bool BBox::isUnbound()
	{
		return false;
	}
}