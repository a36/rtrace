#ifndef _ANIMATOR_H
#define _ANIMATOR_H

#include <utility>
#include <vector>
#include <random>

#include <Scene/SphereObject.h>
#include <Scene/World.h>

struct AnimatorValues {
    u32 m_frameCount = 20;
    std::pair<u32, u32> m_imageSize = { 512, 512 };

    // Values are as such: Lower limit, upper limit
    std::pair<u32, u32> m_objectCount = { 1, 15 };
    std::pair<f32, f32> m_objectRadius = { 0.5f, 5.0f };

    std::pair<f32, f32> m_objectSpeed = { -1.0f, 1.0f };

    std::pair<f32, f32> m_objectPosX = { 2.5f, 12.5f };
    std::pair<f32, f32> m_objectPosY = { -7.5f, 7.5f };
    std::pair<f32, f32> m_objectPosZ = { -25.0f, -15.0f };
};

class Animator {
public:
    Animator(AnimatorValues values);
    ~Animator();

    void run();

private:
    void generateScene(std::vector<Object*>& objects);

    void generateDirections(std::vector<Object*>& objects);

    struct RNG_GEN {
        std::random_device device;
        std::mt19937 rng;

        RNG_GEN()
            : rng(device())
        {
        }
    } m_rng;

    World m_world;

    std::vector<Object*>& m_objects;
    std::vector<Vec3> m_directions;

    AnimatorValues m_values;
};

#endif