#ifndef GAME_PLATFORM_TERMINAL_TERMINAL_H
#define GAME_PLATFORM_TERMINAL_TERMINAL_H

typedef struct {
    int initialized;
} Terminal;

int terminal_init(Terminal *terminal);
void terminal_clear(Terminal *terminal);
void terminal_move_cursor(Terminal *terminal, int x, int y);
void terminal_put_char(Terminal *terminal, int x, int y, char ch);
void terminal_put_text(Terminal *terminal, int x, int y, const char *text);
void terminal_flush(Terminal *terminal);
void terminal_shutdown(Terminal *terminal);

#endif
