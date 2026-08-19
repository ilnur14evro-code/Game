#ifndef GAME_ENGINE_AI_AI_H
#define GAME_ENGINE_AI_AI_H

#include "engine/entity/entity_store.h"
#include "engine/world/world.h"

int ai_take_turn(World *world, EntityStore *entities, EntityId entity, EntityId player);

#endif
