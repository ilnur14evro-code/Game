#include "engine/world/world.h"

static int world_in_bounds(const World *world, int x, int y) {
    return x >= 0 && y >= 0 && x < world->width && y < world->height;
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

    enemy_position.x = player_position.x + 2;
    enemy_position.y = player_position.y;
    if (!world_is_walkable(world, enemy_position.x, enemy_position.y)) {
        enemy_position.x = player_position.x - 2;
    }
    if (!world_is_walkable(world, enemy_position.x, enemy_position.y)) {
        enemy_position.x = player_position.x;
        enemy_position.y = player_position.y + 1;
    }

    world->enemy = entity_store_create(&world->entities, enemy_position);
}

int world_is_walkable(const World *world, int x, int y) {
    if (world == 0 || !world_in_bounds(world, x, y)) {
        return 0;
    }
    return world->tiles[y][x] != '#';
}
