/*
Author: Kerry O'Neill
Date: 1/24/17
Purpose: Prompts the user to input a positive number which is then 
used to declare the size of the array. The program than fills the array with
random numbers, and prints the index of the biggest element. 
Time Spent: 40 minutes
*/
#include <stdio.h>
#include <stdlib.h>

int find_max(int random[], int n);
void clear_kb_buffer();

int main(){
	int num, random[100];
	printf("Hello! Please enter in a positive integer: ");
	scanf("%d", &num);
	clear_kb_buffer();

	int a = (int*)malloc(sizeof(num) * 100);

	int b = num;
	do
	{
		b--;
		random[b] = rand();
	} while (b > 0);
	printf("The index of the largest element in the array is: %d\n", find_max(random, num));
	free(a);
	system("pause");
	return 0;
}

int find_max(int rand[], int num)
{
	int a, b = num;

	num--;
	a = rand[num];
	do
	{
		if (rand[num] > a)
		{
			a = rand[num];
			b = num;
		}
		num--;
	} while (num >= 0);
	return b;
}

void clear_kb_buffer()
{
	char c = ' ';
	do
	{
		scanf("%c", &c);
	} while (c != '\n');
}