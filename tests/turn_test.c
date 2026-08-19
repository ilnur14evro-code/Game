#include "engine/turn/turn.h"

#include <assert.h>

int main(void) {
    World world;
    Position player;
    Command command;

    world_init(&world, 10, 6);

    assert(entity_store_get_position(&world.entities, world.player, &player) == 1);
    command.type = COMMAND_MOVE_RIGHT;
    assert(turn_process_command(&world, command) == 1);
    assert(entity_store_get_position(&world.entities, world.player, &player) == 1);
    assert(player.x == 6);

    command.type = COMMAND_WAIT;
    assert(turn_process_command(&world, command) == 1);

    command.type = COMMAND_MOVE_UP;
    assert(turn_process_command(&world, command) == 1);
    assert(entity_store_get_position(&world.entities, world.player, &player) == 1);
    assert(player.y == 2);
    return 0;
}
