cmake_minimum_required(VERSION 3.8)
project(armend_visualize)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(Python3 REQUIRED COMPONENTS Interpreter Development)
find_package(rclcpp REQUIRED)
find_package(mit_msgs REQUIRED)
find_package(xsm_msg REQUIRED)

include_directories(include)
include_directories(include/eigen)
include_directories(include/matplotlib-cpp-master)
include_directories(include/armend_visualize/visualize.hpp)

include_directories(${EIGEN3_INCLUDE_DIR})


set(dependencies
    rclcpp
    std_msgs
    mit_msgs
    xsm_msg
)


add_executable(main src/main.cpp)
ament_target_dependencies(main rclcpp ${dependencies})
target_include_directories( main  PUBLIC include/eigen-3.4.0)
target_include_directories( main PUBLIC include/matplotlib-cpp-master)
target_include_directories( main PUBLIC ${Python3_INCLUDE_DIRS})
target_link_libraries( main ${Python3_LIBRARIES})
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

install(TARGETS
  main
  DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
