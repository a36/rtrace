#include <Math/Ray.h>
#include <Scene/SphereObject.h>

SphereObject::SphereObject(f64 r, Vec3 position)
    : m_radius(r)
{
    // Assign base class variable
    m_position = position;
}

bool SphereObject::intersect(Ray& r, f64& t1, f64& t2)
{
    Vec3 oc = m_position - r.getOrigin();

    f64 a = Vec3::dot(oc, r.getDirection());
    if (a < 0)
        return false;

    f64 b = oc.length_squared() - a * a;
    const f64 rSqr = radiusSqr();
    if (b > rSqr)
        return false;

    // Will use c in World.cpp to calculate distance
    f64 c = sqrt(rSqr - b);
    t1 = a - c;
    t2 = a + c;

    // If need be, you can add member variables to the Ray class
    // Given they will be used across all of the objects, so shared values across
    // The calculations

    // Set the reference of the intersection to this object
    r.getIntersection() = this;

    return true;
}
