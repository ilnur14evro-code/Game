#include "engine/render/render.h"

void render_buffer_clear(RenderBuffer *buffer, int width, int height, char fill) {
    int x;
    int y;

    if (buffer == 0) {
        return;
    }

    if (width < 1) width = 1;
    if (height < 1) height = 1;
    if (width > RENDER_MAX_WIDTH) width = RENDER_MAX_WIDTH;
    if (height > RENDER_MAX_HEIGHT) height = RENDER_MAX_HEIGHT;

    buffer->width = width;
    buffer->height = height;

    for (y = 0; y < height; ++y) {
        for (x = 0; x < width; ++x) {
            buffer->cells[y][x] = fill;
        }
    }
}

void render_world(const World *world, RenderBuffer *buffer) {
    int x;
    int y;
    Position player;
    Position enemy;

    if (world == 0 || buffer == 0) {
        return;
    }

    render_buffer_clear(buffer, world->width, world->height, ' ');

    for (y = 0; y < world->height; ++y) {
        for (x = 0; x < world->width; ++x) {
            buffer->cells[y][x] = world->tiles[y][x];
        }
    }

    if (entity_store_get_position(&world->entities, world->player, &player) &&
        player.x >= 0 && player.x < buffer->width &&
        player.y >= 0 && player.y < buffer->height) {
        buffer->cells[player.y][player.x] = '@';
    }

    if (entity_store_get_position(&world->entities, world->enemy, &enemy) &&
        enemy.x >= 0 && enemy.x < buffer->width &&
        enemy.y >= 0 && enemy.y < buffer->height) {
        buffer->cells[enemy.y][enemy.x] = 'g';
    }
}
