#include <rt\solids\quad.h>
#include <rt\bbox.h>
#include <rt\intersection.h>
#include <core\assert.h>

namespace rt {
	Quad::Quad(const Point & v1, const Vector & span1, const Vector & span2, CoordMapper * texMapper, Material * material) :
		v1(v1), span1(span1), span2(span2), texMapper(texMapper), material(material)
	{
	}
	BBox Quad::getBounds() const
	{
		NOT_IMPLEMENTED;
	}
	Intersection Quad::intersect(const Ray & ray, float previousBestDistance) const
	{
		Intersection intersection;

		Vector normal = cross(span1, span2).normalize();

		float t = dot(normal, v1 - ray.o) / dot(ray.d, normal);
		
		if (t < 0 || t > previousBestDistance)
			return intersection.failure();
		Point p = ray.o + ray.d * t;

		Vector x = p - v1;
		float projToSpan1 = dot(x, span1) / dot(span1, span1);
		if (projToSpan1 < 0 || projToSpan1 > 1)
			return intersection.failure();
		float projToSpan2 = dot(x, span2) / dot(span2, span2);
		if (projToSpan2 >= 0 && projToSpan2 <= 1)
		{
			intersection.ray = ray;
			intersection.distance = t;
			intersection._normal = normal;
			intersection.solid = this;
			return intersection;
		}
	}
	Point Quad::sample() const
	{
		NOT_IMPLEMENTED;
	}
	float Quad::getArea() const
	{
		return 0.0f;
	}
}