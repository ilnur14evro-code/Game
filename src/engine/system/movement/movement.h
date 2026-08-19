#ifndef GAME_ENGINE_SYSTEM_MOVEMENT_MOVEMENT_H
#define GAME_ENGINE_SYSTEM_MOVEMENT_MOVEMENT_H

#include "engine/entity/entity_store.h"
#include "engine/world/world.h"

int movement_system_move(World *world, EntityStore *store, EntityId entity, int dx, int dy);

#endif
