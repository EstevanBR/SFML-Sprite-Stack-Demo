cmake_minimum_required(VERSION 3.0.0)
project(SpriteStack VERSION 0.1.0)

set(SFML_DEMO_SOURCES
    main.cpp
    MyGame.cpp
    MyGame.hpp
    MyStack.cpp
    MyStack.hpp
    DeathZone.hpp
)

add_executable(SpriteStack ${SFML_DEMO_SOURCES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

add_subdirectory(SFML-Engine-2019)

target_link_libraries(SpriteStack LINK_PUBLIC SFML-Engine -lsfml-graphics -lsfml-window -lsfml-system)