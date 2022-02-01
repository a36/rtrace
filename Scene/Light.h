#ifndef _LIGHT_H
#define _LIGHT_H

#include <Math/Vec3.h>
#include <Util/Color.h>

class Light {
public:
    Light() = default;
    Light(const util::ColorF& color, const f32 intensity);

    virtual ~Light() = default;

    inline auto& getColor() { return m_color; }
    inline const auto& getColor() const { return m_color; }

    inline f32& getIntensity() { return m_intensity; }
    inline const f32& getIntensity() const { return m_intensity; }

private:
    util::ColorF m_color;
    f32 m_intensity;
};

#endif