#!/bin/bash
set -ue

http_try_fetch()
{
  local http_url="${1}"
  if [[ ! -e "${SOURCE_DIR}" ]]; then
    mkdir -p ${SOURCE_DIR}
    curl \
      --location \
      ${http_url} \
      |tar -xz --directory ${SOURCE_DIR_PREFIX} ${NAME}
  fi
}

init_config()
{
  while [[ ${#} -gt 0 ]]; do
    eval "local _${1}"
    shift
  done
  if [[ ! -v _target ]]; then
    source /etc/os-release
    _target="${ID}_$(uname -m)"
  fi
  readonly NAME="${_name}"
  readonly SOURCE_DIR_PREFIX="${_dst}/source"
  readonly SOURCE_DIR="${_dst}/source/${_name}"
  readonly BUILD_DIR="${_dst}/build/${_target}/${_name}"
  readonly INSTALL_DIR="${_dst}/install/${_target}/${_name}"
}

main()
{
  init_config "${@}"
  fetch
  configure
  install
}

main  "${@}"
