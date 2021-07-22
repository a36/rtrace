#include <Image/PPM/Image.h>
#include <Image/PPM/Pixel.h>
#include <iostream>
#include <vector>

std::ostream& operator<<(std::ostream& to, const ppm::Image& image)
{
    return image.write(to);
}

namespace ppm {
Image::Image() { applyResize(); }

Image::Image(const u32 width, const u32 height)
    : m_width(width)
    , m_height(height)
{
    applyResize();
}

void Image::reset()
{
    for (std::size_t i = 0; i < m_raster.size(); i++) {
        for (std::size_t j = 0; j < m_raster[i].size(); j++) {
            m_raster[i][j] = ppm::Pixel::Black;
        }
    }
}

void Image::setPixel(u32 x, u32 y, Pixel p)
{
    m_raster[y][x] = p;
}

std::ostream& Image::write(std::ostream& to) const
{
    // Write header
    to << "P3\n"
       << m_width << " " << m_height << " " << m_maxVal << "\n";

    // Write raster
    for (const std::vector<Pixel>& row : m_raster) {
        for (const Pixel& pixel : row) {
            to << pixel << "\t";
        }
        to << "\n";
    }

    return to;
}

void Image::applyResize()
{
    // Resize to width
    m_raster.resize(m_width);

    // Resize each column to be height size
    for (auto& column : m_raster) {
        column.resize(m_height);
    }
}
} // namespace ppm