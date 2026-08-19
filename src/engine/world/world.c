#include "engine/world/world.h"

static int world_in_bounds(const World *world, int x, int y) {
    return x >= 0 && y >= 0 && x < world->width && y < world->height;
}

static int world_find_free_tile(const World *world, Position origin, Position *result) {
    int radius;

    if (world == 0 || result == 0) {
        return 0;
    }

    for (radius = 1; radius < WORLD_MAX_WIDTH + WORLD_MAX_HEIGHT; ++radius) {
        int offsets[4][2] = {{radius, 0}, {-radius, 0}, {0, radius}, {0, -radius}};
        int i;

        for (i = 0; i < 4; ++i) {
            int x = origin.x + offsets[i][0];
            int y = origin.y + offsets[i][1];
            if (world_is_walkable(world, x, y)) {
                result->x = x;
                result->y = y;
                return 1;
            }
        }
    }

    return 0;
}

void world_init(World *world, int width, int height) {
    int x;
    int y;
    Position player_position;
    Position enemy_position;

    if (world == 0) {
        return;
    }

    if (width < 3) width = 3;
    if (height < 3) height = 3;
    if (width > WORLD_MAX_WIDTH) width = WORLD_MAX_WIDTH;
    if (height > WORLD_MAX_HEIGHT) height = WORLD_MAX_HEIGHT;

    world->width = width;
    world->height = height;
    world->player = ENTITY_INVALID;
    world->enemy = ENTITY_INVALID;
    entity_store_init(&world->entities);

    for (y = 0; y < height; ++y) {
        for (x = 0; x < width; ++x) {
            world->tiles[y][x] =
                (x == 0 || y == 0 || x == width - 1 || y == height - 1) ? '#' : '.';
        }
    }

    player_position.x = width / 2;
    player_position.y = height / 2;
    world->player = entity_store_create(&world->entities, player_position);

    if (world_find_free_tile(world, player_position, &enemy_position)) {
        world->enemy = entity_store_create(&world->entities, enemy_position);
    }
}

int world_is_walkable(const World *world, int x, int y) {
    if (world == 0 || !world_in_bounds(world, x, y)) {
        return 0;
    }
    return world->tiles[y][x] != '#';
}
