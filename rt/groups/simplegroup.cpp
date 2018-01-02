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
		float bestDistance = previousBestDistance;
		Intersection bestIntersection;
		for (int i = 0; i < primitives.size(); i++)
		{
			Intersection currentIntersection = primitives[i]->intersect(ray, bestDistance);

			if (currentIntersection)
			{
				bestDistance = currentIntersection.distance;
				bestIntersection = currentIntersection;
			}
		}
		return bestIntersection;
	}

	void SimpleGroup::rebuildIndex()
	{
	}

	void SimpleGroup::add(Primitive * p)
	{
		primitives.push_back(p);
	}

	void SimpleGroup::setMaterial(Material * m)
	{
	}

	void SimpleGroup::setCoordMapper(CoordMapper * cm)
	{
	}

}


