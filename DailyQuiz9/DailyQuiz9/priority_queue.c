#include <stdio.h>
#include <stdlib.h>
#include "priority_queue.h"

typedef struct element {
	int data;
	int priority;
}Element;

typedef struct pQueue {
	int size;
	int capacity;
	Element* item;
}p_queue;

PRIORITY_QUEUE priority_queue_init_default(void) {
	p_queue* pQueue;
	pQueue = (p_queue*)malloc(sizeof(p_queue));
	if (pQueue == NULL) {
		printf("Failed to create an object.\n");
		exit(1);
	}
	if (pQueue != NULL) {
		pQueue->capacity = 5;
		pQueue->size = 0;
		pQueue->item = (Element*)malloc(sizeof(Element)* pQueue->capacity);
		if (pQueue->item == NULL) {
			printf("Failed.\n");
			free(pQueue);
			pQueue = NULL;
		}
	}
	return (PRIORITY_QUEUE)pQueue;
}

Status priority_queue_insert(PRIORITY_QUEUE hQueue, int priority_level, int data_item) {
	p_queue* pQueue = (p_queue*)hQueue;
	Element* temp;
	int i, p_index, index;
	Element var_temp;

	if (pQueue->size == pQueue->capacity) {
		temp = (Element*)malloc(sizeof(Element) * 2 * pQueue->capacity);
		if (temp == NULL) {
			return FAILURE;
		}

		for (i = 0; i < pQueue->capacity; i++) {
			temp[i] = pQueue->item[i];
		}
		free(pQueue->item);
		pQueue->item = temp;
		pQueue->capacity *= 2;
	}
	pQueue->item[pQueue->size].data = data_item;
	pQueue->item[pQueue->size].priority = priority_level;

	p_index = ((pQueue->size - 1) / 2);
	index = pQueue->size;
	while (p_index >= 0 && pQueue->item[index].priority > pQueue->item[p_index].priority) {
		var_temp = pQueue->item[index];
		pQueue->item[index] = pQueue->item[p_index];
		pQueue->item[p_index] = var_temp;
		index = p_index;
		p_index = ((p_index - 1) / 2);
	}
	pQueue->size++;
	return SUCCESS;
}

Status priority_queue_service(PRIORITY_QUEUE hQueue) {
	p_queue* pQueue = (p_queue*)hQueue;
	Element temp1, temp2;
	Boolean fix_down = TRUE;
	int left_index, right_index;
	int index = 0;

	if (pQueue->size <= 0) {
		return FAILURE;
	}

	temp1 = pQueue->item[0];
	pQueue->item[0] = pQueue->item[pQueue->size - 1];
	pQueue->item[pQueue->size - 1] = temp1;
	pQueue->size--;
	while (fix_down) {
		left_index = (index * 2 + 1);
		right_index = (index * 2 + 2);

		if (right_index >= pQueue->size && left_index < pQueue->size) {
			if (pQueue->item[left_index].priority > pQueue->item[index].priority) {
				temp2 = pQueue->item[index];
				pQueue->item[index] = pQueue->item[left_index];
				pQueue->item[left_index] = temp2;
			}

			fix_down = FALSE;
		}
		else if (right_index < pQueue->size) {

			int max_index = pQueue->item[left_index].priority > pQueue->item[right_index].priority ?
				left_index : right_index;

			if (pQueue->item[max_index].priority > pQueue->item[index].priority) {
				temp2 = pQueue->item[index];
				pQueue->item[index] = pQueue->item[max_index];
				pQueue->item[max_index] = temp2;
				index = max_index;
				fix_down = TRUE;
			}
			else {
				fix_down = FALSE;
			}
		}
		else {
			fix_down = FALSE;
		}
	}

	return SUCCESS;
}

int priority_queue_front(PRIORITY_QUEUE hQueue, Status* status) {
	p_queue* pQueue = (p_queue*)hQueue;
	if (pQueue->size <= 0) {
		if (status != NULL) {
			*status = FAILURE;
		}
		return -1337;
	}
	if (status != NULL) {
		*status = SUCCESS;
	}
	return pQueue->item[0].data;
}

Boolean priority_queue_is_empty(PRIORITY_QUEUE hQueue) {
	p_queue* pQueue = (p_queue*)hQueue;
	if (pQueue->size == 0) {
		return TRUE;
	}
	return FALSE;
}

void priority_queue_destroy(PRIORITY_QUEUE* phQueue) {
	p_queue* pQueue = (p_queue*)*phQueue;
	free(pQueue->item);
	free(pQueue);
	*phQueue = NULL;
	return;
}