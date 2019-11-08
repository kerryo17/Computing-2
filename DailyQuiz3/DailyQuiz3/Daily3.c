/*
Author: Kerry O'Neill
Date: 1/29/18
Purpose: To practice with the left shift operator. 
I made a for loop using the left shift operator, and it moves
the value of x over one bit, and the for loop executes when x equals 0.
Time spent: 20 minutes
*/

#include <stdio.h>

int main() {
	unsigned int x=1;
	int i;
	for (i = 0; i<x; i++) {
		printf("%d: %u\n", i, x);
		x = x << 1;
	}
	return 0;
}