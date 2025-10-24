#include "window.h"



app::Window::Window() {

}
app::Window::Window(glm::ivec2 size, glm::ivec2 pos, std::string title) {
    this->size = size;
    this->pos = pos;
    this->title = title;
    this->window = glfwCreateWindow(this->size.x, this->size.y, title.c_str(), NULL, NULL);

    if (window = NULL)
    {
        throw std::runtime_error("Failed to create GLFW window");
    }


};

void app::Window::makeContextCurrent() {
    glfwMakeContextCurrent(this->window);
}

void app::Window::setPos(glm::ivec2 pos)
{
    this->pos = pos;
}

glm::ivec2 app::Window::getPos()
{
    return this->pos;
}

void app::Window::setSize(glm::ivec2 size)
{
    this->size = size;
}

glm::ivec2 app::Window::getSize()
{
    return this->size;
}

void app::Window::setTitle(std::string title)
{
    this->title = title;
}

std::string app::Window::getTitle()
{
    return this->title;
}
