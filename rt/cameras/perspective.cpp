#include <rt/cameras/perspective.h>
#include <rt/ray.h>
#include <math.h>

namespace rt {


	PerspectiveCamera::PerspectiveCamera(const Point& center, const Vector& forward, const Vector& up, float verticalOpeningAngle, float horizonalOpeningAngle)
		: _center(center), _forward(forward), _up(up), _verticalOpeningAngle(verticalOpeningAngle), _horizonalOpeningAngle(horizonalOpeningAngle)
	{
	}

	Ray PerspectiveCamera::getPrimaryRay(float x, float y) const
	{
		Ray result;
		float a = tan(_horizonalOpeningAngle / 2.0f) * x;
		float b = tan(_verticalOpeningAngle / 2.0f) * y;

		Vector right = cross(_forward, _up);
		Vector cameraUp = cross(right, _forward);

		Vector d = a * right + b * cameraUp + _forward;

		result = Ray(_center, d.normalize());
		return result;
	}

	float lerp(float v0, float v1, float t) {
		return v0 + t * (v1 - v0);
	}
}

