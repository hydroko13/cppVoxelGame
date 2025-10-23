#include <iostream>
#include "app/window.h"


int main() {


    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    app::Window win(glm::ivec2(100, 100), glm::ivec2(0, 0), std::string("Hello"));




    return 0;
}

