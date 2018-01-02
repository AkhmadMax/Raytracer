#include <rt\integrators\casting.h>
#include <core\color.h>
#include <rt\world.h>
#include <rt\intersection.h>
#include <math.h>
#include <iostream>

namespace rt {
	RGBColor RayCastingIntegrator::getRadiance(const Ray & ray) const
	{
		RGBColor result;

		Intersection intersection = world->scene->intersect(ray, FLT_MAX);
		if (intersection)
		{
			float color = dot(ray.d, intersection._normal);
			color = abs(color);
			//float color = dot(-ray.d, Vector(0, 1, 0));
			//float color = intersection.distance;
			//float color = 1;
			//std::cout << color << std::endl;
			result =  RGBColor(color, color, color);
		}
		else
			result = RGBColor(0.01f, 0.01f, 0.01f);

		return result;
	}
}