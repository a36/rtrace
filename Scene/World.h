#ifndef _WORLD_H
#define _WORLD_H

#include <vector>
#include <memory>

#include <Scene/Object.h>
#include <Image/PPM.h>

// TODO
class World {
public:
    World() = default;
    ~World() = default;

    void render(ppm::Image& to);

    std::vector<Object*>& getObjects() { return m_objects; }

private:
    std::vector<Object*> m_objects;
    // Camera m_camera;
    // linked with m_objects, when Material is in we may use a std::pair
    //std::vector<Material> m_materials;
};

#endif