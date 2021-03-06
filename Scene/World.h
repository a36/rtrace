#ifndef _WORLD_H
#define _WORLD_H

#include <memory>
#include <vector>

#include <Image/PPM.h>
#include <Scene/Camera.h>
#include <Scene/Object.h>

// TODO
class World {
public:
    World() = default;
    ~World() = default;

    void render(ppm::Image& to, Camera& camera);

    inline std::vector<Object*>& getObjects() { return m_objects; }
    inline const std::vector<Object*>& getObjects() const { return m_objects; }

private:
    std::vector<Object*> m_objects;
    // Camera m_camera;
    // linked with m_objects, when Material is in we may use a std::pair
    //std::vector<Material> m_materials;
};

#endif