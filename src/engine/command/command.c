#include "engine/command/command.h"

int command_from_key(Key key, Command *command) {
    if (command == 0) {
        return 0;
    }

    command->type = COMMAND_NONE;
    switch (key) {
        case KEY_UP:
        case KEY_W:
            command->type = COMMAND_MOVE_UP;
            break;
        case KEY_DOWN:
        case KEY_S:
            command->type = COMMAND_MOVE_DOWN;
            break;
        case KEY_LEFT:
        case KEY_A:
            command->type = COMMAND_MOVE_LEFT;
            break;
        case KEY_RIGHT:
        case KEY_D:
            command->type = COMMAND_MOVE_RIGHT;
            break;
        case KEY_ENTER:
            command->type = COMMAND_WAIT;
            break;
        case KEY_ESCAPE:
            command->type = COMMAND_QUIT;
            break;
        default:
            return 0;
    }

    return 1;
}
