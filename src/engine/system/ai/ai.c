#include "engine/system/ai/ai.h"

#include "engine/system/movement/movement.h"

static int step_towards(int from, int target) {
    if (from < target) return 1;
    if (from > target) return -1;
    return 0;
}

static int would_overlap_player(const Position *enemy, const Position *player, int dx, int dy) {
    return enemy->x + dx == player->x && enemy->y + dy == player->y;
}

int ai_system_take_enemy_turn(World *world, EventQueue *events) {
    Position player;
    Position enemy;
    int dx;
    int dy;

    if (world == 0) {
        return 0;
    }

    if (!entity_store_get_position(&world->entities, world->player, &player) ||
        !entity_store_get_position(&world->entities, world->enemy, &enemy)) {
        return 0;
    }

    dx = step_towards(enemy.x, player.x);
    dy = step_towards(enemy.y, player.y);

    if (dx != 0 && !would_overlap_player(&enemy, &player, dx, 0) &&
        movement_system_move(world, &world->entities, world->enemy, dx, 0, events)) {
        return 1;
    }

    if (dy != 0 && !would_overlap_player(&enemy, &player, 0, dy) &&
        movement_system_move(world, &world->entities, world->enemy, 0, dy, events)) {
        return 1;
    }

    return 0;
}
