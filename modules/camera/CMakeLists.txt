#set(LIBRARY_NAME o3d3xx_camera)
cmake_minimum_required(VERSION 3.5)
project(o3d3xx_camera)
set(CMAKE_INSTALL_LIBDIR lib/o3d3xx_camera)

set(O3D3XX_CAMERA_SOURCE_PREFIX ${PROJECT_SOURCE_DIR}/src/libo3d3xx_camera)

set(SOURCE_FILES
        ${O3D3XX_CAMERA_SOURCE_PREFIX}/app_config.cpp
        ${O3D3XX_CAMERA_SOURCE_PREFIX}/camera.cpp
        ${O3D3XX_CAMERA_SOURCE_PREFIX}/cmdline_opts.cpp
        ${O3D3XX_CAMERA_SOURCE_PREFIX}/device_config.cpp
        ${O3D3XX_CAMERA_SOURCE_PREFIX}/err.cpp
        ${O3D3XX_CAMERA_SOURCE_PREFIX}/imager_config.cpp
        ${O3D3XX_CAMERA_SOURCE_PREFIX}/net_config.cpp
        ${O3D3XX_CAMERA_SOURCE_PREFIX}/spatial_filter_config.cpp
        ${O3D3XX_CAMERA_SOURCE_PREFIX}/temporal_filter_config.cpp
        ${O3D3XX_CAMERA_SOURCE_PREFIX}/util.cpp
        ${O3D3XX_CAMERA_SOURCE_PREFIX}/version.cpp
        )

set(O3D3XX_CAMERA_HEADER_PREFIX ${PROJECT_SOURCE_DIR}/include/o3d3xx_camera)

set(PUBLIC_HEADERS
        ${O3D3XX_CAMERA_HEADER_PREFIX}/app_config.h
        ${O3D3XX_CAMERA_HEADER_PREFIX}/camera.hpp
        ${O3D3XX_CAMERA_HEADER_PREFIX}/cmdline_opts.h
        ${O3D3XX_CAMERA_HEADER_PREFIX}/device_config.h
        ${O3D3XX_CAMERA_HEADER_PREFIX}/err.h
        ${O3D3XX_CAMERA_HEADER_PREFIX}/imager_config.h
        ${O3D3XX_CAMERA_HEADER_PREFIX}/net_config.h
        ${O3D3XX_CAMERA_HEADER_PREFIX}/spatial_filter_config.h
        ${O3D3XX_CAMERA_HEADER_PREFIX}/temporal_filter_config.h
        ${O3D3XX_CAMERA_HEADER_PREFIX}/util.h
        ${O3D3XX_CAMERA_HEADER_PREFIX}/version.h
	${PROJECT_SOURCE_DIR}/include/o3d3xx_camera.h
        )

find_package(XMLRPC REQUIRED c++ libwww-client)
#find_package(XMLRPC REQUIRED c++)
find_package(Boost REQUIRED COMPONENTS program_options system)

#set(O3D3XX_CAMERA_INCLUDE_DIRS include)

#include_directories(${O3D3XX_CAMERA_INCLUDE_DIRS})

add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES} ${PUBLIC_HEADERS})

target_include_directories(${PROJECT_NAME} PUBLIC
                          $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
			  $<INSTALL_INTERFACE:${CMAKE_INSTALL_PREFIX}/include>)

target_include_directories(${PROJECT_NAME} PUBLIC ${XMLRPC_INCLUDE_DIRS} ${Boost_INCLUDE_DIR})
set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER "${PUBLIC_HEADERS}")

#target_include_directories(${PROJECT_NAME} 
#                PUBLIC ${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_INCLUDEDIR}/modules/camera/include
#                PUBLIC ${xmlrpc_INCLUDE_DIRS})
message("woeafjodifjaoweijfaoweijfoadjfpoijwej" ${XMLRPC_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME}
                        ${Boost_LIBRARIES}
#                        xmlrpc++
#                        xmlrpc
#                        xmlrpc_abyss
#                        xmlrpc_client++
#                        xmlrpc_client
#                        xmlrpc_packetsocket
#                        xmlrpc_server
#                        xmlrpc_server++
#                        xmlrpc_server_abyss
#                        xmlrpc_server_abyss++
#                        xmlrpc_server_cgi
#                        xmlrpc_server_cgi++
#                        xmlrpc_server_pstream++
#                        xmlrpc_util
#                        xmlrpc_xmlparse
#                        xmlrpc_xmltok
#			glog
)

option(BUILD_SHARED_LIBS "Build o3d3xx shared" ON)
option(BUILD_EXE_VERSION "Build o3d3xx-version" OFF)
option(BUILD_EXE_RESET "Build o3d3xx-reset" ON)
option(BUILD_EXE_LS "Build o3d3xx-ls" ON)
option(BUILD_EXE_TRACE "Build o3d3xx-trace" ON)
option(BUILD_EXE_DUMP "Build o3d3xx-dump" ON)
option(BUILD_EXE_CONFIG "Build o3d3xx-config" ON)
option(BUILD_EXE_RM "Build o3d3xx-rm" ON)
option(BUILD_EXE_REBOOT "Build o3d3xx-reboot" ON)
option(BUILD_EXE_IMAGER_TYPES "Build o3d3xx-imager-types" ON)
option(BUILD_EXE_IFM_IMPORT "Build o3d3xx-ifm-import" ON)
option(BUILD_EXE_IFM_EXPORT "Build o3d3xx-ifm-export" ON)
add_subdirectory(bin)

#target_include_directories(${LIBRARY_NAME} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/..")

#install(TARGETS ${LIBRARY_NAME} EXPORT ${LIBRARY_NAME}
#        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
#        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
#        PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${LIBRARY_NAME})
#install(EXPORT ${LIBRARY_NAME} DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${LIBRARY_NAME})


