
cmake_minimum_required(VERSION 3.20)

project(football_manager)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SFML_DIR "C:/Libraries/SFML/lib/cmake/SFML")

find_package(SFML 3 REQUIRED COMPONENTS
        Graphics
        Window
        System
)

add_executable(football_manager main.cpp)

target_link_libraries(football_manager PRIVATE
        SFML::Graphics
        SFML::Window
        SFML::System
)
