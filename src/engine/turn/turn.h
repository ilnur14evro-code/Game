#ifndef GAME_ENGINE_TURN_TURN_H
#define GAME_ENGINE_TURN_TURN_H

#include "engine/command/command.h"
#include "engine/world/world.h"

int turn_process_command(World *world, Command command);

#endif
