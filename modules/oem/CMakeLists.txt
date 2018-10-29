cmake_minimum_required(VERSION 3.5)

project(o3d3xx_oem)

set(CMAKE_INSTALL_LIBDIR lib/o3d3xx_oem)

set(O3D3XX_OEM_SOURCE_PREFIX ${PROJECT_SOURCE_DIR}/src/libo3d3xx_oem)

set(SOURCE_FILES
        ${O3D3XX_OEM_SOURCE_PREFIX}/frame_grabber.cpp
        ${O3D3XX_OEM_SOURCE_PREFIX}/image_buffer.cpp)

set(O3D3XX_OEM_HEADER_PREFIX ${PROJECT_SOURCE_DIR}/include/o3d3xx_oem)

set(PUBLIC_HEADERS
        ${O3D3XX_OEM_HEADER_PREFIX}/frame_grabber.h
        ${O3D3XX_OEM_HEADER_PREFIX}/image_buffer.h)

find_package(Threads REQUIRED)
find_package(PCL 1.7 REQUIRED COMPONENTS common)
find_package(resultsync 0.2 REQUIRED)
find_package(OpenCV 3 REQUIRED)

add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES} ${PUBLIC_HEADERS})

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)

set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER "${PUBLIC_HEADERS}")

target_link_libraries(${PROJECT_NAME} o3d3xx_camera o3d3xx_framegrabber o3d3xx_image)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_INCLUDEDIR}/modules/oem/include)

include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})
target_link_libraries(${PROJECT_NAME} ${PCL_COMMON_LIBRARIES})
