/*
Author: Kerry O'Neill
Date: 6/22/18
Purpose: Take any list of numbers, and sort through said list
to make sure there is no duplicates, or negative numbers.
Effort: 5 hours
*/


#include <stdio.h>
#include <stdlib.h>

struct node;
typedef struct node Node;

typedef struct node{
	int data;
	Node* next;
} qList;

int main(int argc, const char * argv[]){
	Node* head = NULL;
	Node* temp;
	Node* curr = head;
	Node* prev;
	int cont = 0;
	int num = -1;

	printf("Enter in numbers you want sorted.\n ");
	printf("The end result will have removed duplicates and non-negative integers.\n");
	printf("Enter in -1 when you are satisfied with your list.\n");

	while (cont == 0){
		scanf("%d", &num);
	
		if (num == -1){
			cont = 1;
		}
		if (num >= 0 && num <= 2000000000){
			temp = (Node*)malloc(sizeof(Node));
			if (temp == NULL){
				printf("Out of memory. Try again.");
				return -1;
			}
			temp->data = num;
			if (head == NULL){
				temp->next = head;
				head = temp;
			}
			else{
				curr = head;
				prev = NULL;
				while (curr != NULL && curr->next != NULL && curr->next->data < num){
					prev = curr;
					curr = curr->next;
				}
				if (curr->data < num && (curr->next == NULL || curr->next->data != num)){
					temp->next = curr->next;
					curr->next = temp;
				}
				else if (curr->data > num && (curr->next == NULL || curr->next->data != num)){
					if (prev != NULL){
						temp->next = prev->next;
						prev->next = temp;
					}
					else{
						temp->next = curr;
						curr = temp;
					}
					head = temp;
				}
			}
		}
	}
	printf("Here is the sorted list of numbers you inputted: \n");
	temp = head;
	while (temp != NULL){
		printf("%d\n", temp->data);
		temp = temp->next;
	}
	return 0;
}
