cmake_minimum_required(VERSION 3.5)

project(o3d3xx_framegrabber)

set(CMAKE_INSTALL_LIBDIR lib/o3d3xx_framegrabber)

set(O3D3XX_FRAMEGRABBER_SOURCE_PREFIX ${PROJECT_SOURCE_DIR}/src/libo3d3xx_framegrabber)

set(SOURCE_FILES
        ${O3D3XX_FRAMEGRABBER_SOURCE_PREFIX}/byte_buffer.cpp
        ${O3D3XX_FRAMEGRABBER_SOURCE_PREFIX}/frame_grabber.cpp
        ${O3D3XX_FRAMEGRABBER_SOURCE_PREFIX}/pcic_schema.cpp)

set(O3D3XX_FRAMEGRABBER_HEADER_PREFIX ${PROJECT_SOURCE_DIR}/include/o3d3xx_framegrabber)

set(PUBLIC_HEADERS
        ${O3D3XX_FRAMEGRABBER_HEADER_PREFIX}/byte_buffer.hpp
        ${O3D3XX_FRAMEGRABBER_HEADER_PREFIX}/frame_grabber.h
        ${O3D3XX_FRAMEGRABBER_HEADER_PREFIX}/pcic_schema.h)

find_package(Threads REQUIRED)
find_package(Boost REQUIRED COMPONENTS program_options system)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

#project(${LIBRARY_NAME} LANGUAGES CXX)

#set(O3D3XX_FRAMEGRABBER_INCLUDE_DIRS include)

#include_directories(${O3D3XX_FRAMEGRABBER_INCLUDE_DIRS}
#                    ${O3D3XX_CAMERA_INCLUDE_DIRS})

#link_directories(${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_LIBDIR}
#                ${O3D3XX_FRAMEGRABBER_BINARY_DIR}/lib)

add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES} ${PUBLIC_HEADERS})

target_include_directories(${PROJECT_NAME} PUBLIC 
                        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
                        $<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>)

set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER "${PUBLIC_HEADERS}")

#add_dependencies(${LIBRARY_NAME} O3D3XX_CAMERA)

target_link_libraries(${PROJECT_NAME} o3d3xx_camera)

#target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_INCLUDEDIR}/modules/framegrabber/include)

#install(TARGETS ${LIBRARY_NAME} EXPORT ${LIBRARY_NAME}
#        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
#        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
#        PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${LIBRARY_NAME})
#install(EXPORT ${LIBRARY_NAME} DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${LIBRARY_NAME})

option(BUILD_EXE_HZ "Build o3d3xx-hz" ON)
option(BUILD_EXE_SCHEMA "Build o3d3xx-schema" ON)
add_subdirectory(src)
#add_subdirectory(test)
