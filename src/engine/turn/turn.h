#ifndef GAME_ENGINE_TURN_TURN_H
#define GAME_ENGINE_TURN_TURN_H

#include "engine/command/command.h"
#include "engine/world/world.h"

typedef enum {
    TURN_PHASE_PLAYER = 0,
    TURN_PHASE_ENEMY,
    TURN_PHASE_COMPLETE
} TurnPhase;

typedef struct {
    TurnPhase phase;
    unsigned long turn_number;
} TurnManager;

void turn_manager_init(TurnManager *manager);
int turn_manager_process(TurnManager *manager, World *world, Command command);
int turn_process_command(World *world, Command command);

#endif
