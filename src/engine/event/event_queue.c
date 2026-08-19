#include "engine/event/event_queue.h"

void event_queue_init(EventQueue *queue) {
    if (queue == 0) {
        return;
    }

    queue->head = 0;
    queue->tail = 0;
    queue->count = 0;
}

int event_queue_push(EventQueue *queue, Event event) {
    if (queue == 0 || queue->count >= EVENT_QUEUE_CAPACITY) {
        return 0;
    }

    queue->items[queue->tail] = event;
    queue->tail = (queue->tail + 1) % EVENT_QUEUE_CAPACITY;
    queue->count += 1;
    return 1;
}

int event_queue_pop(EventQueue *queue, Event *event) {
    if (queue == 0 || event == 0 || queue->count == 0) {
        return 0;
    }

    *event = queue->items[queue->head];
    queue->head = (queue->head + 1) % EVENT_QUEUE_CAPACITY;
    queue->count -= 1;
    return 1;
}

int event_queue_is_empty(const EventQueue *queue) {
    return queue == 0 || queue->count == 0;
}
