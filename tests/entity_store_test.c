#include "engine/entity/entity_store.h"

#include <assert.h>

int main(void) {
    EntityStore store;
    Position first = {2, 3};
    Position second = {7, 4};
    Position actual;
    EntityId id;

    entity_store_init(&store);

    id = entity_store_create(&store, first);
    assert(id != ENTITY_INVALID);
    assert(entity_store_is_alive(&store, id) == 1);
    assert(entity_store_get_position(&store, id, &actual) == 1);
    assert(actual.x == 2);
    assert(actual.y == 3);

    assert(entity_store_set_position(&store, id, second) == 1);
    assert(entity_store_get_position(&store, id, &actual) == 1);
    assert(actual.x == 7);
    assert(actual.y == 4);

    assert(entity_store_is_alive(&store, ENTITY_INVALID) == 0);
    assert(entity_store_get_position(&store, ENTITY_INVALID, &actual) == 0);
    return 0;
}
