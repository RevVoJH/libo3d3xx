#project(O3D3XX)
cmake_minimum_required(VERSION 3.5)

set(CMAKE_DISABLE_SOURCE_CHANGES ON)
set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)

#project(o3d3xx LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_INSTALL_INCLUDEDIR ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(modules)

#add_library(${O3D3XX_LIBRARY_NAME} 
#            SHARED
#            ${O3D3XX_SOURCE_DIR}/modules/camera
#            ${O3D3XX_SOURCE_DIR}/modules/framegrabber
#            ${O3D3XX_SOURCE_DIR}/modules/image
#            ${O3D3XX_SOURCE_DIR}/modules/oem
#            ${O3D3XX_SOURCE_DIR}/modules/pcicclient
#            ${PUBLIC_HEADERS})
