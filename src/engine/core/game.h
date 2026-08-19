#ifndef GAME_ENGINE_CORE_GAME_H
#define GAME_ENGINE_CORE_GAME_H

#include "engine/command/command.h"
#include "engine/render/render.h"
#include "engine/world/world.h"

typedef struct {
    World world;
    RenderBuffer render_buffer;
    int finished;
} Game;

int game_init(Game *game);
int game_process_key(Game *game, Key key);
const RenderBuffer *game_render_buffer(const Game *game);

#endif
