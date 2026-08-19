#include "engine/entity/entity_store.h"

void entity_store_init(EntityStore *store) {
    int i;

    if (store == 0) {
        return;
    }

    for (i = 0; i < ENTITY_MAX; ++i) {
        store->alive[i] = 0;
        store->positions[i].x = 0;
        store->positions[i].y = 0;
    }
}

EntityId entity_store_create(EntityStore *store, Position position) {
    int i;

    if (store == 0) {
        return ENTITY_INVALID;
    }

    for (i = 1; i < ENTITY_MAX; ++i) {
        if (!store->alive[i]) {
            store->alive[i] = 1;
            store->positions[i] = position;
            return (EntityId)i;
        }
    }

    return ENTITY_INVALID;
}

int entity_store_is_alive(const EntityStore *store, EntityId id) {
    if (store == 0 || id == ENTITY_INVALID || id >= ENTITY_MAX) {
        return 0;
    }

    return store->alive[id] != 0;
}

int entity_store_get_position(const EntityStore *store, EntityId id, Position *position) {
    if (!entity_store_is_alive(store, id) || position == 0) {
        return 0;
    }

    *position = store->positions[id];
    return 1;
}

int entity_store_set_position(EntityStore *store, EntityId id, Position position) {
    if (!entity_store_is_alive(store, id)) {
        return 0;
    }

    store->positions[id] = position;
    return 1;
}

int entity_store_find_at(const EntityStore *store, Position position, EntityId *entity) {
    int i;

    if (store == 0 || entity == 0) {
        return 0;
    }

    for (i = 1; i < ENTITY_MAX; ++i) {
        if (store->alive[i] && store->positions[i].x == position.x &&
            store->positions[i].y == position.y) {
            *entity = (EntityId)i;
            return 1;
        }
    }

    return 0;
}
