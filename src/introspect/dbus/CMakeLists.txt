find_package(DBUS REQUIRED)

# Use results of find_package() call.
include_directories(${DBUS_INCLUDE_DIRS} /usr/local/Cellar/dbus/1.14.0/lib/dbus-1.0/include/ )

message(${DBUS_INCLUDE_DIRS})

add_files(
        introspect_dbus.h
        introspect_dbus.c
)