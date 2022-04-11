cmake_minimum_required(VERSION 3.4)
project(Library)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        include/model/Client.h src/model/Client.cpp src/model/Address.cpp include/model/Address.h src/model/Vehicle.cpp include/model/Vehicle.h src/model/Rent.cpp include/model/Rent.h)

add_library(Library ${SOURCE_FILES})

#add 'include' directory with header files from 'Library' project to paths
target_include_directories(Library PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

#Unit Tests section

enable_testing() # dodane wcześniej w punkcie 2

find_package (Boost 1.60.0 COMPONENTS "unit_test_framework" REQUIRED)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${Boost_INCLUDE_DIRS}
)

set(SOURCE_TEST_FILES
        test/master.cpp
        test/ClientTest.cpp test/AddressTest.cpp test/VehicleTest.cpp test/RentTest.cpp) # tu w przyszłości będą dodawane pliki źródłowe testów

add_executable (Test ${SOURCE_TEST_FILES})

#dołącz bibliotekę z testowanymi klasami oraz bibliotekę boost.test do programu testów
target_link_libraries (Test
        Library
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
        )

#dodaj test TestBiblioteki1. Instrukcji cmake add_test może być wiele.
#Dodatkowe parametry wpływają na szczegółowość generowanego raportu. Standardowo znajduje się on w Testing/Temporary.
add_test(LibraryTest Test
        --report_level=detailed
        --log_level=all
        --color_output=yes
        )