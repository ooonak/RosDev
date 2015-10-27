cmake_minimum_required(VERSION 2.8.3)
project(arduino_robot)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  message_generation
)

add_message_files(
  FILES
  # joystick.msg
)

generate_messages(
  DEPENDENCIES
  std_msgs
)

catkin_package(
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(arduino_robot src/arduino_robot.cpp)
target_link_libraries(arduino_robot ${catkin_LIBRARIES})
