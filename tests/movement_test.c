#include "engine/system/movement/movement.h"

#include <assert.h>

int main(void) {
    World world;
    Position position;

    world_init(&world, 10, 6);
    assert(entity_store_get_position(&world.entities, world.player, &position) == 1);
    assert(position.x == 5);

    assert(movement_system_move(&world, &world.entities, world.player, 1, 0) == 1);
    assert(entity_store_get_position(&world.entities, world.player, &position) == 1);
    assert(position.x == 6);

    assert(movement_system_move(&world, &world.entities, world.player, -100, 0) == 0);
    assert(position.x == 6 || entity_store_get_position(&world.entities, world.player, &position));

    return 0;
}
