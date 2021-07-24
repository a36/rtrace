#include <Animator.h>

int main(int argc, char** argv)
{
    AnimatorValues values = {
        20,           // Frame rate
        { 512, 512 }, // Image size

        // Values are as such: Lower limit, upper limit
        { 1, 15 },      // Object Count
        { 0.5f, 5.0f }, // Object Radius

        { -1.0f, 1.0f }, // Object Speed

        // Boundaries of spawned object positions
        { 2.5f, 12.5f },    // Object Position X
        { -7.5f, 7.5f },    // Object Position Y
        { -25.0f, -15.0f }, // Object Position Z
    };

    Animator animator(values);
    animator.run();

    return EXIT_SUCCESS;
}