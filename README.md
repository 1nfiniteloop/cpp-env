# C++ development environment

Start developing a project in C++ means setting the bar a bit higher than usual.
Because the C++ toolchain has no support for package managment. It also requires
extensive build environment configuration before the application development can
begin. This requires knowledge, patience and time.

The intention with this development environment is to give new projects
a basic setup and have something to build upon for a quick start.

## Overview

The build-environment is based on a portable docker-container including all
basic tools needed, see more in `.devcontainer/Dockerfile`.  No further
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

### Code snippets

A set of user-defined code snippets for creating C++11 classes and interfaces
exists in `.vscode/cpp.code-snippets`. This file can be copied into
`~/.config/Code/User/snippets/` for global scope.

### Code formatting

This repository contains a customized `.clang-format` file which is used when
invoking "Format document" in VS Code.

### IntelliSense

Plugin _llvm-vs-code-extensions.vscode-clangd_ is chosen over
_ms-vscode.cpptools_ which don't work in Alpine Linux containers (or in general
from my experience). `build/(Debug|Release)/compile_commands.json` must be
symlinked to project root for clangd to work, read more @ vscode-clangd
extension details.

## Install dependencies

Install dependencies with `./install-dependencies gtest boost [...]`.

Note: This shall be run from inside the container. The dependencies is cached
on a docker volume under `~/third_party`.

## Build

1. Create build tree with `mkdir --parents build/{Debug,Release}`

2. Build _Debug_ and run tests:

         cd build/Debug \
          && cmake \
             -D CMAKE_EXPORT_COMPILE_COMMANDS=1 \
             -D VERSION=1.0.0 \
             -D BUILD=Debug \
             ../../ \
          && make test_all

3. Build _Release_ and make package:

        cd build/Release \
          && cmake \
             -D CMAKE_EXPORT_COMPILE_COMMANDS=1 \
             -D VERSION=1.0.0 \
             -D BUILD=Release \
             -D UNITTEST=OFF \
             ../../ \
          && make package

## Project structure

This project contains three basic components. It demonstrates how to organize a
project in a modular and maintainable structure and favor dependency inversion
principle:

* _hello_world_impl_: This component holds an implementation and produces a
  static library when built.
* _hello_world_: This component contains interfaces only and no implementation,
  thus nothing is produced when built. Another component is responsible for
  implementing these interfaces (_hello_world_impl_ in this example). Other
  components in the project shall depend on this, rather than the implementation.
* _Application:_ This component contains the main function and builds an
  executable (in this example) by linking together all implementation components.

```text
application/
├── CMakeLists.txt
├── GenerateBuildInfo.cmake
└── src
    ├── Application.cc
    └── BuildInfo.h.in
hello_world
├── CMakeLists.txt
└── inc
    └── hello_world
        ├── Factory.h
        └── Greeter.h
hello_world_impl
├── CMakeLists.txt
├── src
│   ├── FactoryImpl.cc
│   ├── GreeterImpl.cc
│   └── GreeterImpl.h
└── test
    ├── CMakeLists.txt
    └── src
        └── GreeterTest.cc
```
