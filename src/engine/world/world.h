#ifndef GAME_ENGINE_WORLD_WORLD_H
#define GAME_ENGINE_WORLD_WORLD_H

#include "engine/entity/entity_store.h"

#define WORLD_MAX_WIDTH 128
#define WORLD_MAX_HEIGHT 128

typedef struct {
    int width;
    int height;
    char tiles[WORLD_MAX_HEIGHT][WORLD_MAX_WIDTH];
    EntityStore entities;
    EntityId player;
    EntityId enemy;
} World;

void world_init(World *world, int width, int height);
int world_try_move_player(World *world, int dx, int dy);
int world_is_walkable(const World *world, int x, int y);

#endif
