CC ?= cc
CFLAGS ?= -std=c11 -Wall -Wextra -Wpedantic -I./src

ENGINE_SRCS = \
	src/engine/core/game.c \
	src/engine/world/world.c \
	src/engine/command/command.c \
	src/engine/turn/turn.c \
	src/engine/render/render.c

PLATFORM_SRCS = \
	src/platform/terminal/terminal.c \
	src/platform/terminal/input.c

.PHONY: all game test clean

all: game

game: $(ENGINE_SRCS) $(PLATFORM_SRCS) src/main.c
	$(CC) $(CFLAGS) $^ -o $@

test: world-test command-test turn-test render-test

world-test: tests/world_test.c src/engine/world/world.c
	$(CC) $(CFLAGS) $^ -o world_test
	./world_test

command-test: tests/command_test.c src/engine/command/command.c
	$(CC) $(CFLAGS) $^ -o command_test
	./command_test

turn-test: tests/turn_test.c src/engine/turn/turn.c src/engine/world/world.c
	$(CC) $(CFLAGS) $^ -o turn_test
	./turn_test

render-test: tests/render_test.c src/engine/render/render.c src/engine/world/world.c
	$(CC) $(CFLAGS) $^ -o render_test
	./render_test

clean:
	rm -f game world_test command_test turn_test render_test
