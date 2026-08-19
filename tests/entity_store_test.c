#include "engine/entity/entity_store.h"

#include <assert.h>

int main(void) {
    EntityStore store;
    Position start = {2, 3};
    Position current = {0, 0};
    EntityId entity;

    entity_store_init(&store);
    entity = entity_store_create(&store, start);

    assert(entity != ENTITY_INVALID);
    assert(entity_store_is_alive(&store, entity) == 1);
    assert(entity_store_get_position(&store, entity, &current) == 1);
    assert(current.x == 2);
    assert(current.y == 3);

    current.x = 4;
    current.y = 5;
    assert(entity_store_set_position(&store, entity, current) == 1);
    assert(entity_store_get_position(&store, entity, &current) == 1);
    assert(current.x == 4);
    assert(current.y == 5);

    assert(entity_store_is_alive(&store, ENTITY_INVALID) == 0);
    return 0;
}
