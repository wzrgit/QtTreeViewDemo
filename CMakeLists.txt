cmake_minimum_required(VERSION 2.8.12)

project(QuickTreeView LANGUAGES CXX)

set(SRC_FILES
"main.cpp"
"qml.qrc"
"treeview_model.h"
"treeview_model.cpp"
"treeview_item.h"
"treeview_item.cpp"
"treeview_filesystem_model.h"
"treeview_filesystem_model.cpp"
    )

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 COMPONENTS Core Quick REQUIRED)

#add_executable(${PROJECT_NAME} "main.cpp" "qml.qrc")
add_executable(${PROJECT_NAME} ${SRC_FILES})

target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Quick)
