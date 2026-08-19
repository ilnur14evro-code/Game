#ifndef GAME_ENGINE_TURN_TURN_MANAGER_H
#define GAME_ENGINE_TURN_TURN_MANAGER_H

#include "engine/command/command.h"
#include "engine/entity/entity_store.h"
#include "engine/world/world.h"

#define TURN_MAX_ENTITIES 32

typedef struct {
    int player_phase;
    unsigned long turn_number;
} TurnManager;

void turn_manager_init(TurnManager *turns);
int turn_manager_process_player(TurnManager *turns, World *world, EntityStore *entities, EntityId player, Command command);
int turn_manager_process_enemies(TurnManager *turns, World *world, EntityStore *entities, EntityId player);

#endif
