
cmake_minimum_required(VERSION 3.10.0)
project(GhostEscape VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)    
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/bin")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}/bin")

set(TARGET ${PROJECT_NAME}-${CMAKE_SYSTEM_NAME})

find_package(SDL3 REQUIRED)
find_package(SDL3_image REQUIRED)
find_package(SDL3_mixer REQUIRED)
find_package(SDL3_ttf REQUIRED)
find_package(glm REQUIRED)

add_executable(${TARGET}
    src/core/affiliate/sprite.cpp
    src/core/affiliate/sprite_anim.cpp
    src/core/affiliate/coilder.cpp
    src/core/object_world.cpp
    src/core/scene.cpp
    src/core/object.cpp
    src/core/actor.cpp
    src/core/asset_store.cpp
    src/core/object_affiliate.cpp
    src/core/game.cpp
    src/scene_main.cpp
    src/enemy.cpp
    src/player.cpp
    src/main.cpp
)

target_link_libraries(${TARGET} PRIVATE
    SDL3::SDL3
    SDL3_image::SDL3_image
    SDL3_mixer::SDL3_mixer
    SDL3_ttf::SDL3_ttf
    glm::glm
)