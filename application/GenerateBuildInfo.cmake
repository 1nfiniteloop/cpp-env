execute_process(
  COMMAND git describe --always --dirty
  WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
  OUTPUT_VARIABLE COMMIT_HASH
  OUTPUT_STRIP_TRAILING_WHITESPACE
)

string(TIMESTAMP BUILD_TIMESTAMP)

configure_file(
  ${CURRENT_SOURCE_DIR}/src/BuildInfo.h.in
  ${CURRENT_BINARY_DIR}/src/BuildInfo.h
)
