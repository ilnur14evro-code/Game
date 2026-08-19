#include "engine/system/movement.h"

static int command_delta(CommandType type, int *dx, int *dy) {
    if (dx == 0 || dy == 0) {
        return 0;
    }

    *dx = 0;
    *dy = 0;

    switch (type) {
        case COMMAND_MOVE_UP:
            *dy = -1;
            return 1;
        case COMMAND_MOVE_DOWN:
            *dy = 1;
            return 1;
        case COMMAND_MOVE_LEFT:
            *dx = -1;
            return 1;
        case COMMAND_MOVE_RIGHT:
            *dx = 1;
            return 1;
        default:
            return 0;
    }
}

int movement_system_execute(World *world, EntityStore *entities, EntityId entity, Command command) {
    Position current;
    Position next;
    int dx;
    int dy;

    if (world == 0 || entities == 0 ||
        !entity_store_get_position(entities, entity, &current)) {
        return 0;
    }

    if (!command_delta(command.type, &dx, &dy)) {
        return 0;
    }

    next.x = current.x + dx;
    next.y = current.y + dy;

    if (next.x < 0 || next.y < 0 ||
        next.x >= world->width || next.y >= world->height ||
        world->tiles[next.y][next.x] == '#') {
        return 0;
    }

    return entity_store_set_position(entities, entity, next);
}
