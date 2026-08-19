#include "engine/world/world.h"

static int world_in_bounds(const World *world, int x, int y) {
    return x >= 0 && y >= 0 && x < world->width && y < world->height;
}

void world_init(World *world, int width, int height) {
    int x;
    int y;

    if (world == 0) {
        return;
    }

    if (width < 3) width = 3;
    if (height < 3) height = 3;
    if (width > WORLD_MAX_WIDTH) width = WORLD_MAX_WIDTH;
    if (height > WORLD_MAX_HEIGHT) height = WORLD_MAX_HEIGHT;

    world->width = width;
    world->height = height;
    world->player.x = width / 2;
    world->player.y = height / 2;

    for (y = 0; y < height; ++y) {
        for (x = 0; x < width; ++x) {
            world->tiles[y][x] = (x == 0 || y == 0 || x == width - 1 || y == height - 1) ? '#' : '.';
        }
    }
}

int world_is_walkable(const World *world, int x, int y) {
    if (world == 0 || !world_in_bounds(world, x, y)) {
        return 0;
    }
    return world->tiles[y][x] != '#';
}

int world_try_move_player(World *world, int dx, int dy) {
    int next_x;
    int next_y;

    if (world == 0) {
        return 0;
    }

    next_x = world->player.x + dx;
    next_y = world->player.y + dy;

    if (!world_is_walkable(world, next_x, next_y)) {
        return 0;
    }

    world->player.x = next_x;
    world->player.y = next_y;
    return 1;
}
