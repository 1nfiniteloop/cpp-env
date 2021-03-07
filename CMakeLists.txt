cmake_minimum_required(VERSION 3.5)
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

# THIRD_PARTY_ROOT is provided from Dockerfile
set(CMAKE_PREFIX_PATH
  $ENV{THIRD_PARTY_ROOT}/install/googletest-1.10.0
  $ENV{THIRD_PARTY_ROOT}/install/benchmark
  $ENV{THIRD_PARTY_ROOT}/install/boost_1_73_0
)

if (UNITTEST)
  include(ImportGTest)
  enable_testing()
  add_custom_target(test_all COMMAND ${CMAKE_CTEST_COMMAND})
endif()

# Third party dependencies:
include(ImportBoost)

# Project components
add_subdirectory(hello_world)
add_subdirectory(hello_world_impl)
add_subdirectory(application)

# Package
include(PackageDebian) # or "include(PackageTarGzip)"