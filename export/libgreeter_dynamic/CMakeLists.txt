set(OUTPUT_NAME greeter)

get_filename_component(TARGET_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
add_library(${TARGET_NAME} SHARED)
target_link_libraries(${TARGET_NAME}
  PRIVATE
  greeter_impl
)
set_target_properties(${TARGET_NAME} PROPERTIES
  VERSION 1
  OUTPUT_NAME ${OUTPUT_NAME}
)
install(
  TARGETS ${TARGET_NAME}
  COMPONENT library
)
install(
  TARGETS ${TARGET_NAME}
  COMPONENT library-dev
)
