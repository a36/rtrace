#include <Scene/Camera.h>

Camera::Camera()
    : m_rotation(0)
    , m_fov(70)
{
}

Camera::Camera(float rotation, float fov)
    : m_rotation(rotation)
    , m_fov(fov)
{
}