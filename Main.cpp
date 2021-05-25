#include <iostream>

#include <Scene/World.h>
#include <Scene/SphereObject.h>
#include <Image/PPM.h>

int main(int argc, char** argv)
{    
    // Initialise scene with objects
    World scene;
    auto& objects = scene.getObjects();
    // Add SphereObject
    objects.push_back(
        new SphereObject(5, Vec3(0, 0, 5)) // Sphere with radius 5, and XYZ position (0, 0, 5)
    );

    // Create instance of image creator
    ppm::Image image(256, 256);
    // Render scene to image
    scene.render(image);
    // Output scene
    std::cout << image;

    // Clean up scene
    for (std::size_t i = 0; i < objects.size(); i++)
    {
        delete objects[i];
    }

    return EXIT_SUCCESS;
}