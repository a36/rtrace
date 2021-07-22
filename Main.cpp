#include <filesystem>
#include <fstream>
#include <iostream>
#include <random>
#include <string>

#include <Image/PPM.h>
#include <Scene/Camera.h>
#include <Scene/SphereObject.h>
#include <Scene/World.h>
#include <Util/Color.h>

class rtrace_animator {
public:
    rtrace_animator()
        : m_objects(m_world.getObjects())
    {
    }
    ~rtrace_animator() = default;

    void setupScene()
    {
        namespace fs = std::filesystem;
        if (!fs::exists("output_frames/")) {
            fs::create_directory("output_frames/");
        }

        generateScene(m_objects);
        generateDirections(m_objects);
    }

    void run()
    {
        constexpr u32 size = 512;
        ppm::Image image(size, size);
        Camera camera(size, size);

        for (u32 i = 0; i < m_frames; i++) {
            m_world.render(image, camera);

            // Output image to out.ppm
            std::ofstream out_ppm("output_frames/frame" + std::to_string(i) + ".ppm");
            if (out_ppm.is_open()) {
                out_ppm << image;
                out_ppm.close();
            }

            for (std::size_t j = 0; j < m_objects.size(); j++) {
                Vec3& pos = m_objects[j]->position();

                pos[0] += m_directions[j].x() / 2;
                pos[1] += m_directions[j].y() / 2;
                pos[2] += m_directions[j].z() / 2;
            }

            image.reset();
        }

        for (std::size_t i = 0; i < m_objects.size(); i++) {
            delete m_objects[i];
        }
    }

private:
    void generateScene(std::vector<Object*>& objects)
    {
        std::uniform_int_distribution<std::mt19937::result_type> objs(1, 50);

        std::uniform_real_distribution<> radius(1, 3);
        std::uniform_real_distribution<> posX(2.5, 22.5);
        std::uniform_real_distribution<> posY(-5, 5);
        std::uniform_real_distribution<> posZ(-35, -15);

        const u32 objsInScene = objs(m_rng.rng);
        for (u32 i = 0; i < objsInScene; i++) {
            objects.push_back(
                new SphereObject(radius(m_rng.rng), { posX(m_rng.rng), posY(m_rng.rng), posZ(m_rng.rng) }));
        }
    }

    void generateDirections(std::vector<Object*>& objects)
    {
        std::uniform_real_distribution<> rngDir(-1, 1);
        for (std::size_t i = 0; i < objects.size(); i++) {
            m_directions.push_back({ rngDir(m_rng.rng), rngDir(m_rng.rng), rngDir(m_rng.rng) });
        }
    }

    const u32 m_frames = 20;

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
};

int main(int argc, char** argv)
{
    rtrace_animator animator;
    animator.setupScene();
    animator.run();

    return EXIT_SUCCESS;
}