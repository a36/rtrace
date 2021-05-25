#ifndef _CAMERA_H
#define _CAMERA_H

#include <Math/Vec3.h>

class Camera {
private:
    Vec3 m_origin; // Should be defaulted to (0,0,0)
    float m_rotation, m_fov;

public:
    Camera();
    Camera(float rotation, float fov);
};

#endif