#include <rt/cameras/perspective.h>
#include <rt/ray.h>
#include <math.h>

namespace rt {


	PerspectiveCamera::PerspectiveCamera(const Point& center, const Vector& forward, const Vector& up, float verticalOpeningAngle, float horizonalOpeningAngle)
		: center(center), forward(forward), up(up), verticalOpeningAngle(verticalOpeningAngle), horizonalOpeningAngle(horizonalOpeningAngle)
	{
		u = cross(forward, up).normalize();
		v = cross(u, forward).normalize();

		uMult = tan(horizonalOpeningAngle / 2.0f);
		vMult = tan(verticalOpeningAngle / 2.0f);
	}

	Ray PerspectiveCamera::getPrimaryRay(float x, float y) const
	{
		Ray result;
		Vector d = forward + u * uMult * x + v * vMult * y;
		result = Ray(center, d.normalize());
		return result;
	}
}

