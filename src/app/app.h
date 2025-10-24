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
#include <spdlog/sinks/daily_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <memory>
#include <filesystem>
#include <KnownFolders.h>
#include <shlobj_core.h>
#include <Windows.h>
#include <sstream>
#include <fstream>
#include <locale>
#include <codecvt>
#include <uuids.h>
#include <random>








namespace app {
    class Application
    {
    private:
        Window window;
        std::shared_ptr<spdlog::logger> logger;

        std::string version = "v0.0.1";

        std::mt19937 rng1;
        std::mt19937 rng2;


    public:
        Application();

        void terminate();

        

    };
}


