#include <rt\solids\sphere.h>
#include <rt\bbox.h>
#include <rt\intersection.h>
#include <core\assert.h>
#include <algorithm>

namespace rt {

	Sphere::Sphere(const Point & center, float radius, CoordMapper * texMapper, Material * material) :
		center(center), radius(radius), texMapper(texMapper), material(material)
	{

	}
	BBox Sphere::getBounds() const
	{
		BBox bbox;
		bbox.min = Point(center.x - radius, center.y - radius, center.z - radius);
		bbox.max = Point(center.x + radius, center.y + radius, center.z + radius);
		return bbox;
	}
	Intersection Sphere::intersect(const Ray & ray, float previousBestDistance) const
	{
		Intersection intersection;

		float a = dot(ray.d, ray.d);
		float b = 2 * dot(ray.d, (ray.o - center));
		float c = dot((ray.o - center), (ray.o - center)) - sqr(radius);

		float t0, t1;
		
		float d = sqr(b) - 4 * a * c;
		if (d > 0)
		{
			t0 = -(b + sqrt(d)) / (2 * a);
			t1 = -(b - sqrt(d)) / (2 * a);

			if (t0 > t1) std::swap(t0, t1);

			if (t0 < 0)
			{
				t0 = t1;
				if (t0 < 0) return intersection.failure();
			}


			if (t0 < previousBestDistance)
			{
				intersection.ray = ray;
				intersection.distance = t0;
				intersection.solid = this;
				intersection._normal = ((ray.o + ray.d * t0) - center).normalize();

				return intersection;
			}
			else
				return intersection.failure();
		}
		else
			return intersection.failure();

	}
	Point Sphere::sample() const
	{
		NOT_IMPLEMENTED;
	}
	float Sphere::getArea() const
	{
		return 0.0f;
	}
}