cmake_minimum_required(VERSION 3.22)
if(EXISTS "/opt/vcpkg/scripts/buildsystems/vcpkg.cmake")
    set( CMAKE_TOOLCHAIN_FILE "/opt/vcpkg/scripts/buildsystems/vcpkg.cmake" )
else()
    set( CMAKE_TOOLCHAIN_FILE "/usr/local/share/vcpkg/scripts/buildsystems/vcpkg.cmake" )
endif()

project(MotherInLaw)

find_package(OpenCV CONFIG REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable(MotherInLaw main.cpp imageclass.cpp imageclass.h mathcalculate.cpp mathcalculate.h)
target_link_libraries(MotherInLaw ${OpenCV_LIBS})

find_package(Catch2 CONFIG REQUIRED)
add_executable(run_tests imageclass.cpp imageclass.h imageclass_test.cpp mathcalculate.cpp mathcalculate.h)
target_link_libraries(run_tests PRIVATE Catch2::Catch2 Catch2::Catch2WithMain ${OpenCV_LIBS})
