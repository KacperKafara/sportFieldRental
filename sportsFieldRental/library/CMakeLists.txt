cmake_minimum_required(VERSION 3.4)
project(Library)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        src/model/Client.cpp
        include/model/Client.h
        src/model/Address.cpp
        include/model/Address.h
        include/typedefs.h
        src/model/clientTypes/ClientType.cpp
        include/model/clientTypes/ClientType.h
        src/model/clientTypes/School.cpp
        include/model/clientTypes/School.h
        src/model/clientTypes/Club.cpp
        include/model/clientTypes/Club.h
        src/model/clientTypes/League.cpp
        include/model/clientTypes/League.h
        src/model/Field.cpp
        include/model/Field.h
        src/model/Rent.cpp
        include/model/Rent.h
        src/model/clientTypes/LeagueA.cpp
        include/model/clientTypes/LeagueA.h
        src/model/clientTypes/LeagueB.cpp
        include/model/clientTypes/LeagueB.h
        src/model/clientTypes/LeagueC.cpp
        include/model/clientTypes/LeagueC.h
        src/model/clientTypes/LeagueD.cpp
        include/model/clientTypes/LeagueD.h
        src/model/events/Event.cpp
        include/model/events/Event.h
        src/model/events/FriendlyMatch.cpp
        include/model/events/FriendlyMatch.h
        src/model/events/Tournament.cpp
        include/model/events/Tournament.h
        src/model/events/Training.cpp
        include/model/events/Training.h
        include/model/Date.h
        src/model/repositories/ClientRepository.cpp include/model/repositories/ClientRepository.h src/model/repositories/RentRepository.cpp include/model/repositories/RentRepository.h src/model/repositories/FieldRepository.cpp include/model/repositories/FieldRepository.h)

add_library(Library ${SOURCE_FILES})

#add 'include' directory with header files from 'Library' project to paths
target_include_directories(Library PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

#Unit Tests section

# Check if generating Visual Studio 14 2015 project
if(MSVC)
    if(NOT BOOST_ROOT)
        set(BOOST_ROOT "C:/local/boost_1_60_0")
    endif()
    set(Boost_INCLUDE_DIR "${BOOST_ROOT}")
    set(Boost_LIBRARY_DIR "${BOOST_ROOT}/lib32-msvc-14.0")
    set(Boost_USE_STATIC_LIBS ON)
    set(Boost_USE_MULTITHREADED ON)

    if(NOT EXISTS ${Boost_LIBRARY_DIR})
        message(WARNING "Boost library requires manual installation in Windows")
        message("1) Browse: https://sourceforge.net/projects/boost/files/boost-binaries/1.60.0/")
        message("2) Download: boost_1_60_0-msvc-14.0-32.exe")
        message("3) Install into default directory: C:\\local")
        message("")
        message(FATAL_ERROR "Boost libraries not found at ${Boost_LIBRARY_DIR}")
    endif()

    find_package(Boost COMPONENTS unit_test_framework REQUIRED)

    include_directories(${Boost_INCLUDE_DIR})
    link_directories(${Boost_LIBRARY_DIR})

else()
    find_package(Boost COMPONENTS unit_test_framework REQUIRED)
endif()

set(SOURCE_TEST_FILES
        test/master.cpp
        test/ClientTest.cpp
        test/AddressTest.cpp
        test/FieldTest.cpp
        test/EventTest.cpp
        test/RentTest.cpp
        test/DateTest.cpp test/ClientRepositoryTest.cpp test/FieldRepositoryTest.cpp)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${Boost_INCLUDE_DIRS}
)

add_executable (Test ${SOURCE_TEST_FILES})

target_link_libraries (Test
        Library
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
        )

add_custom_target(check ${CMAKE_COMMAND} -E env CTEST_OUTPUT_ON_FAILURE=1 BOOST_TEST_LOG_LEVEL=all
        ${CMAKE_CTEST_COMMAND} -C $<CONFIG> --verbose
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR})

enable_testing()
add_test(LibraryTest Test)