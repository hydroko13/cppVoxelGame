#pragma once

#include <iostream>
#include <spdlog/spdlog.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <string>
#include <stdexcept>


namespace app {
	class Window {
		private:
			glm::ivec2 size;
			glm::ivec2 pos;
			std::string title;

			GLFWwindow* window;

		public:
			Window();

			Window(glm::ivec2 size, glm::ivec2 pos, std::string title);

			void setPos(glm::ivec2 pos);

			glm::ivec2 getPos();

			void setSize(glm::ivec2 size);

			glm::ivec2 getSize();

			void setTitle(std::string title);

			std::string getTitle();

			void makeContextCurrent();
	};
}