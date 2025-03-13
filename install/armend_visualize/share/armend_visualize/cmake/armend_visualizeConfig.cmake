# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_armend_visualize_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED armend_visualize_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(armend_visualize_FOUND FALSE)
  elseif(NOT armend_visualize_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(armend_visualize_FOUND FALSE)
  endif()
  return()
endif()
set(_armend_visualize_CONFIG_INCLUDED TRUE)

# output package information
if(NOT armend_visualize_FIND_QUIETLY)
  message(STATUS "Found armend_visualize: 0.0.0 (${armend_visualize_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'armend_visualize' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${armend_visualize_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(armend_visualize_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${armend_visualize_DIR}/${_extra}")
endforeach()
