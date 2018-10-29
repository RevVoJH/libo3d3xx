cmake_minimum_required(VERSION 3.5)
project(o3d3xx_examples)
set(CMAKE_INSTALL_LIBDIR lib/o3d3xx_examples)

find_package(PCL 1.7.1 REQUIRED COMPONENTS common io)
find_package(OpenCV REQUIRED)
find_package(Boost REQUIRED COMPONENTS program_options system)
find_package(Threads REQUIRED)
find_package(XMLRPC REQUIRED)
find_library(LIB_boost_system NAMES boost_system)

#find_library(o3d3xx_camera REQUIRED)
#find_library(o3d3xx_framegrabber REQUIRED)
#find_library(o3d3xx_image REQUIRED)
#find_library(o3d3xx_pcicclient REQUIRED)

include_directories(
        ${O3D3XX_IMAGE_INCLUDE_DIRS}
        ${O3D3XX_CAMERA_INCLUDE_DIRS}
        ${O3D3XX_FRAMEGRABBER_INCLUDE_DIRS}
        ${PCL_INCLUDE_DIRS}
        ${OpenCV_INCLUDE_DIRS}
        ${XMLRPC_INCLUDE_DIRS}
        )

link_directories(
  ${O3D3XX_IMAGE_LIBRARY_DIR}
  ${O3D3XX_CAMERA_LIBRARY_DIR}
  ${O3D3XX_FRAMEGRABBER_LIBRARY_DIR}
  ${PCL_LIBRARY_DIRS}
  ${OpenCV_LIBRARY_DIRS}
  ${XMLRPC_LIBRARIES}
  )
add_definitions(
  ${PCL_DEFINITIONS}
  ${OpenCV_DEFINITIONS}
  )

################################################
## Build the examples
################################################

add_executable(ex-100k ex-100k.cpp)
target_link_libraries(ex-100k
                      o3d3xx_camera
                      o3d3xx_framegrabber
                      o3d3xx_image
                      ${PCL_COMMON_LIBRARIES}
                      ${OpenCV_LIBRARIES}
                      ${XMLRPC_LIBRARIES}
                      )

target_include_directories(ex-100k 
                PUBLIC ${XMLRPC_INCLUDE_DIRS})

add_executable(ex-cartesian ex-cartesian.cpp)
target_link_libraries(ex-cartesian
                      o3d3xx_camera
                      o3d3xx_framegrabber
                      o3d3xx_image
                      ${OpenCV_LIBRARIES}
                      ${LIB_boost_system}
                      )
add_executable(ex-cartesian_compare ex-cartesian_compare.cpp)
target_link_libraries(ex-cartesian_compare
                      o3d3xx_camera
                      o3d3xx_framegrabber
                      o3d3xx_image
                      ${OpenCV_LIBRARIES}
                      ${PCL_IO_LIBRARIES}
                      ${LIB_boost_system}
                      )

add_executable(ex-file_io ex-file_io.cpp)
target_link_libraries(ex-file_io
                      o3d3xx_camera
                      o3d3xx_framegrabber
                      o3d3xx_image
                      ${PCL_IO_LIBRARIES}
                      ${OpenCV_LIBRARIES}
                      )

add_executable(ex-framegrabber_recycling ex-framegrabber_recycling.cpp)
target_link_libraries(ex-framegrabber_recycling
                      o3d3xx_camera
                      o3d3xx_framegrabber
                      ${LIB_boost_system}
                      )

add_executable(ex-exposure_times ex-exposure_times.cpp)
target_link_libraries(ex-exposure_times
                      o3d3xx_camera
                      o3d3xx_framegrabber
                      o3d3xx_image
                      ${PCL_COMMON_LIBRARIES}
                      ${OpenCV_LIBRARIES}
                      )
add_executable(ex-change_ip ex-change_ip.cpp)
target_link_libraries(ex-change_ip
                      o3d3xx_camera
                      o3d3xx_framegrabber
                      ${LIB_boost_system}
                      )
add_executable(ex-pcicclient_set_io ex-pcicclient_set_io.cpp)
target_link_libraries(ex-pcicclient_set_io
                      o3d3xx_camera
                      o3d3xx_pcicclient
                      ${LIB_boost_system}
                      )

add_executable(ex-pcicclient_async_messages ex-pcicclient_async_messages.cpp)
target_link_libraries(ex-pcicclient_async_messages
                      o3d3xx_camera
                      o3d3xx_pcicclient
                      ${LIB_boost_system}
                      )

add_executable(ex-fast_app_switch ex-fast_app_switch.cpp)
target_link_libraries(ex-fast_app_switch
                      o3d3xx_camera
                      o3d3xx_framegrabber
                      o3d3xx_image
                      o3d3xx_pcicclient
                      ${OpenCV_LIBRARIES}
                      ${LIB_boost_system}
                      )

add_executable(ex-oem_is_booted ex-oem_is_booted.cpp)
target_link_libraries(ex-oem_is_booted
                      o3d3xx_camera
                      )

add_executable(ex-pcic_dos_attack ex-pcic_dos_attack.cpp)
target_link_libraries(ex-pcic_dos_attack
                      o3d3xx_camera
                      o3d3xx_framegrabber
                      o3d3xx_image
                      o3d3xx_pcicclient
                      ${OpenCV_LIBRARIES}
                      ${LIB_boost_system}
                      ${CMAKE_THREAD_LIBS_INIT}
                      )
