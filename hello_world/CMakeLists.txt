set(LIBRARY_NAME hello_world)
add_library(${LIBRARY_NAME} INTERFACE)
target_include_directories(${LIBRARY_NAME}
  INTERFACE inc
)
