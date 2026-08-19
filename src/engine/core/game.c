#include "engine/core/game.h"

#include "engine/command/command.h"
#include "engine/render/render.h"
#include "engine/turn/turn.h"

int game_init(Game *game, Terminal *terminal) {
    if (game == 0 || terminal == 0) {
        return 0;
    }

    game->terminal = terminal;
    game->finished = 0;
    world_init(&game->world, 20, 10);
    render_game(game->terminal, &game->world);
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

    render_game(game->terminal, &game->world);
    return 1;
}
