#include "engine/system/ai/ai.h"

#include <assert.h>

int main(void) {
    World world;
    Position player;
    Position enemy;

    world_init(&world, 12, 6);
    assert(entity_store_get_position(&world.entities, world.player, &player) == 1);
    assert(entity_store_get_position(&world.entities, world.enemy, &enemy) == 1);

    assert(ai_system_take_enemy_turn(&world) == 1);
    assert(entity_store_get_position(&world.entities, world.enemy, &enemy) == 1);
    assert(enemy.x == player.x + 1);
    assert(enemy.y == player.y);

    assert(ai_system_take_enemy_turn(&world) == 0);
    return 0;
}
