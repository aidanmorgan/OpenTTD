#ifndef INTROSPECT_DBUS_HPP
#define INTROSPECT_DBUS_HPP

#include "introspect/introspect.hpp"
#include <dbus/dbus.h>
#include "core/alloc_func.hpp"

struct introspect_dbus_context {
    char* channel_name;
    DBusConnection* connection;
};
typedef struct introspect_dbus_context* introspect_dbus_context_t;

int32_t introspect_dbus_init(introspect_context_t context, const char* channel_name);
int32_t introspect_dbus_send_vehicle(introspect_dbus_context_t context, const struct Vehicle* vehicle);
int32_t introspect_dbus_send_station(introspect_dbus_context_t context, const struct Station* vehicle);
int32_t introspect_dbus_send_town(introspect_dbus_context_t context, const struct Town* vehicle);
int32_t introspect_dbus_close(introspect_dbus_context_t context);

#endif