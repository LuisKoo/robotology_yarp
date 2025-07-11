# SPDX-FileCopyrightText: 2006-2021 Istituto Italiano di Tecnologia (IIT)
# SPDX-License-Identifier: BSD-3-Clause

yarp_prepare_plugin(robotDescriptionClient
  CATEGORY device
  TYPE RobotDescriptionClient
  INCLUDE RobotDescriptionClient.h
  GENERATE_PARSER
  DEFAULT ON
)

if(NOT SKIP_robotDescriptionClient)
  yarp_add_plugin(yarp_robotDescriptionClient)

  target_sources(yarp_robotDescriptionClient
    PRIVATE
      RobotDescriptionClient.cpp
      RobotDescriptionClient.h
      RobotDescriptionClient_ParamsParser.cpp
      RobotDescriptionClient_ParamsParser.h
  )

  target_link_libraries(yarp_robotDescriptionClient
    PRIVATE
      YARP::YARP_os
      YARP::YARP_sig
      YARP::YARP_dev
  )
  list(APPEND YARP_${YARP_PLUGIN_MASTER}_PRIVATE_DEPS
    YARP_os
    YARP_sig
    YARP_dev
  )

  target_sources(yarp_robotDescriptionClient PRIVATE $<TARGET_OBJECTS:IRobotDescriptionMsgs>)
  target_include_directories(yarp_robotDescriptionClient PRIVATE $<TARGET_PROPERTY:IRobotDescriptionMsgs,INTERFACE_INCLUDE_DIRECTORIES>)

  yarp_install(
    TARGETS yarp_robotDescriptionClient
    EXPORT YARP_${YARP_PLUGIN_MASTER}
    COMPONENT ${YARP_PLUGIN_MASTER}
    LIBRARY DESTINATION ${YARP_DYNAMIC_PLUGINS_INSTALL_DIR}
    ARCHIVE DESTINATION ${YARP_STATIC_PLUGINS_INSTALL_DIR}
    YARP_INI DESTINATION ${YARP_PLUGIN_MANIFESTS_INSTALL_DIR}
  )

  set(YARP_${YARP_PLUGIN_MASTER}_PRIVATE_DEPS ${YARP_${YARP_PLUGIN_MASTER}_PRIVATE_DEPS} PARENT_SCOPE)

  set_property(TARGET yarp_robotDescriptionClient PROPERTY FOLDER "Plugins/Device")

  if(YARP_COMPILE_TESTS)
    add_subdirectory(tests)
  endif()

endif()
