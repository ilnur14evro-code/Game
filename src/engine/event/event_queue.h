#ifndef GAME_ENGINE_EVENT_EVENT_QUEUE_H
#define GAME_ENGINE_EVENT_EVENT_QUEUE_H

#include "engine/event/event.h"

#define EVENT_QUEUE_CAPACITY 64

typedef struct {
    Event items[EVENT_QUEUE_CAPACITY];
    int head;
    int tail;
    int count;
} EventQueue;

void event_queue_init(EventQueue *queue);
int event_queue_push(EventQueue *queue, Event event);
int event_queue_pop(EventQueue *queue, Event *event);
int event_queue_is_empty(const EventQueue *queue);

#endif
