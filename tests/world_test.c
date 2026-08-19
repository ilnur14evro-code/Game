#include "engine/world/world.h"

#include <assert.h>

int main(void) {
    World world;
    Position player;
    Position enemy;

    world_init(&world, 10, 6);

    assert(entity_store_get_position(&world.entities, world.player, &player) == 1);
    assert(entity_store_get_position(&world.entities, world.enemy, &enemy) == 1);
    assert(player.x == 5);
    assert(player.y == 3);
    assert(enemy.x != player.x || enemy.y != player.y);
    assert(world_is_walkable(&world, player.x, player.y) == 1);
    assert(world_is_walkable(&world, 0, 0) == 0);
    assert(world_is_walkable(&world, -1, 0) == 0);
    return 0;
}
