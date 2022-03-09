#include "introspect.hpp"

int32_t introspect_send_town(introspect_context_t context, const struct Town* town) {
    return context->send_town(context->instance_context, town);
}

int32_t introspect_send_vehicle(introspect_context_t context, const struct Vehicle * vehicle) {
    return context->send_vehicle(context->instance_context, vehicle);
}

int32_t introspect_send_station(introspect_context_t context, const struct Station * station) {
    return context->send_station(context->instance_context, station);
}

int32_t introspect_close(introspect_context_t context) {
    return context->close(context->instance_context);
}
