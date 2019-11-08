/*
Author: Kerry O'Neill
Date: 4/12/18
Time spent: 4 days
Purpose: Practicing with priority queues, and using a heap data structure. 
*/


#include <stdio.h>
#include <stdlib.h>
#include "priority_queue.h"

int main(int argc, char* argv[])
{
	PRIORITY_QUEUE hPQueue;
	hPQueue = priority_queue_init_default();
	int i;

	for (i = 1; i < 101; i++)
	{
		int temp = rand();
		priority_queue_insert(hPQueue, i, temp);
		printf("Data: %d    Priority: %d\n", temp, i);
	}

	printf("\n");
	printf("***************************************\n");
	printf("\n");

	while (!priority_queue_is_empty(hPQueue))
	{
		printf("Priority Queue is not empty. Serviced: %d\n", priority_queue_front(hPQueue, NULL));
		priority_queue_service(hPQueue);
	}

	printf("\n");
	printf("Priority Queue is empty. Destroying the object now.\n");
	priority_queue_destroy(&hPQueue);
	return 0;
}