FROM ubuntu:focal

ENV DEBIAN_FRONTEND=noninteractive

RUN sed --in-place=~ 's|archive.ubuntu.com|ftp.acc.umu.se|g' /etc/apt/sources.list

# base-tools for C and C++
RUN apt-get update \
    && apt-get install \
        --no-install-recommends \
        --assume-yes \
        --quiet \
        autoconf \
        automake \
        cmake \
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
        valgrind \
    && rm -r /var/lib/apt/lists/*

# Other useful tools.
RUN apt-get update \
    && apt-get install \
        --no-install-recommends \
        --assume-yes \
        --quiet \
        ca-certificates \
        curl \
        git \
        less \
        xz-utils \
    && rm -r /var/lib/apt/lists/*

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
