#include "engine/command/command.h"

#include <assert.h>

int main(void) {
    Command command;

    assert(command_from_key(KEY_W, &command) == 1);
    assert(command.type == COMMAND_MOVE_UP);
    assert(command_from_key(KEY_S, &command) == 1);
    assert(command.type == COMMAND_MOVE_DOWN);
    assert(command_from_key(KEY_A, &command) == 1);
    assert(command.type == COMMAND_MOVE_LEFT);
    assert(command_from_key(KEY_D, &command) == 1);
    assert(command.type == COMMAND_MOVE_RIGHT);
    assert(command_from_key(KEY_ENTER, &command) == 1);
    assert(command.type == COMMAND_WAIT);
    assert(command_from_key(KEY_ESCAPE, &command) == 1);
    assert(command.type == COMMAND_QUIT);
    assert(command_from_key(KEY_UNKNOWN, &command) == 0);
    return 0;
}
