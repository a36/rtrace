#include <iostream>

#include <Scene/World.h>
#include <Scene/Camera.h>
#include <Scene/SphereObject.h>
#include <Image/PPM.h>
#include <Util/Color.h>

int main(int argc, char** argv)
{    
    World scene;
    std::vector<Object*>& objects = scene.getObjects();
    objects.push_back(
        // Camera angle seems a bit buggy right now, SphereObject with coords (0, 0, -10) 
        // should  appear in the center of screen, but instead appears to the left.
        new SphereObject(5, Vec3(7, 0, -17.5)) // Sphere with radius 5, and XYZ position (7, 0, -17.5)
    );

    const u32 width = 256, height = 256;
    ppm::Image image(width, height);
    Camera camera(width, height);

    scene.render(image, camera);

    std::cout << image;

    // Clean up scene, prevent memory leaks
    for (std::size_t i = 0; i < objects.size(); i++)
    {
        delete objects[i];
    }

    return EXIT_SUCCESS;
}