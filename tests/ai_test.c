#include "engine/system/ai/ai.h"

#include <assert.h>

static int distance(Position a, Position b) {
    int dx = a.x - b.x;
    int dy = a.y - b.y;
    if (dx < 0) dx = -dx;
    if (dy < 0) dy = -dy;
    return dx + dy;
}

int main(void) {
    World world;
    Position player;
    Position enemy_before;
    Position enemy_after;

    world_init(&world, 10, 6);
    assert(entity_store_get_position(&world.entities, world.player, &player) == 1);
    assert(entity_store_get_position(&world.entities, world.enemy, &enemy_before) == 1);

    assert(ai_system_take_enemy_turn(&world) == 1);
    assert(entity_store_get_position(&world.entities, world.enemy, &enemy_after) == 1);
    assert(distance(enemy_after, player) < distance(enemy_before, player));
    assert(enemy_after.x != player.x || enemy_after.y != player.y);
    return 0;
}
