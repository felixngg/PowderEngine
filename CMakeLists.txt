cmake_minimum_required(VERSION 3.21)
project(PowderEngine)

set(CMAKE_CXX_STANDARD 17)

set(THIRD_PARTY ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty)

set(SDL2_INCLUDE_DIRS ${THIRD_PARTY}/sdl2/incl)
set(SDL2_LIBRARIES
        "${THIRD_PARTY}/sdl2/lib/x86/SDL2.lib;"
        "${THIRD_PARTY}/sdl2/lib/x86/SDL2main.lib")
set(SDL2_IMAGE_INCLUDE_DIRS ${THIRD_PARTY}/sdl2-image/incl)
set(SDL2_IMAGE_LIBRARIES ${THIRD_PARTY}/sdl2-image/lib/x86/SDL2_image.lib)

set(HEADER_FILES ${CMAKE_CURRENT_SOURCE_DIR}/incl)
set(SOURCE_FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/src/Engine.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/GameObject.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/ControllableObject.cpp)

add_library(
        ${PROJECT_NAME}
        ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})

target_include_directories(
        ${PROJECT_NAME} PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${SDL2_INCLUDE_DIRS}
        ${SDL2_IMAGE_INCLUDE_DIRS}
        ${HEADER_FILES})

install(TARGETS ${PROJECT_NAME}
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin)

install(FILES
        ${THIRD_PARTY}/sdl2/lib/x86/SDL2.dll
        ${THIRD_PARTY}/sdl2-image/lib/x86/SDL2_image.dll
        DESTINATION
        lib)
