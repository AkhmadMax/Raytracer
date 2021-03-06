#ifndef CG1RAYTRACER_SOLIDS_DISC_HEADER
#define CG1RAYTRACER_SOLIDS_DISC_HEADER

#include <rt/solids/solid.h>
#include <core/point.h>

namespace rt {

class Disc : public Solid {
public:
//    Disc() {}
    Disc(const Point& center, const Vector& normal, float radius, CoordMapper* texMapper, Material* material);

    virtual BBox getBounds() const;
    virtual Intersection intersect(const Ray& ray, float previousBestDistance=FLT_MAX) const;
    virtual Point sample() const;
    virtual float getArea() const;
private:
	const Point & center;
	const Vector& normal;
	float radius;
	CoordMapper* texMapper;
	Material* material;
};

}


#endif
