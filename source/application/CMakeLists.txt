set(EXECUTABLE_NAME application)
set(SOURCES
  src/Application.cc
)
add_executable(${EXECUTABLE_NAME} ${SOURCES})
target_link_libraries(${EXECUTABLE_NAME}
  Boost::program_options
)
target_include_directories(${EXECUTABLE_NAME}
  PRIVATE src ${CMAKE_CURRENT_BINARY_DIR}/src
)
target_link_libraries(${EXECUTABLE_NAME} hello_world_impl)
install(
  TARGETS ${EXECUTABLE_NAME}
  DESTINATION bin
  COMPONENT application
)

add_custom_target(generate_buildinfo
  COMMENT "Generating build info"
  COMMAND ${CMAKE_COMMAND}
    -D PROJECT_VERSION=${PROJECT_VERSION}
    -D PROJECT_SOURCE_DIR=${PROJECT_SOURCE_DIR}
    -D CURRENT_SOURCE_DIR=${CMAKE_CURRENT_SOURCE_DIR}
    -D CURRENT_BINARY_DIR=${CMAKE_CURRENT_BINARY_DIR}
    -P ${CMAKE_CURRENT_SOURCE_DIR}/GenerateBuildInfo.cmake
)
add_dependencies(${EXECUTABLE_NAME} generate_buildinfo)