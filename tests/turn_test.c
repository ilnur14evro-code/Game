#include "engine/turn/turn.h"

#include <assert.h>

int main(void) {
    World world;
    Command command;
    Position player;
    Position enemy_before;
    Position enemy_after;

    world_init(&world, 10, 6);
    assert(entity_store_get_position(&world.entities, world.player, &player) == 1);
    assert(entity_store_get_position(&world.entities, world.enemy, &enemy_before) == 1);

    command.type = COMMAND_MOVE_RIGHT;
    assert(turn_process_command(&world, command) == 1);
    assert(entity_store_get_position(&world.entities, world.player, &player) == 1);
    assert(player.x == 6);
    assert(entity_store_get_position(&world.entities, world.enemy, &enemy_after) == 1);
    assert(enemy_after.x == enemy_before.x - 1);

    command.type = COMMAND_WAIT;
    assert(turn_process_command(&world, command) == 1);

    assert(turn_process_command(&world, (Command){COMMAND_NONE}) == 0);

    return 0;
}
