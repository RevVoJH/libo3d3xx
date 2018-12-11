cmake_minimum_required(VERSION 3.5)
project(o3d3xx_pcicclient)
set(CMAKE_INSTALL_LIBDIR lib/o3d3xx_pcicclient)

set(O3D3XX_PCICCLIENT_SOURCE_PREFIX ${PROJECT_SOURCE_DIR}/src/libo3d3xx_pcicclient)

set(SOURCE_FILES ${O3D3XX_PCICCLIENT_SOURCE_PREFIX}/pcicclient.cpp)

set(O3D3XX_PCICCLIENT_HEADER_PREFIX ${PROJECT_SOURCE_DIR}/include)

set(PUBLIC_HEADERS ${O3D3XX_PCICCLIENT_HEADER_PREFIX}/o3d3xx_pcicclient.h)

#find_package(Threads REQUIRED)
find_package(Boost REQUIRED COMPONENTS program_options system)

add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES} ${PUBLIC_HEADERS})

target_include_directories(${PROJECT_NAME} PUBLIC 
                        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
                        $<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>)

set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER "${PUBLIC_HEADERS}")

target_link_libraries(${PROJECT_NAME} o3d3xx_camera)

#target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_INCLUDEDIR}/modules/pcicclient/include)

