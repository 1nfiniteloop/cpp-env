FROM alpine:3.16

ARG ALPINE_MIRROR="ftp.acc.umu.se/mirror/alpinelinux.org"
RUN sed -i "s|dl-cdn.alpinelinux.org/alpine|${ALPINE_MIRROR}|g" /etc/apk/repositories

# base-tools for C and C++
RUN apk update \
  && apk add --no-cache \
    autoconf \
    automake \
    cmake \
    g++ \
    gcc \
    gdb \
    libtool \
    make \
    pkgconf \
  && rm -r /var/cache/apk/*

# Other useful tools for C and C++
RUN apk update \
  && apk add --no-cache \
    clang-extra-tools \
    py3-pip \
    valgrind \
  && rm -r /var/cache/apk/* \
  && python3 -m pip install conan

# Other useful tools.
RUN apk update \
  && apk add --no-cache \
    bash \
    ca-certificates \
    curl \
    git \
    sudo \
  && rm -r /var/cache/apk/*

RUN adduser \
    -s /bin/bash \
    -D \
    build \
  && addgroup sudo \
  && adduser build sudo \
  && echo -e "\n# Allow sudo without password\n%sudo ALL=(ALL) NOPASSWD:ALL\n" >> /etc/sudoers

# Don't run as root inside container,
# see https://github.com/microsoft/vscode-remote-release/issues/22
ENV HOME /home/build
ENV THIRD_PARTY_ROOT /home/build/third_party
USER build

CMD ["/bin/bash", "-l"]
