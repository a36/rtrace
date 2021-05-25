#ifndef _CAMERA_H
#define _CAMERA_H

#include <Math/Vec3.h>

class Camera {
public:
    Camera() = default;
    Camera(float rotation, float fov);
    ~Camera() = default;

private:
    Vec3 m_origin = { 0, 0, 0 }; // Should be defaulted to (0,0,0)
    float m_rotation = 0; // Shouldn't this be a vec3? (x rot, y rot, z rot)
    float m_fov = 70;
};

#endif