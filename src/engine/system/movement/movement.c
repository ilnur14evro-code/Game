#include "engine/system/movement/movement.h"

int movement_system_move(World *world, EntityStore *store, EntityId entity, int dx, int dy, EventQueue *events) {
    Position position;
    Position next;
    EntityId occupant;
    Event moved;

    if (world == 0 || store == 0 || !entity_store_get_position(store, entity, &position)) {
        return 0;
    }

    next.x = position.x + dx;
    next.y = position.y + dy;

    if (!world_is_walkable(world, next.x, next.y)) {
        return 0;
    }

    if (entity_store_find_at(store, next, &occupant) && occupant != entity) {
        return 0;
    }

    if (!entity_store_set_position(store, entity, next)) {
        return 0;
    }

    if (events != 0) {
        moved.type = EVENT_ENTITY_MOVED;
        moved.entity = entity;
        moved.target = ENTITY_INVALID;
        moved.x = next.x;
        moved.y = next.y;
        moved.value = 0;
        (void)event_queue_push(events, moved);
    }

    return 1;
}
