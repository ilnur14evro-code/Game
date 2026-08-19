#ifndef GAME_ENGINE_ENTITY_ENTITY_STORE_H
#define GAME_ENGINE_ENTITY_ENTITY_STORE_H

#include "engine/entity/entity.h"
#include "engine/entity/position.h"

typedef struct {
    int alive[ENTITY_MAX];
    Position positions[ENTITY_MAX];
} EntityStore;

void entity_store_init(EntityStore *store);
EntityId entity_store_create(EntityStore *store, Position position);
int entity_store_is_alive(const EntityStore *store, EntityId id);
int entity_store_get_position(const EntityStore *store, EntityId id, Position *position);
int entity_store_set_position(EntityStore *store, EntityId id, Position position);

#endif
