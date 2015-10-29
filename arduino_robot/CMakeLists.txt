cmake_minimum_required(VERSION 2.8.3)
project(arduino_robot)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  message_generation
  std_msgs
  #std_srvs
)

add_message_files(
  FILES
  Joystick.msg
  MotorSpeed.msg
  ArmMotors.msg
)

add_service_files(
  #FILES
  #ArmMotors.srv
)

generate_messages(
  DEPENDENCIES
  std_msgs
  #std_srvs
)

catkin_package(
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(arduino_robot src/arduino_robot.cpp)
target_link_libraries(arduino_robot ${catkin_LIBRARIES})
