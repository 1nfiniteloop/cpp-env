set(CPACK_PACKAGE_NAME "${PROJECT_NAME}")
set(CPACK_PACKAGE_VERSION "${PROJECT_VERSION}")
set(CPACK_PACKAGING_INSTALL_PREFIX "/usr/local")
set(CPACK_SOURCE_GENERATOR "TGZ")

# Optional: generate separate packages for each install component
set(CPACK_ARCHIVE_COMPONENT_INSTALL ON)

include(CPack)