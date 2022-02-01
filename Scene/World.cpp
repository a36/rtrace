#include <Scene/World.h>

#include <Image/PPM.h>
#include <Math/Ray.h>
#include <Scene/Camera.h>

void World::render(ppm::Image& to, Camera& camera)
{
    auto& raster = to.getRaster();

    for (u32 i = 0; i < camera.getWidth(); i++) {
        for (u32 j = 0; j < camera.getHeight(); j++) {
            // Access using raster[i][j]
            f64 x = (2 * ((j + 0.5) * camera.getInvWidth())) * camera.getAngle();
            f64 y = (1 - 2 * ((i + 0.5) * camera.getInvHeight())) * camera.getAngle();

            Vec3 rayDirection = { x, y, -1 };
            Ray primaryRay = Ray(rayDirection.normalise()); // Initialize primary ray

            // This would be unoptimized with multiple objects
            // e.g. could spend time drawing objects that are hidden behind other objects
            for (int k = 0; k < m_objects.size(); ++k) {
                f64 t1 = 0, t2 = 0;
                if (m_objects[k]->intersect(primaryRay, t1, t2)) {
                    raster[i][j] = ppm::Pixel::fromF32(
                        t1 - (t1 * x),
                        t1 * (y * x * y),
                        t2 / (t1 * x));
                }
            }
        }
    }
}
