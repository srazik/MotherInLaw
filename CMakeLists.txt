cmake_minimum_required(VERSION 3.22)
set( CMAKE_TOOLCHAIN_FILE "/usr/local/share/vcpkg/scripts/buildsystems/vcpkg.cmake" )

project(MotherInLaw)

find_package(OpenCV CONFIG REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable(MotherInLaw main.cpp import.cpp export.cpp imageclass.cpp imageclass.h)
target_link_libraries(MotherInLaw ${OpenCV_LIBS})

find_package(Catch2 CONFIG REQUIRED)
add_executable(run_tests imageclass.cpp imageclass.h imageclass_test.cpp)
target_link_libraries(run_tests PRIVATE Catch2::Catch2 Catch2::Catch2WithMain ${OpenCV_LIBS})
