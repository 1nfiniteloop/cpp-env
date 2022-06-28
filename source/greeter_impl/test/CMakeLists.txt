set(UNITTEST_NAME "${TARGET_NAME}_test")
set(SOURCES
  src/GreeterTest.cc
)
add_executable(${UNITTEST_NAME} ${SOURCES})
add_test(NAME ${UNITTEST_NAME} COMMAND ${UNITTEST_NAME})
add_dependencies(test_all ${UNITTEST_NAME})
target_include_directories(${UNITTEST_NAME}
  PRIVATE ../src
)
target_link_libraries(${UNITTEST_NAME} PRIVATE
  greeter_impl
  GTest::gmock_main
)
