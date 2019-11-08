/*
Author: Kerry O'Neill
Date: 2/2/18
Purpose: Practice more with the bit-wise operator, and flip the bits of a number.
Effort: 30 mins
*/

#include <stdio.h>

#include <stdio.h>
void set_flag(int* flag_holder, int flag_position);
void unset_flag(unsigned int * flag_holder, int flag_positon);
void display_32_flags(unsigned int flag_holder);
int check_flag(int flag_holder, int flag_position);

int main(int argc, char* argv[])
{
	unsigned int flag_holder = 0;
	set_flag(&flag_holder, 3);
	set_flag(&flag_holder, 16);
	set_flag(&flag_holder, 31);
	display_32_flags(flag_holder);
	unset_flag(&flag_holder, 31);
	unset_flag(&flag_holder, 3);
	set_flag(&flag_holder, 9);
	display_32_flags(flag_holder);
	system("pause");
	return 0;
}

void set_flag(int* flag_holder, int flag_position) {
	int n = 1;
	n = n << (flag_position);
	*flag_holder = *flag_holder + n;
	return;
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

void unset_flag(unsigned int * flag_holder, int flag_positon) {

	 int new= 1;
	int check=*flag_holder;


	new = new << (flag_positon);
	check = (check >> flag_positon) & new;
	if (check != 1) {
		*flag_holder = *flag_holder - new;
			}
	return;
}

void display_32_flags(unsigned int flag_holder) {
	int i=0;
	for (i = 31; i >= 0; i--)
	{
		printf("%d", check_flag(flag_holder, i));
		if (i % 4 == 0)
		{
			printf(" ");
		}
	}
	printf("\n");
}