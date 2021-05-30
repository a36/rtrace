#include <Scene/SphereObject.h>
#include <Math/Ray.h>

SphereObject::SphereObject(double r, Vec3 position)
    : m_radius(r)
{
    // Assign base class variable
    m_position = position;
}

bool SphereObject::intersect(Ray& r, double& t1, double& t2)
{
    Vec3 oc = m_position - r.getOrigin();

    double a = Vec3::dot(oc, r.getDirection());
    if (a < 0)
        return false;

    double b = Vec3::dot(oc, oc) - a*a;
    if (b > radiusSqr())
        return false;

    // Will use c in World.cpp to calculate distance
    double c = sqrt(m_radius * m_radius - b);
    t1 = a - c;
    t2 = a + c;

    // If need be, you can add member variables to the Ray class
    // Given they will be used across all of the objects, so shared values across
    // The calculations
    
    // Set the reference of the intersection to this object
    r.getIntersection() = this;

    return true;
}
