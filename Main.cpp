#include <Animator.h>

int main(int argc, char** argv)
{
    AnimatorValues values = {
        1,              // Frame rate
        { 1024, 1024}, // Image size

        // Values are as such: Lower limit, upper limit
        { 25, 50 },      // Object Count
        { 0.5f, 25.0f }, // Object Radius

        { -2.5f, 2.5f }, // Object Speed

        // Boundaries of spawned object positions
        { 15, 250 },         // Object Position X
        { -15 * 5, 15 * 2 }, // Object Position Y
        { -500.0f, -50.0f }, // Object Position Z
    };

    Animator animator(values);
    animator.run();

    return EXIT_SUCCESS;
}