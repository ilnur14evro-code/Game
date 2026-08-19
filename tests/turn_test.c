#include "engine/turn/turn.h"

#include <assert.h>

int main(void) {
    World world;
    Command command;

    world_init(&world, 10, 6);

    command.type = COMMAND_MOVE_RIGHT;
    assert(turn_process_command(&world, command) == 1);
    assert(world.player.x == 6);

    command.type = COMMAND_MOVE_UP;
    assert(turn_process_command(&world, command) == 1);
    assert(world.player.y == 2);

    command.type = COMMAND_WAIT;
    assert(turn_process_command(&world, command) == 1);

    world.player.x = 1;
    world.player.y = 1;
    command.type = COMMAND_MOVE_LEFT;
    assert(turn_process_command(&world, command) == 0);
    assert(world.player.x == 1);
    assert(world.player.y == 1);

    return 0;
}
