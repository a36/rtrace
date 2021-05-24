#include <Types.h>
#include <iostream>

namespace ppm {
struct Pixel {
    u8 m_r = 0;
    u8 m_g = 0;
    u8 m_b = 0;

    Pixel() = default;
    Pixel(const u8 r, const u8 g, const u8 b);
    ~Pixel() = default;
    
    Pixel& operator=(const u8 other);

    std::ostream& write(std::ostream& to) const;

    static const Pixel Black;
    static const Pixel White;
    static const Pixel Red;
    static const Pixel Green;
    static const Pixel Blue;
};

} // namespace ppm

std::ostream& operator<<(std::ostream& to, const ppm::Pixel& from);