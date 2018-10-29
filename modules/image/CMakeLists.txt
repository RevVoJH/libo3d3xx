cmake_minimum_required(VERSION 3.5)
project(o3d3xx_image)
set(CMAKE_INSTALL_LIBDIR lib/o3d3xx_image)

option(BUILD_EXE_VIEWER "Build o3d3xx-viewer" ON)

set(O3D3XX_IMAGE_SOURCE_PREFIX ${PROJECT_SOURCE_DIR}/src/libo3d3xx_image)

set(SOURCE_FILES
        ${O3D3XX_IMAGE_SOURCE_PREFIX}/image.cpp)

set(O3D3XX_IMAGE_HEADER_PREFIX ${PROJECT_SOURCE_DIR}/include/o3d3xx_image)

set(PUBLIC_HEADERS
        ${O3D3XX_IMAGE_HEADER_PREFIX}/image.h)

find_package(PCL 1.7 REQUIRED COMPONENTS common visualization)
find_package(Boost REQUIRED COMPONENTS program_options system)
find_package(OpenCV REQUIRED)

add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES} ${PUBLIC_HEADERS})

target_include_directories(${PROJECT_NAME} PUBLIC 
                        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
                        $<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include ${PCL_INCLUDE_DIRS}>)

set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER "${PUBLIC_HEADERS}")

target_link_libraries(${PROJECT_NAME} o3d3xx_framegrabber)

#target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_INCLUDEDIR}/modules/image/include
#                            PUBLIC ${PCL_INCLUDE_DIRS})

include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})
target_link_libraries(${PROJECT_NAME} ${PCL_COMMON_LIBRARIES} ${PCL_VISUALIZATION_LIBRARIES})

add_subdirectory(src)

