#include <rt\solids\triangle.h>
#include <rt\bbox.h>
#include <rt\intersection.h>
#include <core\assert.h>
#include <main\statistics.h>

namespace rt {
	Triangle::Triangle(Point vertices[3], CoordMapper * texMapper, Material * material) : 
		vertices{vertices[0], vertices[1], vertices[2] }, texMapper(texMapper), material(material)
	{
		Statistics::totalNumTris++;
	}
	Triangle::Triangle(const Point& v1, const Point& v2, const Point& v3, CoordMapper * texMapper, Material * material) :
		vertices{ v1, v2, v3 }, texMapper(texMapper), material(material)
	{
		Statistics::totalNumTris++;
	}

	BBox Triangle::getBounds() const
	{
		BBox bbox;
		bbox.min = min(vertices[0], min(vertices[1], vertices[2]));
		bbox.max = max(vertices[0], max(vertices[1], vertices[2]));
		return bbox;
	}
	Intersection Triangle::intersect(const Ray & ray, float previousBestDistance) const
	{
		Statistics::numRayTrianglesTests++;

		Intersection intersection;

		Point a = vertices[0];
		Point b = vertices[1];
		Point c = vertices[2];

		Vector normal(cross(b - a, c - a).normalize());
		float t = dot(normal, (a - ray.o)) / dot(ray.d, normal);
		
		if (t < 0 || t > previousBestDistance)
			return intersection.failure();


		Point p = ray.o + t * ray.d;

		bool edgeAB = false, edgeBC = false, edgeCA = false;
		// inside-out test
		if (dot(normal, cross(b - a, p - a)) >= 0)
			edgeAB = true;
		else
			return intersection.failure();

		if (dot(normal, cross(c - b, p - b)) >= 0)
			edgeBC = true;
		else
			return intersection.failure();

		if (dot(normal, cross(a - c, p - c)) >= 0)
			edgeCA = true;
		else
			return intersection.failure();


		if (edgeAB & edgeBC & edgeCA)
		{
			intersection.distance = t;
			//intersection.hitPoint = p;
			intersection._normal = normal;
			intersection.ray = ray;
			intersection.solid = this;

			Statistics::numRayTrianglesIsect++;
			return intersection;
		}
		else
			return intersection.failure();
	}
	Point Triangle::sample() const
	{
		NOT_IMPLEMENTED;
	}
	float Triangle::getArea() const
	{
		return 0.0f;
	}
}