#include "engine/ai/ai.h"

static int try_step(World *world, EntityStore *entities, EntityId entity, Position current, int dx, int dy) {
    Position next;

    next.x = current.x + dx;
    next.y = current.y + dy;

    if (next.x < 0 || next.y < 0 ||
        next.x >= world->width || next.y >= world->height ||
        world->tiles[next.y][next.x] == '#') {
        return 0;
    }

    return entity_store_set_position(entities, entity, next);
}

int ai_take_turn(World *world, EntityStore *entities, EntityId entity, EntityId player) {
    Position enemy;
    Position target;
    int dx;
    int dy;

    if (world == 0 || entities == 0 || entity == ENTITY_INVALID || player == ENTITY_INVALID ||
        !entity_store_get_position(entities, entity, &enemy) ||
        !entity_store_get_position(entities, player, &target)) {
        return 0;
    }

    dx = target.x - enemy.x;
    dy = target.y - enemy.y;

    if (dx != 0 && (dy == 0 || dx > 0)) {
        return try_step(world, entities, entity, enemy, dx > 0 ? 1 : -1, 0);
    }

    if (dy != 0) {
        return try_step(world, entities, entity, enemy, 0, dy > 0 ? 1 : -1);
    }

    return 0;
}
