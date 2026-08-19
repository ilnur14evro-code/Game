#ifndef GAME_ENGINE_WORLD_WORLD_H
#define GAME_ENGINE_WORLD_WORLD_H

#define WORLD_MAX_WIDTH 128
#define WORLD_MAX_HEIGHT 128

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    int width;
    int height;
    char tiles[WORLD_MAX_HEIGHT][WORLD_MAX_WIDTH];
    Position player;
} World;

void world_init(World *world, int width, int height);
int world_try_move_player(World *world, int dx, int dy);

#endif
