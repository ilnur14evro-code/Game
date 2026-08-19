#include "engine/world/world.h"

#include <assert.h>

int main(void) {
    World world;
    Position position;

    world_init(&world, 10, 6);
    assert(world.width == 10);
    assert(world.height == 6);
    assert(entity_store_get_position(&world.entities, world.player, &position) == 1);
    assert(position.x == 5);
    assert(position.y == 3);
    assert(entity_store_get_position(&world.entities, world.enemy, &position) == 1);
    assert(position.x == 7);
    assert(position.y == 3);

    assert(world_is_walkable(&world, 5, 3) == 1);
    assert(world_is_walkable(&world, 0, 0) == 0);
    assert(world_is_walkable(&world, -1, 0) == 0);

    return 0;
}
