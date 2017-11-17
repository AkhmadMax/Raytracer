#include <rt/groups/simplegroup.h>
#include <rt/bbox.h>
#include <rt/intersection.h>

namespace rt {

	BBox rt::SimpleGroup::getBounds() const
	{
		return BBox();
	}

	Intersection SimpleGroup::intersect(const Ray & ray, float previousBestDistance) const
	{
		return Intersection();
	}

	void SimpleGroup::rebuildIndex()
	{
	}

	void SimpleGroup::add(Primitive * p)
	{
	}

	void SimpleGroup::setMaterial(Material * m)
	{
	}

	void SimpleGroup::setCoordMapper(CoordMapper * cm)
	{
	}

}


