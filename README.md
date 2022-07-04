# C++ development environment

Start developing a project in C++ means setting the bar a bit higher than usual.
Because the C++ toolchain has no support for package managment. It also requires
extensive build environment configuration before the application development can
begin. This requires knowledge, patience and time.

The intention with this development environment is to give new projects
a basic setup and structure to build upon, that also scales well as
the project grows.

## Overview

The build-environment is based on a portable docker-container including all
basic tools needed, see more in `.devcontainer/${DIST}/Dockerfile`. No further
package installations is required, the only prerequisite is that Docker is
installed.

## Visual Studio Code

Visual Studio Code (VS Code) together with the plugin
_"ms-vscode-remote.remote-containers"_ makes it very convenient to have the
development environment inside a container, see more @
<https://code.visualstudio.com/docs/remote/containers>. To setup the development
environment simply open this project in VS Code. A notification with an option
to open this project inside the container will appear. Recommended VS Code
extensions will also be installed and set-up accordingly, see more in
`.devcontainer/devcontainer.json`.

## Install dependencies

Install dependencies with `./install-dependencies gtest boost [...]`.

Note: This shall be run from inside the container. The dependencies is cached
on a docker volume under `~/third_party`.

## Build

1. Create build tree with `mkdir --parents build/{Debug,Release}`

2. Build _Debug_ and run tests:

         cd build/Debug \
          && cmake \
             -D VERSION=1.0.0 \
             -D BUILD=Debug \
             ../../ \
          && make test_all

3. Build _Release_ and make package:

        cd build/Release \
          && cmake \
             -D VERSION=1.0.0 \
             -D BUILD=Release \
             -D WITH_UNITTEST=OFF \
             ../../ \
          && make package

### Code formatting

The repository contains `.clang-format` and `.clang-tidy` to control code
formatting. Invoke "Format document" in VS Code or run manually to format files:

    find source -iname '*.h' -o -iname '*.cpp' -o -iname '*.cc' \
      |xargs clang-format -i

To format function -and variable names, run:

    run-clang-tidy -fix -header-filter=.* source

__Note:__ clang-tidy requires the compilation database `compile_commands.json`
to be available. CMake creates this file in the build directory, thus create a
symlink from the project root to this file.

### IntelliSense

Plugin _llvm-vs-code-extensions.vscode-clangd_ is chosen over
_ms-vscode.cpptools_ which don't work in Alpine Linux containers (or in general
from my experience). `build/(Debug|Release)/compile_commands.json` must be
symlinked to project root for clangd to work, read more @ vscode-clangd
extension details.

## Project structure

The structure demonstrates how to organize a project in a modular and
maintainable way. The structure is intended to scale well as the project grows
and be easy to understand. When looking at included files, it's easy to
know what target and module it originates from:

    #include "greeter/Factory.h"

Because the "include prefix" is the same as the module's folder name as well as
the target name.

### source folder

This folder contains all source code of the project as separate modules:

    source/
    ├── application
    │   ├── CMakeLists.txt
    │   ├── GenerateBuildInfo.cmake
    │   └── src
    │       ├── Application.cc
    │       └── BuildInfo.h.in
    ├── CMakeLists.txt
    ├── greeter
    │   ├── CMakeLists.txt
    │   └── inc
    │       └── greeter
    │           ├── Factory.h
    │           └── Greeter.h
    └── greeter_impl
        ├── CMakeLists.txt
        ├── src
        │   ├── FactoryImpl.cc
        │   ├── GreeterImpl.cc
        │   └── GreeterImpl.h
        └── test
            ├── CMakeLists.txt
            └── src
                └── GreeterTest.cc

Description:

* _Application:_ This module contains the main function and is the top level
  module that nothing depends on.
* _greeter_: This module contains interfaces only and has no implementation,
  thus nothing is produced when built. Another module is responsible for
  implementing these interfaces (_greeter_impl_ in this example). Other
  modules in the project shall depend on this to favor dependency inversion
  principle, rather than depend on the implementation.
* _greeter_impl_: This module contains an implementation of the _greeter_
  interface.

### export folder

This folder conains all targets (libraries and executables) that is produced
from this project. It contains no source code, instead the executable and
libraries is built upon including source code modules of choice. This makes it
easy to reuse source code modules and create new targets and variants. Example
"hello_world" is a statically linked cmdline application that is built upon
modules "application" and  "greeter_impl".

    export/
    ├── CMakeLists.txt
    ├── hello_world
    │   └── CMakeLists.txt
    ├── libgreeter_dynamic
    │   └── CMakeLists.txt
    └── libgreeter_static
        └── CMakeLists.txt

### install and package

Following components is defined that each produces a package/installation:

    $ make list_install_components
    Available install components are: "application" "library" "library-dev"

Description:

* _application:_ Contains the statically linked hello_world app.
* _library:_ Contains a dynamic library that external applications uses during
  runtime.
* _library-dev:_ Contains library headers, dynamic library and static library
  for app developers.
