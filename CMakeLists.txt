cmake_minimum_required(VERSION 3.23)
project(hello_world
  VERSION ${VERSION}
  DESCRIPTION "Hello world example application written in C++"
  HOMEPAGE_URL "https://github.com/1nfiniteloop/cpp-env"
)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake-module)
set(CMAKE_BUILD_TYPE ${BUILD})
option(WITH_UNITTEST "Build unit tests and its dependencies" ON)
if(NOT DEFINED THIRD_PARTY_ROOT)
  message(FATAL_ERROR "THIRD_PARTY_ROOT not set")
endif()

# Language-specific settings
add_compile_options(-Wall -Wextra -pedantic -Werror)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS_DEBUG "-ggdb3")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

# DISTRO_ID shall be set from toolchain when cross-compiling
if(NOT DISTRO_ID)
  cmake_host_system_information(RESULT DISTRO_ID QUERY DISTRIB_ID)
endif()

# Third party dependencies:
set(THIRD_PARTY_INSTALL_PREFIX ${THIRD_PARTY_ROOT}/install/${DISTRO_ID}_${CMAKE_SYSTEM_PROCESSOR})
file(GLOB CMAKE_PREFIX_PATH
  ${THIRD_PARTY_INSTALL_PREFIX}/googletest-*/usr/local
  ${THIRD_PARTY_INSTALL_PREFIX}/boost_*
)
find_package(Boost 1.70 REQUIRED COMPONENTS program_options)

if (WITH_UNITTEST AND NOT CMAKE_CROSSCOMPILING)
  set(UNITTEST TRUE)
  find_package(GTest REQUIRED)
  enable_testing()
  add_custom_target(test_all COMMAND ${CMAKE_CTEST_COMMAND})
endif()

# Project components
add_subdirectory(source)
add_subdirectory(export)

# Package
include(PackageTarGzip) # or "include(PackageDebian)"
