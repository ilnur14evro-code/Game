#include "engine/turn/turn.h"

#include <assert.h>

int main(void) {
    World world;
    TurnManager manager;
    Command command;
    Position player;
    Position enemy_before;
    Position enemy_after;

    world_init(&world, 10, 6);
    turn_manager_init(&manager);

    assert(manager.phase == TURN_PHASE_PLAYER);
    assert(manager.turn_number == 0);
    assert(entity_store_get_position(&world.entities, world.player, &player) == 1);
    assert(entity_store_get_position(&world.entities, world.enemy, &enemy_before) == 1);

    command.type = COMMAND_MOVE_RIGHT;
    assert(turn_manager_process(&manager, &world, command) == 1);
    assert(manager.phase == TURN_PHASE_PLAYER);
    assert(manager.turn_number == 1);
    assert(entity_store_get_position(&world.entities, world.player, &player) == 1);
    assert(player.x == 6);
    assert(entity_store_get_position(&world.entities, world.enemy, &enemy_after) == 1);
    assert(enemy_after.x == enemy_before.x);
    assert(enemy_after.y == enemy_before.y);

    command.type = COMMAND_WAIT;
    assert(turn_manager_process(&manager, &world, command) == 1);
    assert(manager.turn_number == 2);

    assert(turn_manager_process(&manager, &world, (Command){COMMAND_NONE}) == 0);
    assert(manager.turn_number == 2);

    return 0;
}
