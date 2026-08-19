#ifndef GAME_ENGINE_SYSTEM_MOVEMENT_H
#define GAME_ENGINE_SYSTEM_MOVEMENT_H

#include "engine/command/command.h"
#include "engine/entity/entity_store.h"
#include "engine/world/world.h"

int movement_system_execute(World *world, EntityStore *entities, EntityId entity, Command command);

#endif
