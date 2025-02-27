cmake_minimum_required(VERSION 3.5.0)
project(test VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED on)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

add_executable(test src/main.cpp)

set(CMAKE_TOOLCHAIN_FILE "C:/src/vcpkg/scripts/buildsystems/vcpkg.cmake")

set(CMAKE_PREFIX_PATH "C:/src/vcpkg/installed/x64-windows/" 
                      "C:/opencv/opencv/build" 
                      )
set(Stb_DIR "C:/src/vcpkg/packages/stb_x64-windows/include" )

find_package(Eigen3 CONFIG REQUIRED)
# find_package(OpenCV REQUIRED) 

target_include_directories(test PUBLIC ${Stb_DIR})
include_directories(${OpenCV_INCLUDE_DIRS})

target_link_libraries(test PUBLIC ${CMAKE_SOURCE_DIR}/bin/Debug/algorithm.lib)
# target_link_libraries(test PUBLIC Eigen3::Eigen)
# target_link_libraries(test PUBLIC ${OpenCV_LIBS})

target_include_directories(test PUBLIC ${CMAKE_SOURCE_DIR}/src)

configure_file(${CMAKE_SOURCE_DIR}/picture/bay.jpg ${CMAKE_SOURCE_DIR}/bin/Debug/bay.jpg COPYONLY)
configure_file(${CMAKE_SOURCE_DIR}/picture/lena.jpeg ${CMAKE_SOURCE_DIR}/bin/Debug/lena.jpeg COPYONLY)

install(FILES ${OpenCV_DIR}/x64/vc16/bin/opencv_world4100d.dll DESTINATION ${EXECUTABLE_OUTPUT_PATH}/Debug/)