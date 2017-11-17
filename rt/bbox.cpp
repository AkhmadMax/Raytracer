#include <rt/bbox.h>

namespace rt {
	BBox BBox::empty()
	{
		return BBox();
	}
	BBox BBox::full()
	{
		return BBox();
	}
	void BBox::extend(const Point & point)
	{
	}
	void BBox::extend(const BBox & bbox)
	{
	}
	std::pair<float, float> BBox::intersect(const Ray & ray) const
	{
		return std::pair<float, float>();
	}
	bool BBox::isUnbound()
	{
		return false;
	}
}