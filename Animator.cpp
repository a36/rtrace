#include <Animator.h>
#include <filesystem>
#include <fstream>

Animator::Animator(AnimatorValues values)
    : m_objects(m_world.getObjects())
    , m_values(values)
{
    namespace fs = std::filesystem;
    if (!fs::exists("output_frames/")) {
        fs::create_directory("output_frames/");
    }

    generateScene(m_objects);
    generateDirections(m_objects);
}

Animator::~Animator()
{
    for (std::size_t i = 0; i < m_objects.size(); i++) {
        delete m_objects[i];
    }
}

void Animator::run()
{
    ppm::Image image(m_values.m_imageSize.first, m_values.m_imageSize.second);
    Camera camera(m_values.m_imageSize.first, m_values.m_imageSize.second);

    for (u32 i = 0; i < m_values.m_frameCount; i++) {
        m_world.render(image, camera);

        // Output image to out.ppm
        std::ofstream out_ppm("output_frames/frame" + std::to_string(i) + ".ppm");
        if (out_ppm.is_open()) {
            out_ppm << image;
            out_ppm.close();
        }

        std::cout << "Renedered frame " << i << std::endl;

        for (std::size_t j = 0; j < m_objects.size(); j++) {
            m_objects[j]->position() += m_directions[j];
        }

        image.reset();
    }
}

void Animator::generateScene(std::vector<Object*>& objects)
{
    std::uniform_int_distribution<std::mt19937::result_type> objs(m_values.m_objectCount.first, m_values.m_objectCount.second);

    std::uniform_real_distribution<> radius(m_values.m_objectRadius.first, m_values.m_objectRadius.second);
    std::uniform_real_distribution<> posX(m_values.m_objectPosX.first, m_values.m_objectPosX.second);
    std::uniform_real_distribution<> posY(m_values.m_objectPosY.first, m_values.m_objectPosY.second);
    std::uniform_real_distribution<> posZ(m_values.m_objectPosZ.first, m_values.m_objectPosZ.second);

    for (u32 i = 0, objC = objs(m_rng.rng);
         i < objC;
         i++) {
        objects.push_back(
            new SphereObject(radius(m_rng.rng), { posX(m_rng.rng), posY(m_rng.rng), posZ(m_rng.rng) }));
    }
}

void Animator::generateDirections(std::vector<Object*>& objects)
{
    std::uniform_real_distribution<> rngDir(m_values.m_objectSpeed.first, m_values.m_objectSpeed.second);
    Vec3 rDir = { rngDir(m_rng.rng),
        rngDir(m_rng.rng),
        rngDir(m_rng.rng) };

    for (std::size_t i = 0; i < objects.size(); i++) {
        rDir.x() += 0.1f;
        rDir.y() -= 0.1f;
        rDir.z() /= 1.15f;
        m_directions.push_back(rDir);
    }
}
