#include <Image/PPM/Pixel.h>

namespace ppm {
const Pixel Pixel::Black = { 0, 0, 0 };
const Pixel Pixel::White = { 255, 255, 255 };
const Pixel Pixel::Red = { 255, 0, 0 };
const Pixel Pixel::Green = { 0, 255, 0 };
const Pixel Pixel::Blue = { 0, 0, 255 };

Pixel::Pixel(const u8 r, const u8 g, const u8 b)
    : m_r(r)
    , m_g(g)
    , m_b(b)

{
}

Pixel& Pixel::operator=(const u8 other)
{
    m_r = m_g = m_b = other;
    return *this;
}

std::ostream& Pixel::write(std::ostream& to) const
{
    to << (u32)m_r << " " << (u32)m_g << " " << (u32)m_b;
    return to;
}
} // namespace ppm

std::ostream& operator<<(std::ostream& to, const ppm::Pixel& from)
{
    return from.write(to);
}
