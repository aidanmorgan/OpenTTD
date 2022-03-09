#ifndef INTROSPECT_H
#define INTROSPECT_H

#include "vehicle_base.h"
#include "station_base.h"
#include "town.h"
#include <stdint.h>

struct introspect_context {
    int32_t (*send_vehicle)(void*, struct Vehicle *);
    int32_t (*send_station)(void*, struct Station *);
    int32_t (*send_town)(void*, struct Town *);

    int32_t (*close)(void *);
    void* instance_context;
};

typedef struct introspect_context* introspect_context_t;

int32_t introspect_send_town(introspect_context_t context, struct Town* town);
int32_t introspect_send_vehicle(introspect_context_t context, struct Vehicle * vehicle);
int32_t introspect_send_station(introspect_context_t context, struct Station * station);
int32_t introspect_close(introspect_context_t context);

#endif