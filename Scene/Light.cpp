#include <Scene/Light.h>

Light::Light(const util::ColorF& color, const f32 intensity)
    : m_color(color)
    , m_intensity(intensity)
{
}