#include "engine/render/render.h"

void render_game(Terminal *terminal, const World *world) {
    int x;
    int y;

    if (terminal == 0 || world == 0) {
        return;
    }

    terminal_clear(terminal);
    for (y = 0; y < world->height; ++y) {
        for (x = 0; x < world->width; ++x) {
            char ch = world->tiles[y][x];
            if (world->player.x == x && world->player.y == y) {
                ch = '@';
            }
            terminal_put_char(terminal, x, y, ch);
        }
    }
    terminal_flush(terminal);
}
