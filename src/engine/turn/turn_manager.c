#include "engine/turn/turn_manager.h"

#include "engine/ai/ai.h"
#include "engine/system/movement.h"

void turn_manager_init(TurnManager *turns) {
    if (turns == 0) {
        return;
    }

    turns->player_phase = 1;
    turns->turn_number = 0;
}

int turn_manager_process_player(TurnManager *turns, World *world, EntityStore *entities, EntityId player, Command command) {
    if (turns == 0 || world == 0 || entities == 0 || !turns->player_phase) {
        return 0;
    }

    if (command.type == COMMAND_WAIT) {
        turns->player_phase = 0;
        return 1;
    }

    if (!movement_system_execute(world, entities, player, command)) {
        return 0;
    }

    turns->player_phase = 0;
    return 1;
}

int turn_manager_process_enemies(TurnManager *turns, World *world, EntityStore *entities, EntityId player) {
    EntityId entity;

    if (turns == 0 || world == 0 || entities == 0 || turns->player_phase) {
        return 0;
    }

    for (entity = 1; entity < ENTITY_MAX; ++entity) {
        if (entity != player && entity_store_is_alive(entities, entity)) {
            (void)ai_take_turn(world, entities, entity, player);
        }
    }

    turns->turn_number += 1;
    turns->player_phase = 1;
    return 1;
}
