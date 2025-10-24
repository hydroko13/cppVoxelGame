#include "gl.h"


void gl::loadOpenGL()
{
    int gladStatus = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    if (gladStatus == 0)
    {
        throw std::runtime_error("Failed to load OpenGL using glad");
    }
}

