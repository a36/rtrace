#include <Types.h>
#include <iostream>

namespace ppm {
class Pixel {
public:
    Pixel() = default;
    Pixel(const u8 r, const u8 g, const u8 b);
    ~Pixel() = default;

    Pixel& operator=(const u8 other);

    // col must have hex formatting: RRGGBB, E.G. FF0000 (red color)
    void set(const u32 col);
    std::ostream& write(std::ostream& to) const;

    const u8 r() const { return m_r; }
    u8& r() { return m_r; }

    const u8 g() const { return m_g; }
    u8& g() { return m_g; }

    const u8 b() const { return m_b; }
    u8 b() { return m_b; }

    static const Pixel Black;
    static const Pixel White;
    static const Pixel Red;
    static const Pixel Green;
    static const Pixel Blue;

private:
    u8 m_r = 0;
    u8 m_g = 0;
    u8 m_b = 0;
};

} // namespace ppm

std::ostream& operator<<(std::ostream& to, const ppm::Pixel& from);