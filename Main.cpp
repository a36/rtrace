#include <iostream>

#include <Scene/World.h>
#include <Scene/SphereObject.h>
#include <Image/PPM.h>
#include <Util/Color.h>

int main(int argc, char** argv)
{    
    World scene;
    std::vector<Object*>& objects = scene.getObjects();
    objects.push_back(
        new SphereObject(5, Vec3(0, 0, 5)) // Sphere with radius 5, and XYZ position (0, 0, 5)
    );

    ppm::Image image(256, 256);
    scene.render(image);
    std::cout << image;

    // Clean up scene, prevent memory leaks
    for (std::size_t i = 0; i < objects.size(); i++)
    {
        delete objects[i];
    }

    return EXIT_SUCCESS;
}