set(SOURCES
  src/Application.cc
)
get_filename_component(TARGET_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
add_library(${TARGET_NAME} OBJECT ${SOURCES})
target_link_libraries(${TARGET_NAME}
  Boost::program_options
  greeter
)
target_include_directories(${TARGET_NAME}
  PRIVATE src ${CMAKE_CURRENT_BINARY_DIR}/src
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
add_dependencies(${TARGET_NAME} generate_buildinfo)