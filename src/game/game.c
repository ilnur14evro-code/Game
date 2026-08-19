#include "game/game.h"

int game_init(Game *game) {
    if (game == 0) {
        return 0;
    }

    game->finished = 0;
    turn_manager_init(&game->turn_manager);
    event_queue_init(&game->events);
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

    if (!turn_manager_process(&game->turn_manager, &game->world, command, &game->events)) {
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
