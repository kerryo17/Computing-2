#include "status.h"
#ifndef QUEUE_H
#define QUEUE_H

typedef void* QUEUE;

QUEUE queue_init_default(void);

Status queue_enqueue(QUEUE hQueue, int item);

Status queue_dequeue(QUEUE hQueue);

int queue_front(QUEUE hQueue);

Boolean queue_is_empty(QUEUE hQueue);

void queue_destroy(QUEUE* phQueue);

#endif