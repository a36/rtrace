#ifndef _LIGHT_H
#define _LIGHT_H

#include <Math/Vec3.h>
#include <Util/Color.h>

class Light {
private:
    Color m_color;
    float m_intensity;

public:
    Light();
    Light(const Color& color, const float intensity);

    virtual ~Light();

    const Color& getColor() const;
    const float& getIntensity() const;
};

#endif