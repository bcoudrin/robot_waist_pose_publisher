# Copyright (C) 2011 CNRS
#
# Author: Benjamin Coudrin
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
project(robot_waist_pose_publisher)

#SET(PROJECT_NAME robot_waist_pose_publisher)
#SET(PROJECT_DESCRIPTION "Publish the waist pose of a robot to tf")
#SET(PROJECT_URL "")

find_package(catkin REQUIRED COMPONENTS roscpp rospy std_msgs tf message_generation)

#generate_messages(DEPENDENCIES nav_msgs std_msgs)

catkin_package(
  INCLUDE_DIRS include
#  LIBRARIES vec2odo
  CATKIN_DEPENDS roscpp rospy std_msgs tf message_generation message_runtime
#  DEPENDS system_lib
)
include_directories(${catkin_INCLUDE_DIRS})

ADD_EXECUTABLE(waist_pose_publisher src/robot_waist_pose_publisher.cpp)
target_link_libraries(waist_pose_publisher ${catkin_LIBRARIES})
add_dependencies(waist_pose_publisher waist_pose_publisher_gencpp)

IF(NOT DEFINED CMAKE_INSTALL_LIBDIR)
    SET(CMAKE_INSTALL_LIBDIR ${CMAKE_INSTALL_PREFIX}/share)
ENDIF()
INCLUDE(cmake/GNUInstallDirs.cmake)
SET(CMAKE_INSTALL_FULL_PKGLIBDIR ${CMAKE_INSTALL_FULL_LIBDIR}/${PROJECT_NAME})
SET(CMAKE_INSTALL_PKGLIBDIR ${CMAKE_INSTALL_LIBDIR}/${PROJECT_NAME})

message("Installation dir : " ${CMAKE_INSTALL_PKGLIBDIR})

INSTALL(TARGETS waist_pose_publisher
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CMAKE_INSTALL_PKGLIBDIR}
)

