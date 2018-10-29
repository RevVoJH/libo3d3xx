################################################
## Build the command-line tools
################################################
option(BUILD_SHARED_LIBS "Build shared libs" ON)
# Empty list
set(O3D3XX_IMAGE_EXE_TARGETS)

find_library(LIB_boost_program_options NAMES boost_program_options)

#-----------------------------------------------
# o3d3xx-viewer
#-----------------------------------------------
if(BUILD_EXE_VIEWER)
  add_executable(o3d3xx-viewer o3d3xx-viewer.cpp)

  target_link_libraries(o3d3xx-viewer o3d3xx_camera o3d3xx_framegrabber o3d3xx_image)

  if(BUILD_SHARED_LIBS)
    target_link_libraries(o3d3xx-viewer
      o3d3xx_image
      o3d3xx_camera
      o3d3xx_framegrabber
      ${PCL_VISUALIZATION_LIBRARIES}
      ${OpenCV_LIBRARIES}
      ${LIB_boost_program_options}
      )
  else()
    target_link_libraries(o3d3xx-viewer
      o3d3xx_image_static
      o3d3xx_camera
      o3d3xx_framegrabber
      ${PCL_VISUALIZATION_LIBRARIES}
      ${OpenCV_LIBRARIES}
      ${LIB_boost_program_options}
      )
  endif(BUILD_SHARED_LIBS)

  set_target_properties(o3d3xx-viewer PROPERTIES
    AUTOMOC TRUE
    COMPILE_FLAGS "-Wno-deprecated"
    )

  install(TARGETS o3d3xx-viewer DESTINATION bin)

  list(APPEND O3D3XX_EXE_TARGETS o3d3xx-viewer)
else()
  message(STATUS "Skipping o3d3xx-viewer")
endif(BUILD_EXE_VIEWER)

#-----------------------------------------------
#-----------------------------------------------
#-----------------------------------------------
if(CMAKE_CROSSCOMPILING)
  foreach(exe_target ${O3D3XX_IMAGE_EXE_TARGETS})
    set_target_properties(${exe_target} PROPERTIES
                          LINK_FLAGS "${CROSSTOOL_EXE_LINKER_FLAGS}"
                          COMPILE_FLAGS "${CROSSTOOL_COMPILE_FLAGS}")
  endforeach(exe_target)
endif(CMAKE_CROSSCOMPILING)
