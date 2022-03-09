#ifndef INTROSPECT_DBUS_H
#define INTROSPECT_DBUS_H

#include "introspect/introspect.h"
#include <dbus/dbus.h>

struct introspect_dbus_context {
    char* channel_name;
    DBusConnection* connection;
};
typedef struct introspect_dbus_context* introspect_dbus_context_t;

int32_t introspect_dbus_init(introspect_context_t context);
int32_t introspect_dbus_send_vehicle(introspect_dbus_context_t context, struct Vehicle* vehicle);
int32_t introspect_dbus_send_station(introspect_dbus_context_t context, struct Station* vehicle);
int32_t introspect_dbus_send_town(introspect_dbus_context_t context, struct Town* vehicle);
int32_t introspect_dbus_close(introspect_dbus_context_t context);

#endif