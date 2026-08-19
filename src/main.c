#include "engine/core/game.h"
#include "platform/terminal/input.h"
#include "platform/terminal/terminal.h"

#include <stdio.h>

static void terminal_render_buffer(Terminal *terminal, const RenderBuffer *buffer) {
    int x;
    int y;

    if (terminal == 0 || buffer == 0) {
        return;
    }

    terminal_clear(terminal);
    for (y = 0; y < buffer->height; ++y) {
        for (x = 0; x < buffer->width; ++x) {
            terminal_put_char(terminal, x, y, buffer->cells[y][x]);
        }
    }
    terminal_flush(terminal);
}

int main(void) {
    Game game = {0};
    Terminal terminal = {0};

    if (!terminal_init(&terminal)) {
        fprintf(stderr, "Failed to initialize terminal\n");
        return 1;
    }

    if (!game_init(&game)) {
        terminal_shutdown(&terminal);
        fprintf(stderr, "Failed to initialize game\n");
        return 1;
    }

    terminal_render_buffer(&terminal, game_render_buffer(&game));

    while (!game.finished) {
        Key key;
        if (!input_read_key(&terminal, &key)) {
            game.finished = 1;
            break;
        }

        if (!game_process_key(&game, key)) {
            game.finished = 1;
            break;
        }

        terminal_render_buffer(&terminal, game_render_buffer(&game));
    }

    terminal_shutdown(&terminal);
    return 0;
}
