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

void turn_manager_init(TurnManager *manager) {
    if (manager == 0) {
        return;
    }

    manager->phase = TURN_PHASE_PLAYER;
    manager->turn_number = 0;
}

int turn_manager_process(TurnManager *manager, World *world, Command command) {
    if (manager == 0 || world == 0 || manager->phase != TURN_PHASE_PLAYER) {
        return 0;
    }

    if (!player_command(world, command)) {
        return 0;
    }

    manager->phase = TURN_PHASE_ENEMY;
    (void)ai_system_take_enemy_turn(world);

    manager->phase = TURN_PHASE_COMPLETE;
    manager->turn_number += 1;
    manager->phase = TURN_PHASE_PLAYER;
    return 1;
}

int turn_process_command(World *world, Command command) {
    TurnManager manager;
    turn_manager_init(&manager);
    return turn_manager_process(&manager, world, command);
}
