/*
Author: Kerry O'Neill
Date: 2/12/18
Purpose: To practice with nodes, and to reverse a linked list.
Effort: 1 hr
*/

#include <stdio.h>
#include <stdlib.h>

struct node;
typedef struct node Node;

struct node
{
	int data;
	Node* next;
};

void reverse(Node **pStart);

int main(int argc, char* argv[])
{
	Node* head = NULL;
	int i;
	Node* temp;

	//set up a test list with values 9->8->7->...->0
	for (i = 0; i < 10; i++)
	{
		temp = (Node*)malloc(sizeof(Node));
		if (temp == NULL)
		{
			printf("out of memory?\n");
			exit(1);
		}
		temp->data = i;
		temp->next = head;
		head = temp;
	}

	//call your function to reverse the list (should work for any list given the head node).
	reverse(&head);

	//print the reversed list.
	temp = head;
	while (temp != NULL)
	{
		printf("%d\n", temp->data);
		temp = temp->next;
	}

	return 0;
}

void reverse(Node **pStart) {
	Node* start = *pStart;
	Node* new_list = start;
	Node *end;
	Node* secondToEnd;
	int shutoff = 1;
	while (new_list->next != NULL)
	{
		new_list = new_list->next;
	}
	while (shutoff){
		end = start;
		secondToEnd = start;
		while (end->next != NULL){
			end = end->next;
		}
		if (start->next == NULL) {
			end->next = NULL;
			shutoff = 0;
			*pStart = new_list;
		}
		else{
			while (secondToEnd->next->next != NULL){
				secondToEnd = secondToEnd->next;
			}
			
			end->next = secondToEnd;
			secondToEnd->next = NULL;
		}
	}
}