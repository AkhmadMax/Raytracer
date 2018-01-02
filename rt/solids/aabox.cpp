#include <rt\solids\aabox.h>
#include <rt\bbox.h>
#include <rt\intersection.h>
#include <core\vector.h>
#include <core\assert.h>



namespace rt {
	AABox::AABox(const Point & corner1, const Point & corner2, CoordMapper * texMapper, Material * material) :
		corner1(corner1), corner2(corner2), texMapper(texMapper), material(material)
	{
	}
	BBox AABox::getBounds() const
	{
		Point minPoint = Point(min(corner1.x, corner2.x), min(corner1.y, corner2.y), min(corner1.z, corner2.z));
		Point maxPoint = Point(max(corner1.x, corner2.x), max(corner1.y, corner2.y), max(corner1.z, corner2.z));
		return BBox(minPoint, maxPoint);
	}
	Intersection AABox::intersect(const Ray & ray, float previousBestDistance) const
	{
		Intersection intersection;
		
		float x1 = (corner1.x - ray.o.x) / ray.d.x;
		float x2 = (corner2.x - ray.o.x) / ray.d.x;
		float y1 = (corner1.y - ray.o.y) / ray.d.y;
		float y2 = (corner2.y - ray.o.y) / ray.d.y;
		float z1 = (corner1.z - ray.o.z) / ray.d.z;
		float z2 = (corner2.z - ray.o.z) / ray.d.z;
		
		float xMin = (x1 < x2) ? x1 : x2;
		float xMax = (x1 > x2) ? x1 : x2;

		float yMin = (y1 < y2) ? y1 : y2;
		float yMax = (y1 > y2) ? y1 : y2;

		float zMin = (z1 < z2) ? z1 : z2;
		float zMax = (z1 > z2) ? z1 : z2;

		if (max(xMin, yMin, zMin) < min(xMax, yMax, zMax))
		{
			Point hitPoint = ray.o + ray.d * max(xMin, yMin, zMin);
			
			float distance = (hitPoint - ray.o).length();

			intersection.distance = distance;


			if (distance > 0 && distance < previousBestDistance)
			{
				if (max(xMin, yMin, zMin) == x1)
					intersection._normal = ray.d.x > 0 ? Vector(-1, 0, 0) : Vector(1, 0, 0);
				if (max(xMin, yMin, zMin) == y1)
					intersection._normal = ray.d.y > 0 ? Vector(0, -1, 0) : Vector(0, 1, 0);
				if (max(xMin, yMin, zMin) == z1)
					intersection._normal = ray.d.z > 0 ? Vector(0, 0, 1) : Vector(0, 0, -1);


				intersection.solid = this;
				return intersection;
			}
			else
				return intersection.failure();
		}
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