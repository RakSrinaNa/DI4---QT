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

set(QT_QMAKE_EXECUTABLE "/usr/local/Cellar/qt/5.10.1/bin/qmake")
find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Sql REQUIRED)

set_property(TARGET PROPERTY C_STANDARD 99)

file(GLOB base_SRC "*.h" "*.cpp")

set(SOURCE_FILES_PROD ${base_SRC})

add_executable(Test ${SOURCE_FILES_PROD})

set_target_properties(Test PROPERTIES COMPILE_FLAGS "-std=c++11 -Wall -Wextra -Werror -W -pedantic -pedantic-errors -O2")
target_link_libraries(helloworld Qt5::Widgets)