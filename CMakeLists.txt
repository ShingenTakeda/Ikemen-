cmake_minimum_required(VERSION 3.15)
project(Ikemen++)

set(CMAKE_C_STANDARD 11) # Requires C11 standard
set(CMAKE_CXX_STANDARD 17) #Requires C++ 17 standard


find_package(SDL2 CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)
find_package(imguizmo CONFIG REQUIRED)
find_package(implot CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)

include_directories(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/src/)
file(GLOB_RECURSE SIM_SRC "${PROJECT_SOURCE_DIR}/src/*.cpp" 
        "${PROJECT_SOURCE_DIR}/src/*.hpp")
        
add_executable(${PROJECT_NAME} ${SIM_SRC})
        
target_link_libraries(${PROJECT_NAME} PUBLIC -pthread -fpic -lm -ldl -lrt
    PRIVATE
    $<TARGET_NAME_IF_EXISTS:SDL2::SDL2main>
    $<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static>
    glad::glad
    imgui::imgui
    imguizmo::imguizmo
    implot::implot
    glm::glm
)
