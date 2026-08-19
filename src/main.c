#include "engine/core/game.h"
#include "platform/terminal/input.h"
#include "platform/terminal/terminal.h"

#include <stdio.h>

int main(void) {
    Game game = {0};
    Terminal terminal = {0};

    if (!terminal_init(&terminal)) {
        fprintf(stderr, "Failed to initialize terminal\n");
        return 1;
    }

    if (!game_init(&game, &terminal)) {
        terminal_shutdown(&terminal);
        fprintf(stderr, "Failed to initialize game\n");
        return 1;
    }

    while (!game.finished) {
        Key key;
        if (!input_read_key(&terminal, &key)) {
            game.finished = 1;
            break;
        }

        if (!game_process_key(&game, key)) {
            game.finished = 1;
        }
    }

    terminal_shutdown(&terminal);
    return 0;
}
