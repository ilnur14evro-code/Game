#include "platform/terminal/terminal.h"

#include <stdio.h>

int terminal_init(Terminal *terminal) {
    if (terminal == 0) return 0;
    terminal->initialized = 1;
    return 1;
}

void terminal_clear(Terminal *terminal) {
    if (terminal == 0 || !terminal->initialized) return;
    fputs("\033[2J\033[H", stdout);
}

void terminal_move_cursor(Terminal *terminal, int x, int y) {
    if (terminal == 0 || !terminal->initialized) return;
    printf("\033[%d;%dH", y + 1, x + 1);
}

void terminal_put_char(Terminal *terminal, int x, int y, char ch) {
    if (terminal == 0 || !terminal->initialized) return;
    terminal_move_cursor(terminal, x, y);
    fputc(ch, stdout);
}

void terminal_put_text(Terminal *terminal, int x, int y, const char *text) {
    if (terminal == 0 || !terminal->initialized || text == 0) return;
    terminal_move_cursor(terminal, x, y);
    fputs(text, stdout);
}

void terminal_flush(Terminal *terminal) {
    if (terminal == 0 || !terminal->initialized) return;
    fflush(stdout);
}

void terminal_shutdown(Terminal *terminal) {
    if (terminal == 0) return;
    terminal->initialized = 0;
}
