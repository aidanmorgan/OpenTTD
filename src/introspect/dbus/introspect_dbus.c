#include "introspect_dbus.h"

int32_t introspect_dbus_send_vehicle(introspect_dbus_context_t context, struct Vehicle* vehicle) {
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
}

int32_t introspect_dbus_send_station(introspect_dbus_context_t context, struct Station* vehicle) {

}

int32_t introspect_dbus_send_town(introspect_dbus_context_t context, struct Town* vehicle) {

}

void introspect_dbus_clos(introspect_dbus_context_t context) {
    dbus_connection_close(context->connection);
}

int32_t introspect_dbus_init(introspect_context_t context, char* in_channel_name) {
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


    introspect_dbus_context_t dbus_context = {
            channel_name = in_channel_name,
            connection = conn
    };
    context->additional_context = (void*)dbus_context;
    return 0;
}

