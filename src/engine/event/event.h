#ifndef GAME_ENGINE_EVENT_EVENT_H
#define GAME_ENGINE_EVENT_EVENT_H

typedef enum {
    EVENT_NONE = 0,
    EVENT_ENTITY_MOVED,
    EVENT_ENTITY_ATTACKED,
    EVENT_ENTITY_DAMAGED,
    EVENT_ENTITY_DIED
} EventType;

typedef struct {
    EventType type;
    unsigned int entity;
    unsigned int target;
    int x;
    int y;
    int value;
} Event;

#endif
