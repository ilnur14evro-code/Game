#include "engine/render/render.h"

#include <assert.h>

int main(void) {
    World world;
    RenderBuffer buffer;
    Position player;
    Position enemy;

    world_init(&world, 8, 6);
    assert(entity_store_get_position(&world.entities, world.player, &player) == 1);
    assert(entity_store_get_position(&world.entities, world.enemy, &enemy) == 1);

    render_world(&world, &buffer);

    assert(buffer.width == 8);
    assert(buffer.height == 6);
    assert(buffer.cells[0][0] == '#');
    assert(buffer.cells[player.y][player.x] == '@');
    assert(buffer.cells[enemy.y][enemy.x] == 'g');
    assert(buffer.cells[1][1] == '.');
    return 0;
}
