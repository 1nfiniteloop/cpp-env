cmake_minimum_required(VERSION 3.23)
project(cpp-env
  VERSION ${VERSION}
  DESCRIPTION "Hello world example application written in C++"
  HOMEPAGE_URL "https://github.com/1nfiniteloop/cpp-env"
)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake-module)
set(CMAKE_BUILD_TYPE ${BUILD})
option(UNITTEST "Build unit tests and its dependencies" ON)

# Language-specific settings
add_compile_options(-Wall -Wextra -pedantic -Werror)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS_DEBUG "-ggdb3")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

# DISTRO_ID shall be set from toolchain when cross-compiling
if(NOT DISTRO_ID)
  cmake_host_system_information(RESULT DISTRO_ID QUERY DISTRIB_ID)
endif()

# THIRD_PARTY_ROOT provided from Dockerfile
set(THIRD_PARTY_INSTALL_PREFIX $ENV{THIRD_PARTY_ROOT}/install/${CMAKE_SYSTEM_NAME}-${DISTRO_ID}/${CMAKE_SYSTEM_PROCESSOR})
set(CMAKE_PREFIX_PATH
  ${THIRD_PARTY_INSTALL_PREFIX}/googletest-1.11.0
  ${THIRD_PARTY_INSTALL_PREFIX}/benchmark
  ${THIRD_PARTY_INSTALL_PREFIX}/boost_1_79_0
)

if (UNITTEST)
  include(ImportGTest)
  enable_testing()
  add_custom_target(test_all COMMAND ${CMAKE_CTEST_COMMAND})
endif()

# Third party dependencies:
include(ImportBoost)

# Project components
add_subdirectory(source)

# Package
include(PackageDebian) # or "include(PackageTarGzip)"