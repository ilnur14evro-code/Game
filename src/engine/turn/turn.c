#include "engine/turn/turn.h"

#include "engine/system/ai/ai.h"
#include "engine/system/movement/movement.h"

static int player_command(World *world, Command command) {
    switch (command.type) {
        case COMMAND_MOVE_UP:
            return movement_system_move(world, &world->entities, world->player, 0, -1);
        case COMMAND_MOVE_DOWN:
            return movement_system_move(world, &world->entities, world->player, 0, 1);
        case COMMAND_MOVE_LEFT:
            return movement_system_move(world, &world->entities, world->player, -1, 0);
        case COMMAND_MOVE_RIGHT:
            return movement_system_move(world, &world->entities, world->player, 1, 0);
        case COMMAND_WAIT:
            return 1;
        case COMMAND_NONE:
        case COMMAND_QUIT:
        default:
            return 0;
    }
}

int turn_process_command(World *world, Command command) {
    if (world == 0) {
        return 0;
    }

    if (!player_command(world, command)) {
        return 0;
    }

    (void)ai_system_take_enemy_turn(world);
    return 1;
}
