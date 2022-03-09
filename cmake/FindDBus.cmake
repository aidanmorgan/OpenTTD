FIND_PACKAGE(PkgConfig)

FIND_LIBRARY(DBUS_LIBRARIES
        NAMES dbus-1
        HINTS /usr/local/lib
        )

FIND_PATH(DBUS_INCLUDE_DIR
        NAMES dbus/dbus.h
        HINTS /usr/local/include
        )

GET_FILENAME_COMPONENT(_DBUS_LIBRARY_DIR ${DBUS_LIBRARIES} PATH)
FIND_PATH(DBUS_ARCH_INCLUDE_DIR
        NAMES dbus/dbus-arch-deps.h
        HINTS /usr/local/include
        ${_DBUS_LIBRARY_DIR}
        ${DBUS_INCLUDE_DIR}
        PATH_SUFFIXES include
        )

SET(DBUS_INCLUDE_DIRS ${DBUS_INCLUDE_DIR} ${DBUS_ARCH_INCLUDE_DIR})

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(DBUS REQUIRED_VARS DBUS_INCLUDE_DIRS DBUS_LIBRARIES)
