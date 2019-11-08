#ifndef STACK_H
#define STACK_H

typedef void* STACK;
typedef enum Status { FAILURE, SUCCESS }STATUS;
typedef enum boolean { FALSE, TRUE }BOOLEAN;

STACK constructor();

STATUS push(STACK hStack, char data);

STATUS pop(STACK hStack);

char top(STACK hStack, int* var);

STATUS empty(STACK hStack);

void destroy(STACK* phStack);

#endif