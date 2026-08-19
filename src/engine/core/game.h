#ifndef GAME_ENGINE_CORE_GAME_H
#define GAME_ENGINE_CORE_GAME_H

#include "engine/command/command.h"
#include "engine/world/world.h"
#include "platform/terminal/terminal.h"

typedef struct {
    World world;
    Terminal *terminal;
    int finished;
} Game;

int game_init(Game *game, Terminal *terminal);
int game_process_key(Game *game, Key key);

#endif
