# Remove strings matching given regular expression from a list.
# @param(in,out) aItems Reference of a list variable to filter.
# @param aRegEx Value of regular expression to match.
function (filter_items aItems aRegEx)
    # For each item in our list
    foreach (item ${${aItems}})
        # Check if our items matches our regular expression
        if ("${item}" MATCHES ${aRegEx})
            # Remove current item from our list
            list (REMOVE_ITEM ${aItems} ${item})
        endif ("${item}" MATCHES ${aRegEx})
    endforeach(item)
    # Provide output parameter
    set(${aItems} ${${aItems}} PARENT_SCOPE)
endfunction (filter_items)

cmake_minimum_required(VERSION 3.2.2)
project(Test)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(QT_QMAKE_EXECUTABLE "/usr/local/Cellar/qt/5.10.1/bin/qmake")
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Sql REQUIRED)

set_property(TARGET PROPERTY C_STANDARD 99)

file(GLOB base_H "*.h")
file(GLOB base_SRC "*.cpp")
file(GLOB base_UI "*.ui")
file(GLOB base_REC "*.qrc")
set(SOURCE_FILES_PROD ${base_H} ${base_UI} ${base_SRC} ${base_REC})

add_executable(Test ${SOURCE_FILES_PROD})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")
set_target_properties(Test PROPERTIES COMPILE_FLAGS "-std=c++11 -Wall -Wextra -Werror -W -pedantic -pedantic-errors -O2")
target_link_libraries(Test Qt5::Sql Qt5::Widgets)