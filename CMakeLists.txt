cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)




project(voxelGame)

add_executable(voxelGame 
"${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/src/hi/hi.cpp"
)


file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/resourcepacks" DESTINATION "${CMAKE_BINARY_DIR}")


find_package(glfw3 CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)





target_link_libraries(voxelGame glfw)
target_link_libraries(voxelGame glad::glad)
target_link_libraries(voxelGame glm::glm)



