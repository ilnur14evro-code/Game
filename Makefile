CC ?= cc
CFLAGS ?= -std=c11 -Wall -Wextra -Wpedantic -I./src

ENGINE_SRCS = \
	src/engine/core/game.c \
	src/engine/world/world.c \
	src/engine/entity/entity_store.c \
	src/engine/command/command.c \
	src/engine/system/movement/movement.c \
	src/engine/system/ai/ai.c \
	src/engine/turn/turn.c \
	src/engine/render/render.c

PLATFORM_SRCS = \
	src/platform/terminal/terminal.c \
	src/platform/terminal/input.c

.PHONY: all game test architecture-check clean

all: game

game: $(ENGINE_SRCS) $(PLATFORM_SRCS) src/main.c
	$(CC) $(CFLAGS) $^ -o $@

test: architecture-check entity-test world-test command-test movement-test turn-test ai-test render-test

architecture-check:
	! grep -R -nE '#include[[:space:]]+"platform/terminal/|#include[[:space:]]+<termios\.h>|#include[[:space:]]+<unistd\.h>' src/engine

entity-test: tests/entity_store_test.c src/engine/entity/entity_store.c
	$(CC) $(CFLAGS) $^ -o entity_store_test
	./entity_store_test

world-test: tests/world_test.c src/engine/world/world.c src/engine/entity/entity_store.c
	$(CC) $(CFLAGS) $^ -o world_test
	./world_test

command-test: tests/command_test.c src/engine/command/command.c
	$(CC) $(CFLAGS) $^ -o command_test
	./command_test

movement-test: tests/movement_test.c src/engine/system/movement/movement.c src/engine/entity/entity_store.c src/engine/world/world.c
	$(CC) $(CFLAGS) $^ -o movement_test
	./movement_test

turn-test: tests/turn_test.c src/engine/turn/turn.c src/engine/system/ai/ai.c src/engine/system/movement/movement.c src/engine/entity/entity_store.c src/engine/world/world.c
	$(CC) $(CFLAGS) $^ -o turn_test
	./turn_test

ai-test: tests/ai_test.c src/engine/system/ai/ai.c src/engine/system/movement/movement.c src/engine/entity/entity_store.c src/engine/world/world.c
	$(CC) $(CFLAGS) $^ -o ai_test
	./ai_test

render-test: tests/render_test.c src/engine/render/render.c src/engine/entity/entity_store.c src/engine/world/world.c
	$(CC) $(CFLAGS) $^ -o render_test
	./render_test

clean:
	rm -f game entity_store_test world_test command_test movement_test turn_test ai_test render_test
