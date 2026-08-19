#ifndef GAME_ENGINE_COMMAND_COMMAND_H
#define GAME_ENGINE_COMMAND_COMMAND_H

typedef enum {
    COMMAND_NONE = 0,
    COMMAND_MOVE_UP,
    COMMAND_MOVE_DOWN,
    COMMAND_MOVE_LEFT,
    COMMAND_MOVE_RIGHT,
    COMMAND_WAIT,
    COMMAND_QUIT
} CommandType;

typedef struct {
    CommandType type;
} Command;

typedef enum {
    KEY_UNKNOWN = 0,
    KEY_UP,
    KEY_DOWN,
    KEY_LEFT,
    KEY_RIGHT,
    KEY_W,
    KEY_A,
    KEY_S,
    KEY_D,
    KEY_ESCAPE,
    KEY_ENTER
} Key;

int command_from_key(Key key, Command *command);

#endif
