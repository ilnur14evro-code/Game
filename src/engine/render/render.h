#ifndef GAME_ENGINE_RENDER_RENDER_H
#define GAME_ENGINE_RENDER_RENDER_H

#include "engine/world/world.h"

#define RENDER_MAX_WIDTH 128
#define RENDER_MAX_HEIGHT 128

typedef struct {
    int width;
    int height;
    char cells[RENDER_MAX_HEIGHT][RENDER_MAX_WIDTH];
} RenderBuffer;

void render_buffer_clear(RenderBuffer *buffer, int width, int height, char fill);
void render_world(const World *world, RenderBuffer *buffer);

#endif
