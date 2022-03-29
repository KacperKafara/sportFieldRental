cmake_minimum_required(VERSION 3.4)
project(Library)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    include/model/Client.h
        src/model/Client.cpp
)

add_library(Library ${SOURCE_FILES})

#add 'include' directory with header files from 'Library' project to paths
target_include_directories(Library PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

#Unit Tests section

enable_testing()

find_package (Boost 1.60.0 COMPONENTS "unit_test_framework" REQUIRED)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${Boost_INCLUDE_DIRS}
)

set(SOURCE_TEST_FILES
        test/ClientTest.cpp
        test/master.cpp)

add_executable (LibraryTest ${SOURCE_TEST_FILES})

target_link_libraries (LibraryTest
        Library
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
        )

add_test(LibraryTest LibraryTest
        --report_level=detailed
        --log_level=all
        --color_output=yes
        )