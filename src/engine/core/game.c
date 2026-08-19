#include "engine/core/game.h"

#include "engine/command/command.h"
#include "engine/turn/turn.h"

int game_init(Game *game) {
    if (game == 0) {
        return 0;
    }

    game->finished = 0;
    world_init(&game->world, 20, 10);
    render_world(&game->world, &game->render_buffer);
    return 1;
}

int game_process_key(Game *game, Key key) {
    Command command;

    if (game == 0) {
        return 0;
    }

    if (!command_from_key(key, &command)) {
        return 1;
    }

    if (command.type == COMMAND_QUIT) {
        game->finished = 1;
        return 1;
    }

    if (!turn_process_command(&game->world, command)) {
        return 1;
    }

    render_world(&game->world, &game->render_buffer);
    return 1;
}

const RenderBuffer *game_render_buffer(const Game *game) {
    if (game == 0) {
        return 0;
    }
    return &game->render_buffer;
}
