cmake_minimum_required(VERSION 3.25)
project(untitled1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/lib/x86_64-linux-gnu/qt5/bin")

find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(untitled1 main.cpp window.cpp window.h rocket.cpp rocket.h engine.cpp engine.h second_window.cpp second_window.h)
target_link_libraries(untitled1
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        )

