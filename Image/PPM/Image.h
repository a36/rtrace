#include <Types.h>
#include <iostream>
#include <vector>

namespace ppm {
class Pixel;

class Image {
public:
    Image();
    Image(const u32 width, const u32 height);
    ~Image() = default;

    void reset();
    void setPixel(u32 x, u32 y, Pixel p);
    std::ostream& write(std::ostream& to) const;

    inline std::vector<std::vector<Pixel>>& getRaster() { return m_raster; }
    inline const std::vector<std::vector<Pixel>>& getRaster() const { return m_raster; }

    inline const u32 getWidth() const { return m_width; }
    inline const u32 getHeight() const { return m_height; }
    inline const u32 getMaxColorDepth() const { return m_maxVal; }

private:
    void applyResize();

    u32 m_width = 256;  // width
    u32 m_height = 256; // height
    u32 m_maxVal = 255; // maximum value color can be

    std::vector<std::vector<Pixel>> m_raster;
};
}

std::ostream& operator<<(std::ostream& to, const ppm::Image& from);