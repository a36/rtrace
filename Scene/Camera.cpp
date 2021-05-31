#include <Scene/Camera.h>

Camera::Camera(const u32 width, const u32 height)
    : m_width(width)
    , m_height(height)
{
}

Camera::Camera(const u32 width, const u32 height, double fov)
    : m_width(width)
    , m_height(height)
    , m_fov(fov)
{
}

Camera::Camera(const u32 width, const u32 height, double fov, Vec3 rotation)
    : m_width(width)
    , m_height(height)
    , m_fov(fov)
    , m_rotation(rotation)
{
}
