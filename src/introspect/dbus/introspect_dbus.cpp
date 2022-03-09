#include <malloc.h>
#include "introspect_dbus.hpp"

int32_t introspect_dbus_send_vehicle(introspect_dbus_context_t context, const struct Vehicle* vehicle) {
    DBusMessage* msg = dbus_message_new_signal('/vehicle/', 'org.openttd.Vehicle', 'Vehicle');

    if(NULL == msg) {
        return E_DBUS_NULL_MESSAGE;
    }

    DBusMessageIter args;
    dbus_message_iter_init_append(msg, &args);
    if (!dbus_message_iter_append_basic(&args, DBUS_TYPE_STRING, &sigvalue)) {
        return E_DBUS_OUT_OF_MEMORY;
    }

    dbus_uint32_t serial;
    if (!dbus_connection_send(context->connection, msg, &serial)) {
        return E_DBUS_OUT_OF_MEMORY;
    }
    dbus_connection_flush(conn);
    dbus_message_unref(msg);

    return 0;
}

int32_t introspect_dbus_send_station(introspect_dbus_context_t context, const struct Station* vehicle) {
    return 0;
}

int32_t introspect_dbus_send_town(introspect_dbus_context_t context, const struct Town* vehicle) {

    return 0;
}

int32_t introspect_dbus_close(introspect_dbus_context_t context) {
    dbus_connection_close(context->connection);
    return 0;
}

int32_t introspect_dbus_init(introspect_context_t context, const char* in_channel_name) {
    context->send_town = &introspect_dbus_send_town;
    context->send_station = &introspect_dbus_send_station;
    context->send_vehicle = &introspect_dbus_send_vehicle;
    context->close = &introspect_dbus_close;

    DBusError err;
    DBusConnection* conn;
    int ret;
    // initialise the errors
    dbus_error_init(&err);

    conn = dbus_bus_get(in_channel_name, &err);
    if (dbus_error_is_set(&err)) {
        dbus_error_free(&err);
        return -1;
    }

    if (NULL == conn) {
        return -1;
    }

    auto impl = MallocT<introspect_dbus_context>((size_t)1);
    impl->channel_name = in_channel_name;
    impl->connection = conn;

    context->instance_context = (void*)impl;
    return 0;
}

