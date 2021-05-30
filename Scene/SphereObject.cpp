#include <Scene/SphereObject.h>

SphereObject::SphereObject(double r, Vec3 position)
    : m_radius(r)
{
    // Assign base class variable
    m_position = position;
}

bool SphereObject::intersect(Ray& r)
{
    Vec3 oc = this->m_position - r.getOrigin(); // Not sure if better way to access m_position
    double a = oc.dot(oc, r.getDirection()); // Not sure if we can call dot without doing oc.dot
    if (a < 0)
        return false;
    double b = oc.dot(oc, oc) - a*a;
    if (b > this->m_radius * this->m_radius) // Just make radius^2 a member variable instead
        return false;
    double c = sqrt(this->m_radius * this->m_radius - b); // Will use c in World.cpp to calculate distance

    return true;
}
