#include <Scene/World.h>

#include <Scene/Camera.h>
#include <Math/Ray.h>
#include <Image/PPM.h>

void World::render(ppm::Image& to, Camera& camera)
{
    auto& raster = to.getRaster();

    for (u32 i = 0; i < raster.size(); i++) {
        for (u32 j = 0; j < raster[i].size(); j++) {
            // Access using raster[i][j]
            double x = (2 * ((j + 0.5) * camera.getInvWidth())) * camera.getAngle();
            double y = (1 - 2 * ((i + 0.5) * camera.getInvHeight())) * camera.getAngle();
            Vec3 rayDirection = {x, y, -1};
            rayDirection.normalise();
            Ray primaryRay = Ray(rayDirection); // Initialize primary ray

            // We can seperate this code below into another function if we want

            // This would be unoptimized with multiple objects
            // e.g. could spend time drawing objects that are hidden behind other objects
            for (int k = 0; k < m_objects.size(); ++k) {
                double t1 = 0, t2 = 0;
                if (m_objects[k]->intersect(primaryRay, t1, t2)) {
                    ppm::Pixel p = ppm::Pixel(1*(2*t2), 1*(1.5*t1), 0);
                    // to.setPixel(i, j, p);
                    raster[i][j] = p;
                }
            }

        }
    }
}
