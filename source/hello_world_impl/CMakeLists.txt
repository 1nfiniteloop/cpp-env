set(LIBRARY_NAME hello_world_impl)
set(SOURCES
  src/FactoryImpl.cc
  src/GreeterImpl.cc
)
add_library(${LIBRARY_NAME} OBJECT ${SOURCES})
target_include_directories(${LIBRARY_NAME}
  PUBLIC inc
  PRIVATE src
)
target_link_libraries(${LIBRARY_NAME}
  PUBLIC hello_world
)

if (UNITTEST)
  add_subdirectory(test)
endif()
