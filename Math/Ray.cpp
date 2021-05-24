#include <Math/Ray.h>

Ray::Ray()
{
}

Ray::Ray(Vec3 origin, Vec3 direction)
    : m_origin(origin)
    , m_direction(direction)
{
}