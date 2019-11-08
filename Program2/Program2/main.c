/*
Author: Kerry O'Neill
Date: 6/17/18
Purpose: To practice with queues
Effort: 2 weeks, had help
*/

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void ferry_simulate(void);
void clear_keyboard_buffer(void);

int main(int argc, char* argv[]){
	int test_cases;
	scanf("%d", &test_cases);
	clear_keyboard_buffer();

	for (int i = 0; i < test_cases; i++){
		ferry_simulate();
	}

	return 0;
}

void ferry_simulate(void){
	int ferry_length;
	int num_cars;
	int which_side;
	int times_crossed = 0;
	int length; 
	int car_length;
	char side;

	QUEUE hQueueleft, hQueueright;

	hQueueleft = queue_init_default();
	hQueueright = queue_init_default();

	scanf("%d", &ferry_length);
	ferry_length *= 100;

	scanf("%d", &num_cars);
	clear_keyboard_buffer();

	for (int i = 0; i < num_cars; i++){

		scanf("%d", &car_length);
		scanf(" %c", &side);

		if (side == 'r'){
			queue_enqueue(hQueueright, car_length);
		}
		else if (side == 'l'){
			queue_enqueue(hQueueleft, car_length);
		}
		clear_keyboard_buffer();
	}

	length = ferry_length;

	for (which_side = 0; ((!(queue_is_empty(hQueueleft))) || (!(queue_is_empty(hQueueright)))); which_side = !which_side){

		if (which_side == 0){
			while ((!(queue_is_empty(hQueueleft))) && (length - queue_front(hQueueleft) >= 0)){
				length -= queue_front(hQueueleft);
				queue_dequeue(hQueueleft);
			}

			times_crossed++;
		}

		else{
			while ((!(queue_is_empty(hQueueright))) && (length - queue_front(hQueueright) >= 0)){
				length -= queue_front(hQueueright);
				queue_dequeue(hQueueright);
			}

			times_crossed++;
		}
		length = ferry_length;
	}

	printf("%d\n", times_crossed);

	queue_destroy(&hQueueleft);
	queue_destroy(&hQueueright);

	return;
}

void clear_keyboard_buffer(void){
	char c;
	int noc;

	do{
		noc = scanf("%c", &c);
	} while (noc == 1 && c != '\n');
}