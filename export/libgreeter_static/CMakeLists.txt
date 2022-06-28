set(OUTPUT_NAME greeter)
set(COMPONENT_NAME library-dev)

get_filename_component(TARGET_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
add_library(${TARGET_NAME} STATIC)
target_link_libraries(${TARGET_NAME}
  PRIVATE
  greeter_impl
)
set_target_properties(${TARGET_NAME} PROPERTIES
  OUTPUT_NAME ${OUTPUT_NAME}
)
install(
  TARGETS ${TARGET_NAME}
  COMPONENT ${COMPONENT_NAME}
)
