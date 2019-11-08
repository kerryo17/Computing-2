#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct node;
typedef struct node Node;

 struct node {
	char data;
	Node* next;
};

 typedef struct stack {
	 Node* head;
 }Stack;

 STACK constructor() {
	 Stack* s = (Stack*)malloc(sizeof(Stack));
	 if (s != NULL) {
		 s->head = NULL;
	 }
	 return s;
 }

 STATUS push(STACK h, char data) {//push function
	 Stack* s = (Stack*)h;
	 Node* temp = (Node*)malloc(sizeof(Node));
	 if (temp == NULL) {
		 printf("Out of memory. Return null");
		 return FAILURE;
	 }
	 temp->data = data;
	 temp->next = s->head;
	 s->head = temp;
	 return SUCCESS;
 }

 STATUS pop(STACK h) {
	 Stack* s = (Stack*)h;
	 if (s->head = NULL) {
		 return NULL;
	 }
	 Node* temp = s->head->next;
	 free(s->head);
	 return SUCCESS;
 }


 char top(STACK h, int* var)
 {
	 Stack* s = (Stack*)h;
	 if (s->head == NULL)
	 {
		 if (var != NULL)
			 *var = 0;
		 return '\0';
	 }
	 else
		 if (t != NULL)
			 *t = 1;

	 return s->head->data;
 }

 BOOLEAN empty(STACK h)
 {
	 Stack* s = (Stack*)h;
	 return (BOOLEAN)(s->head == NULL);
 }

 void destroy(STACK* h)
 {
	 Stack* s = (Stack*)h*;
	 Node* temp = s->head;
	 while (temp != NULL)
	 {
		 s->head = s->head->next;
		 free(temp);
		 temp = s->head;
	 }
	 free(s);
	 *h = NULL;
	 return;
 }