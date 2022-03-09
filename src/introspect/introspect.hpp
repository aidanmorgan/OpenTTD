#ifndef INTROSPECT_HPP
#define INTROSPECT_HPP

#include "vehicle_base.h"
#include "station_base.h"
#include "town.h"
#include <stdint.h>
#include "core/alloc_func.hpp"

struct introspect_context {
    int32_t (*send_vehicle)(void*, const struct Vehicle *);
    int32_t (*send_station)(void*, const struct Station *);
    int32_t (*send_town)(void*, const struct Town *);

    int32_t (*close)(void *);
    void* instance_context;
};
typedef struct introspect_context* introspect_context_t;

int32_t introspect_send_town(introspect_context_t context, const struct Town* town);
int32_t introspect_send_vehicle(introspect_context_t context, const struct Vehicle * vehicle);
int32_t introspect_send_station(introspect_context_t context, const struct Station * station);
int32_t introspect_close(introspect_context_t context);

#endif