#include <Scene/Light.h>

Light::Light(const Color<float>& color, const float intensity)
    : m_color(color)
    , m_intensity(intensity)
{
}