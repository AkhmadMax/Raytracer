#include <core/color.h>
#include <core/macros.h>
#include <algorithm>

namespace rt {

	RGBColor RGBColor::operator+(const RGBColor& c) const
	{
		RGBColor result;
		result.r = r + c.r;
		result.g = g + c.g;
		result.b = b + c.b;
		return result;
	}

	RGBColor RGBColor::operator-(const RGBColor& c) const
	{
		RGBColor result;
		result.r = r - c.r;
		result.g = g - c.g;
		result.b = b - c.b;
		return result;
	}
	RGBColor RGBColor::operator*(const RGBColor& c) const
	{
		RGBColor result;
		result.r = r * c.r;
		result.g = g * c.g;
		result.b = b * c.b;
		return result;
	}
	RGBColor RGBColor::clamp() const
	{
		RGBColor result = RGBColor(r, g, b);
		if (r > 1) result.r = 1;
		if (r < 0) result.r = 0;
		if (g > 1) result.g = 1;
		if (g < 0) result.g = 0;
		if (b > 1) result.b = 1;
		if (b < 0) result.b = 0;
		return result;
	}

	RGBColor operator*(float scalar, const RGBColor& b)
	{
		RGBColor result;
		result.r = scalar * b.r;
		result.g = scalar * b.g;
		result.b = scalar * b.b;
		return result;
	}

	RGBColor operator*(const RGBColor& a, float scalar)
	{
		RGBColor result;
		result.r = scalar * a.r;
		result.g = scalar * a.g;
		result.b = scalar * a.b;
		return result;
	}

	RGBColor operator/(const RGBColor& a, float scalar)
	{
		RGBColor result;
		result.r = a.r / scalar;
		result.g = a.g / scalar;
		result.b = a.b / scalar;
		return result;
	}
}
