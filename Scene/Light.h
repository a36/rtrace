#ifndef _LIGHT_H
#define _LIGHT_H

#include <Math/Vec3.h>
#include <Util/Color.h>

class Light {
public:
    Light() = default;
    Light(const Color<float>& color, const float intensity);

    virtual ~Light() = default;

    inline auto& getColor() { return m_color; }
    inline const auto& getColor() const { return m_color; }

    inline float& getIntensity() { return m_intensity; }
    inline const float& getIntensity() const { return m_intensity; }

private:
    Color<float> m_color;
    float m_intensity;
};

#endif