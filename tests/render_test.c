#include "engine/render/render.h"

#include <assert.h>

int main(void) {
    World world;
    RenderBuffer buffer;
    int cx;
    int cy;

    world_init(&world, 8, 6);
    cx = world.player.x;
    cy = world.player.y;

    render_world(&world, &buffer);

    assert(buffer.width == 8);
    assert(buffer.height == 6);
    assert(buffer.cells[0][0] == '#');
    assert(buffer.cells[cy][cx] == '@');
    assert(buffer.cells[1][1] == '.');

    return 0;
}
