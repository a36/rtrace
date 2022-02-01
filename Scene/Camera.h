#ifndef _CAMERA_H
#define _CAMERA_H

#include <Math/Vec3.h>
#include <Types.h>

class Camera {
public:
    Camera() = default;
    Camera(const u32 width, const u32 height);
    Camera(const u32 width, const u32 height, f64 fov);
    Camera(const u32 width, const u32 height, f64 fov, Vec3 rotation);
    ~Camera() = default;

    inline const u32 getWidth() const { return m_width; }
    inline const u32 getHeight() const { return m_height; }

    inline const f64 getInvWidth() const { return 1 / f64(m_width); }
    inline const f64 getInvHeight() const { return 1 / f64(m_height); }

    inline const f64 getAspectRatio() const { return m_width / f64(m_height); }
    inline const f64 getAngle() const { return tan(3.14159264358 * 0.5 * m_fov / 180.); } // Could set up a macro or whatever for Pi

private:
    u32 m_width = 256;
    u32 m_height = 256;
    Vec3 m_origin = { 0, 0, 0 }; // Should be defaulted to (0,0,0)
    Vec3 m_rotation = { 0, 0, 0 };
    f64 m_fov = 50;
};

#endif