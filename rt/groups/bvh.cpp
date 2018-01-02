#include <rt\groups\bvh.h>
#include <rt\intersection.h>
#include <core\assert.h>

namespace rt {
	BVH::BVH()
	{
	}
	BBox BVH::getBounds() const
	{
		return BBox();
	}
	Intersection BVH::intersect(const Ray & ray, float previousBestDistance) const
	{
		return Intersection();
	}
	void BVH::rebuildIndex()
	{
		
	}
	BVH::~BVH()
	{
	}
	void BVH::add(Primitive * p)
	{
		primitives.push_back(p);
	}
	void BVH::setMaterial(Material * m)
	{
	}
	void BVH::setCoordMapper(CoordMapper * cm)
	{
	}
}


