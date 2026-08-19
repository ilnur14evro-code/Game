#ifndef GAME_PLATFORM_TERMINAL_INPUT_H
#define GAME_PLATFORM_TERMINAL_INPUT_H

#include "engine/command/command.h"
#include "platform/terminal/terminal.h"

int input_read_key(Terminal *terminal, Key *key);

#endif
