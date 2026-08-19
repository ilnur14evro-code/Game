#ifndef GAME_ENGINE_SYSTEM_AI_AI_H
#define GAME_ENGINE_SYSTEM_AI_AI_H

#include "engine/event/event_queue.h"
#include "engine/world/world.h"

int ai_system_take_enemy_turn(World *world, EventQueue *events);

#endif
