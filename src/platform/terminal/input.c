#include "platform/terminal/input.h"

#if defined(__unix__) || defined(__APPLE__)
#include <termios.h>
#include <unistd.h>

static int read_byte(unsigned char *value) {
    return read(STDIN_FILENO, value, 1) == 1;
}

int input_read_key(Terminal *terminal, Key *key) {
    struct termios original;
    struct termios raw;
    unsigned char byte;

    if (terminal == 0 || key == 0 || !terminal->initialized) return 0;
    if (tcgetattr(STDIN_FILENO, &original) != 0) return 0;

    raw = original;
    raw.c_lflag &= (tcflag_t) ~(ICANON | ECHO);
    raw.c_cc[VMIN] = 1;
    raw.c_cc[VTIME] = 0;

    if (tcsetattr(STDIN_FILENO, TCSANOW, &raw) != 0) return 0;

    if (!read_byte(&byte)) {
        tcsetattr(STDIN_FILENO, TCSANOW, &original);
        return 0;
    }

    if (byte == '\033') {
        unsigned char second;
        unsigned char third;
        if (read_byte(&second) && second == '[' && read_byte(&third)) {
            switch (third) {
                case 'A': *key = KEY_UP; break;
                case 'B': *key = KEY_DOWN; break;
                case 'C': *key = KEY_RIGHT; break;
                case 'D': *key = KEY_LEFT; break;
                default: *key = KEY_ESCAPE; break;
            }
        } else {
            *key = KEY_ESCAPE;
        }
    } else {
        switch (byte) {
            case 'w': case 'W': *key = KEY_W; break;
            case 'a': case 'A': *key = KEY_A; break;
            case 's': case 'S': *key = KEY_S; break;
            case 'd': case 'D': *key = KEY_D; break;
            case '\n': case '\r': *key = KEY_ENTER; break;
            default: *key = KEY_UNKNOWN; break;
        }
    }

    tcsetattr(STDIN_FILENO, TCSANOW, &original);
    return 1;
}
#else
int input_read_key(Terminal *terminal, Key *key) {
    (void)terminal;
    (void)key;
    return 0;
}
#endif
