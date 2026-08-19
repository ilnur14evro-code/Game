#include "engine/system/movement/movement.h"

int movement_system_move(World *world, EntityStore *store, EntityId entity, int dx, int dy) {
    Position position;
    Position next;
    EntityId occupant;

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

    return entity_store_set_position(store, entity, next);
}
