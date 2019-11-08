/*
Author: Kerry O'Neill
Date: 3/19/18 (version 3)
Time spent: 5 hours with help
Purpose: Prompts a user how many strings they want printed, prints said strings.
*/
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int evaluate();
void clearbuffer();

int main(int argc, char* argv[])
{
	int i, n;
	printf("How many strings would you like printed?");
	scanf("%d", &n);
	clearbuffer();

	for (i = 0; i < n; i++){
		if (evaluate() == 0)
			printf("Yes.\n");

		else
			printf("No.\n");
	}

	system("pause");
	return 0;
}

int evaluate()
{
	STACK h = constructor();
	char c;
	int n = scanf("%c", &c);
	int rand = 1;

	while (n > 0 && rand == 1 && c != '\n')
	{
		if (c == '(' || c == '[' || c == '{' || c == ')' || c == ']' || c == '}') {
			push(h, c);
		}
		if (c == '(' || c == '[' || c == '{'){
			if (top(h, NULL) != ('(' || '[' || '{')){
				rand = 0;
			}
			else{
				pop(h);
			}
		}
	}
	if (!empty(h)) {
		rand = 0;
	}
	if (n == 1 && c != '\n') {
		clearBuffer();
	}
	destroy(&h);
	return rand;
}

void clearbuffer() {
	char c = ' ';
	do {
		scanf("%c", &c);
	} while (c != '\n');
}

