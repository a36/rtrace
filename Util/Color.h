#ifndef _COLOR_H
#define _COLOR_H

class Color {
public:
    float m_r, m_g, m_b;

public:
    Color();
    Color(float r, float g, float b);
};

// Add two colors
inline Color operator+(const Color& c1, const Color& c2) {
    return (Color(c1.m_r + c2.m_r, c1.m_g + c2.m_g, c1.m_b + c2.m_b));
}

// Multiply colors by scalar
inline Color operator*(const Color& c1, const float s) {
    return (Color(c1.m_r * s, c1.m_g * s, c1.m_b * s));
}

// Divide colors by float
inline Color operator/(const Color& c1, const float s) {
    return (Color(c1.m_r / s, c1.m_g / s, c1.m_b / s));
}

#endif

