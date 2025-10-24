#include "app.h"






app::Application::Application()
{   
        
    std::random_device rd;
    


    rng1 = std::mt19937(rd()); // USED FOR PROGRAM RANDOMNESS, E.G: LOG FILENAME UUID STRINGS
    rng2 = std::mt19937(rd()); // USED FOR GAME RANDOMNESS
    std::uniform_int_distribution uuidGenerator(65, 90);
    std::uniform_int_distribution boolGen(0, 1);



    if (std::filesystem::exists(std::filesystem::path("data_voxelgame/logs/latest.txt"))) {

        std::stringstream ss;

        for (int i = 0; i < 25; i++) {
            int casing = boolGen(rng1);
            int num = uuidGenerator(rng1);
           
            ss << static_cast<char>(num+(casing*32));

        }

        
        std::string filename = "old_" + ss.str() + ".txt";



        
     
        std::filesystem::rename(std::filesystem::path("data_voxelgame/logs/latest.txt"), std::filesystem::path("data_voxelgame/logs") / std::filesystem::path(filename));
    }
    logger = spdlog::basic_logger_mt("logger", "data_voxelgame/logs/latest.txt");

    spdlog::get("logger")->info("Starting CppVoxelGame " + version);
    spdlog::get("logger")->info("Initializing GLFW");

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    spdlog::get("logger")->info("Creating GLFW window");

    if (!std::filesystem::exists(std::filesystem::path("data_voxelgame"))) {
        std::filesystem::create_directory(std::filesystem::path("data_voxelgame"));
        std::filesystem::create_directory(std::filesystem::path("data_voxelgame/logs"));
        
        std::filesystem::create_directory(std::filesystem::path("data_voxelgame/temp"));
        std::filesystem::create_directory(std::filesystem::path("data_voxelgame/cache"));
        std::filesystem::create_directory(std::filesystem::path("data_voxelgame/glob_data"));
        std::filesystem::create_directory(std::filesystem::path("data_voxelgame/worlds"));



    }   
    

    try
    {
        this->window = Window(glm::ivec2(800, 800), glm::ivec2(0, 0), std::string("C++ voxel game"));


        spdlog::get("logger")->info("Successfully created GLFW window");
    }
    catch (std::exception& e)
    {
        spdlog::get("logger")->error("Failed to create GLFW window");



        this->terminate();
    }

}

void app::Application::terminate() {
    spdlog::get("logger")->critical("Terminating program...");
    std::exit(-1);
}

