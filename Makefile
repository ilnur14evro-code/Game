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

test: tests/world_test.c src/engine/world/world.c
	$(CC) $(CFLAGS) $^ -o world_test
	./world_test

clean:
	rm -f game world_test
