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
			
			Window(glm::ivec2 size, glm::ivec2 pos, std::string title) {
				this->size = size;
				this->pos = pos;
				this->title = title;
				this->window = glfwCreateWindow(this->size.x, this->size.y, title.c_str(), NULL, NULL);

				if (window == NULL) {
					throw std::runtime_error("Failed to create GLFW window");
				}


			};



			void setPos(glm::ivec2 pos) {
				this->pos = pos;
			}

			glm::ivec2 getPos() {
				return this->pos;
			}

			void setSize(glm::ivec2 size) {
				this->size = size;
			}

			glm::ivec2 getSize() {
				return this->size;
			}

			void setTitle(std::string title) {
				this->title = title;
			}

			std::string getTitle() {
				return this->title;
			}



	};
}