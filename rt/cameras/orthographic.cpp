#include <rt/cameras/orthographic.h>
#include <rt/ray.h>
#include <iostream>

using namespace std;

namespace rt {
	
	OrthographicCamera::OrthographicCamera(const Point & center, const Vector & forward, const Vector & up, float scaleX, float scaleY)
		: center(center), forward(forward), up(up), scaleX(scaleX), scaleY(scaleY)
	{
		u = cross(forward, up).normalize();
		v = cross(u, forward).normalize();

		// prepar scaled vectors in advance, to avoid additional operation in forloop
		uScaled = u * (scaleX / 2.0f);
		vScaled = v * (scaleY / 2.0f);
	}

	Ray OrthographicCamera::getPrimaryRay(float x, float y) const
	{
		Point origin = center + x * uScaled + y * vScaled;
		Ray result = Ray(origin, forward);

		return result;
	}

}

