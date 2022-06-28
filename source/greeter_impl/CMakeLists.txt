set(SOURCES
  src/FactoryImpl.cc
  src/GreeterImpl.cc
)
get_filename_component(TARGET_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
add_library(${TARGET_NAME} OBJECT ${SOURCES})
target_include_directories(${TARGET_NAME}
  PUBLIC inc
  PRIVATE src
)
target_link_libraries(${TARGET_NAME}
  PUBLIC greeter
)
set_target_properties(${TARGET_NAME} PROPERTIES
  POSITION_INDEPENDENT_CODE ON
)
if (UNITTEST)
  add_subdirectory(test)
endif()
