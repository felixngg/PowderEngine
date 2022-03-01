cmake_minimum_required(VERSION 3.21)
project(PowderEngine)

set(CMAKE_CXX_STANDARD 17)

find_package(SDL2 CONFIG REQUIRED)
find_package(sdl2-image CONFIG REQUIRED)

set(HEADER_FILES ${CMAKE_CURRENT_SOURCE_DIR}/incl)
set(SOURCE_FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Engine.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/GameObject.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/ControllableObject.cpp)

add_library(
        ${PROJECT_NAME}
        ${SOURCE_FILES})

target_include_directories(${PROJECT_NAME} PUBLIC ${HEADER_FILES})
target_link_libraries(${PROJECT_NAME} PUBLIC  SDL2::SDL2 SDL2::SDL2main SDL2::SDL2_image)
