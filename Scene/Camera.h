#ifndef _CAMERA_H
#define _CAMERA_H

#include <Types.h>
#include <Math/Vec3.h>

class Camera {
public:
    Camera() = default;
    Camera(const u32 width, const u32 height);
    Camera(const u32 width, const u32 height, double fov);
    Camera(const u32 width, const u32 height, double fov, Vec3 rotation);
    ~Camera() = default;

    inline const u32 getWidth() const { return m_width; }
    inline const u32 getHeight() const { return m_height; }

    inline const double getInvWidth() const { return 1 / double(m_width); }
    inline const double getInvHeight() const { return 1 / double(m_height); }

    inline const double getAspectRatio() const { return m_width / double(m_height); }
    inline const double getAngle() const { return tan(3.14159264358 * 0.5 * m_fov / 180.); } // Could set up a macro or whatever for Pi

private:
    u32 m_width = 256; 
    u32 m_height = 256; 
    Vec3 m_origin = { 0, 0, 0 }; // Should be defaulted to (0,0,0)
    Vec3 m_rotation = { 0, 0, 0 };
    double m_fov = 50;
};

#endif