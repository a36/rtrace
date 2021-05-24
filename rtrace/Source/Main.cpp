#include <iostream>
#include <numeric>

#include <Image/PPM.h>

int main(int argc, char** argv)
{
    // Testing image, generates a gradient
    ppm::Image image(256, 256);
    auto& raster = image.getRaster();
    for (auto& row : raster) {
        for (std::size_t j = 0; j < row.size(); j++) {
            // Chop the row up into even numerical distances
            u8 multiplier = static_cast<u8>(row.size() / image.getMaxColorDepth());
            row[j] = multiplier * static_cast<u8>(j);
        }
    }
    image.write(std::cout);

    return EXIT_SUCCESS;
}