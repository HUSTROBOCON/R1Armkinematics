cmake_minimum_required(VERSION 3.8)
project(armForwardkinematics)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(pinocchio REQUIRED)
find_package(Eigen3 REQUIRED)
find_package(Boost REQUIRED COMPONENTS python310)
find_package(mit_msgs REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(std_msgs REQUIRED)
find_package(xsm_msg REQUIRED)


include_directories(include)
include_directories(include/pid)

include_directories(${EIGEN3_INCLUDE_DIR} ${PINOCCHIO_INCLUDE_DIRS})


set(ARM_INCLUDE
include
)

set(dependencies
  rclcpp
  std_msgs
  mit_msgs
  xsm_msg
)

set(SOURCES
    source/ForwardkinematicsT/FT_method.cpp
    source/ForwardkinematicsT/zwzmcg.cpp
    source/ForwardkinematicsT/zwzVel.cpp
    source/ForwardkinematicsT/path.cpp
    source/pid.cpp
)

add_executable(pino_armkine_node src/armPino.cpp ${SOURCES})
ament_target_dependencies(pino_armkine_node rclcpp pinocchio ${dependencies})
target_link_libraries(pino_armkine_node ${EIGEN3_LIBRARIES} ${PINOCCHIO_LIBRARIES} ${Boost_LIBRARIES})

# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

install(TARGETS
  pino_armkine_node
  DESTINATION lib/${PROJECT_NAME})

install(DIRECTORY launch
  DESTINATION share/${PROJECT_NAME}
)

# 安装config文件
install(DIRECTORY
  config
  DESTINATION share/${PROJECT_NAME}/
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
