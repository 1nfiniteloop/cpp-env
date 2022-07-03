set(LIBRARY_NAME greeter_impl)
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
  PUBLIC greeter
)

if (UNITTEST)
  add_subdirectory(test)
endif()
