FROM ubuntu:jammy

ENV DEBIAN_FRONTEND=noninteractive
ARG DEBIAN_MIRROR="se.archive.ubuntu.com"

RUN sed -i "s|archive.ubuntu.com|${DEBIAN_MIRROR}|g" /etc/apt/sources.list

# base-tools for C and C++
RUN apt-get update \
  && apt-get install \
    --no-install-recommends \
    --assume-yes \
    --quiet \
    autoconf \
    automake \
    g++ \
    gcc \
    gdb \
    libtool \
    make \
    pkg-config \
  && rm -r /var/lib/apt/lists/*

# Other useful tools for C and C++
RUN apt-get update \
  && apt-get install \
    --no-install-recommends \
    --assume-yes \
    --quiet \
    clangd \
    clang-format \
    clang-tidy \
    python3-pip \
    valgrind \
  && rm -r /var/lib/apt/lists/* \
  && python3 -m pip install conan

# Other useful tools.
RUN apt-get update \
  && apt-get install \
    --no-install-recommends \
    --assume-yes \
    --quiet \
    bzip2 \
    ca-certificates \
    curl \
    git \
    less \
    xz-utils \
  && rm -r /var/lib/apt/lists/*

ARG CMAKE_VERSION=3.25.0
RUN curl \
  --location \
  --remote-name \
  https://github.com/Kitware/CMake/releases/download/v${CMAKE_VERSION}/cmake-${CMAKE_VERSION}-linux-x86_64.sh \
  && bash cmake-${CMAKE_VERSION}-linux-x86_64.sh -- --skip-license --prefix=/usr/local \
  && rm cmake-${CMAKE_VERSION}-linux-x86_64.sh

RUN useradd \
  --uid 1000 \
  --shell /bin/bash \
  --create-home \
  build

# Don't run as root inside container,
# see https://github.com/microsoft/vscode-remote-release/issues/22
ENV HOME /home/build
ENV THIRD_PARTY_ROOT /home/build/third_party
USER build

CMD ["/bin/bash", "-l"]
