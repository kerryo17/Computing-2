#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

struct node;

typedef struct node Node;

struct node{
	int data;
	Node* next;
};

struct queue{
	Node* head;
	Node* tail;
};

typedef struct queue Queue;

QUEUE queue_init_default(void){
	Queue* pQueue;
	pQueue = (Queue*)malloc(sizeof(Queue));

	if (pQueue != NULL){
		pQueue->head = NULL;
		pQueue->tail = NULL;
	}
	return pQueue;
}

Status queue_enqueue(QUEUE hQueue, int item){
	Queue* pQueue = (Queue*)hQueue;
	Node* temp;

	temp = (Node*)malloc(sizeof(Node));

	if (temp == NULL){
		return FAILURE;
	}

	temp->data = item;
	temp->next = NULL;

	if (pQueue->tail == NULL){
		pQueue->head = temp;
		pQueue->tail = temp;
		return SUCCESS;
	}
	pQueue->tail->next = temp;
	pQueue->tail = temp;

	return SUCCESS;
}

Status queue_dequeue(QUEUE hQueue){
	Queue* pQueue = (Queue*)hQueue;
	Node* temp;

	if (pQueue->head == NULL){
		return FAILURE;
	}

	temp = pQueue->head;
	pQueue->head = pQueue->head->next;
	free(temp);

	return SUCCESS;
}

int queue_front(QUEUE hQueue){
	Queue* pQueue = (Queue*)hQueue;

	return pQueue->head->data;
}

Boolean queue_is_empty(QUEUE hQueue){
	Queue* pQueue = (Queue*)hQueue;

	return (Boolean)(pQueue->head == NULL);
}

void queue_destroy(QUEUE* phQueue){
	Queue* pQueue = (Queue*)*phQueue;
	Node* temp = pQueue->head;

	while (temp != NULL){
		pQueue->head = pQueue->head->next;
		free(temp);
		temp = pQueue->head;
	}

	free(pQueue);
	*phQueue = NULL;

	return;
}