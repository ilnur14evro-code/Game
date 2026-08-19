#include "engine/turn/turn.h"

int turn_process_command(World *world, Command command) {
    if (world == 0) {
        return 0;
    }

    switch (command.type) {
        case COMMAND_MOVE_UP:
            return world_try_move_player(world, 0, -1);
        case COMMAND_MOVE_DOWN:
            return world_try_move_player(world, 0, 1);
        case COMMAND_MOVE_LEFT:
            return world_try_move_player(world, -1, 0);
        case COMMAND_MOVE_RIGHT:
            return world_try_move_player(world, 1, 0);
        case COMMAND_WAIT:
            return 1;
        case COMMAND_NONE:
        case COMMAND_QUIT:
        default:
            return 0;
    }
}
