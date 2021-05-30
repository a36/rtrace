#include <Scene/World.h>

#include <Math/Ray.h>

void World::render(ppm::Image& to)
{
    // TODO: actual raycasting algorithm with intersections
    // with the objects in the scene
    auto& raster = to.getRaster();
    for (u32 i = 0; i < raster.size(); i++) {
        for (u32 j = 0; j < raster[i].size(); j++) {
            // Chop the row up into even numerical distances
            u8 multiplier = static_cast<u8>(raster[i].size() / to.getMaxColorDepth());
            raster[i][j] = multiplier * static_cast<u8>(j);

            Ray pRay; // Initialize primary ray

            // This would be unoptimized with multiple objects
            // e.g. could spend time drawing objects that are hidden behind other objects
            for (int k = 0; k < m_objects.size(); ++k) {
                if (m_objects[k]->intersect(pRay)) {
                    // Compute minimum distance
                    // float distance;
                }
            }
        }
    }
}
