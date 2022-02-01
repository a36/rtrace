#ifndef _UTIL_COLOR_H
#define _UTIL_COLOR_H

#include <concepts>

#include <Types.h>

namespace util {
template <typename T>
concept ColorType = std::floating_point<T>;

template <ColorType T>
struct Color {
    T m_r = 0;
    T m_g = 0;
    T m_b = 0;

    Color() = default;
    Color(T r, T g, T b)
        : m_r(r)
        , m_g(g)
        , m_b(b)
    {
    }

    ~Color() = default;

    inline Color operator+(const Color& c2)
    {
        return Color(m_r + c2.m_r, m_g + c2.m_g, m_b + c2.m_b);
    }

    inline Color operator*(const T s)
    {
        return Color(m_r * s, m_g * s, m_b * s);
    }

    inline Color operator/(const T s)
    {
        return Color(m_r / s, m_g / s, m_b / s);
    }
};

typedef Color<f32> ColorF;
typedef Color<f64> ColorD;

} // namespace util

#endif
