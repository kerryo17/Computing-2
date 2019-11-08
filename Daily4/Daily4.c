/*
Author: Kerry O'Neill
Date: 1/31/18
Effort: 1 hour
Purpose: To practice more with the bitwise function.
*/
#include <stdio.h>
void set_flag(int* flag_holder, int flag_position);
int check_flag(int flag_holder, int flag_position);
int main(int argc, char* argv[])
{
	int flag_holder = 0;
	int i;
	set_flag(&flag_holder, 3);
	set_flag(&flag_holder, 16);
	set_flag(&flag_holder, 31);
	for (i = 31; i >= 0; i--)
	{
		printf("%d", check_flag(flag_holder, i));
		if (i % 4 == 0)
		{
			printf(" ");
		}
	}
	printf("\n");
	return 0;
}

void set_flag(int* flag_holder, int flag_position) {
	int n = 1;
	if (!check_flag(*flag_holder, flag_position)) {	
		n = n << (flag_position);
		*flag_holder = *flag_holder + n;
	}
}

int check_flag(int flag_holder, int flag_position) {
	int n = 1;
	flag_holder = (flag_holder >> flag_position) & n;

	if (flag_holder == 1) {
		return 1;
	}
	else {
		return 0;
	}
}