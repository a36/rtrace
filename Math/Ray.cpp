#include <Math/Ray.h>

Ray::Ray()
    : m_origin(0, 0, 0)
    , m_direction(0, 0, -1)
{
}

Ray::Ray(Vec3 origin, Vec3 direction)
    : m_origin(origin)
    , m_direction(direction)
{
}