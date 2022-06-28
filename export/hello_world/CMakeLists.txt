set(OUTPUT_NAME hello_world)
set(COMPONENT_NAME application)

get_filename_component(TARGET_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
add_executable(${TARGET_NAME})
target_link_libraries(${TARGET_NAME}
  application
  greeter_impl # or use "libgreeter_dynamic" to link dynamically
)
set_target_properties(${TARGET_NAME} PROPERTIES
  OUTPUT_NAME ${OUTPUT_NAME}
)
install(
  TARGETS ${TARGET_NAME}
  DESTINATION bin
  COMPONENT ${COMPONENT_NAME}
)
