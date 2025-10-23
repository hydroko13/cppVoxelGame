#pragma once

#include <iostream>
#include <spdlog/spdlog.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <string>
#include <stdexcept>
#include "window.h"
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <memory>
#include <spdlog/sinks/stdout_color_sinks.h>



namespace app {
    class Application
    {
    private:
        Window window;
        std::shared_ptr<spdlog::logger> console;
        std::shared_ptr<spdlog::logger> err_logger;
        std::string version = "v0.0.1";

    public:
        Application()
        {
            console = spdlog::stderr_color_mt("console");
            err_logger = spdlog::stderr_color_mt("stderr");

            spdlog::get("console")->info("Starting CppVoxelGame " + version );
            spdlog::get("console")->info("Initializing GLFW");

            glfwInit();
            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
            glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
            spdlog::get("console")->info("Creating GLFW window");
            try
            {
                this->window = Window(glm::ivec2(800, 800), glm::ivec2(0, 0), std::string("C++ voxel game"));


                spdlog::get("console")->info("Successfully created GLFW window");
            }
            catch (std::exception &e)
            {
                spdlog::error("Failed to create GLFW window");

                this->terminate();
            }
            
        }

        void terminate() {
            spdlog::critical("Terminating program...");
            std::exit(-1);
        }
    };
}


