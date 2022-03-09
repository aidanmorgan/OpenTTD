FIND_PACKAGE(PkgConfig)

FIND_LIBRARY(DBUS_LIBRARIES
        NAMES dbus-1
        HINTS /usr/local/lib /usr/lib /usr/lib/x86_64-linux-gnu
        )

FIND_PATH(DBUS_INCLUDE_DIR
        NAMES dbus/dbus.h
        HINTS /usr/local/include /usr/include/dbus-1.0/ /usr/lib/x86_64-linux-gnu/dbus-1.0/
        )

GET_FILENAME_COMPONENT(_DBUS_LIBRARY_DIR ${DBUS_LIBRARIES} PATH)
FIND_PATH(DBUS_ARCH_INCLUDE_DIR
        NAMES dbus/dbus-arch-deps.h
        HINTS /usr/local/include /usr/include/dbus-1.0/ /usr/lib/x86_64-linux-gnu/dbus-1.0/
        ${_DBUS_LIBRARY_DIR}
        ${DBUS_INCLUDE_DIR}
        PATH_SUFFIXES include
        )

SET(DBUS_INCLUDE_DIRS ${DBUS_INCLUDE_DIR} ${DBUS_ARCH_INCLUDE_DIR})

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(DBUS REQUIRED_VARS DBUS_INCLUDE_DIRS DBUS_LIBRARIES)
