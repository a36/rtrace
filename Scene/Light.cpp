#include <Scene/Light.h>

Light::Light()
{
}

Light::Light(const Color& color, const float intensity)
    : m_color(color)
    , m_intensity(intensity)
{
}

Light::~Light()
{
}

const Color& Light::getColor() const 
{
    return this->m_color;
}

const float& Light::getIntensity() const
{
    return this->m_intensity;
}
