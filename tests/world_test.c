#include "engine/world/world.h"

#include <assert.h>

int main(void) {
    World world;

    world_init(&world, 10, 6);
    assert(world.width == 10);
    assert(world.height == 6);
    assert(world.player.x == 5);
    assert(world.player.y == 3);

    assert(world_try_move_player(&world, 1, 0) == 1);
    assert(world.player.x == 6);
    assert(world_try_move_player(&world, 0, -100) == 0);

    world.player.x = 1;
    world.player.y = 1;
    assert(world_try_move_player(&world, -1, 0) == 0);
    assert(world.player.x == 1);

    return 0;
}
