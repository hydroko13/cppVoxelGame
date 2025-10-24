#pragma once

#include <iostream>
#include <spdlog/spdlog.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <string>
#include <stdexcept>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/daily_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <memory>
#include <filesystem>
#include <sstream>
#include <fstream>
#include <locale>
#include <codecvt>
#include <random>
#include <stdexcept>
#include "../app/app.h"

namespace gl {
    void loadOpenGL();
}
