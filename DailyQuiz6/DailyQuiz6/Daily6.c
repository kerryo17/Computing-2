/*
Author: Kerry O'Neill
Date: 2/5/18
Purpose:To practice more with the bitwise operator, and expand
on our previous daily quizzes.
Effort:1 hour, had help from suitemate
*/

#include <stdio.h>
void set_flag(unsigned int flag_holder[], int flag_position);
void unset_flag(unsigned int flag_holder[], int flag_position);
int check_flag(unsigned int flag_holder[], int flag_position);
void display_32_flags_as_array(unsigned int flag_holder);
void display_flags(unsigned int flag_holder[], int size);

int main(int argc, char* argv[]){
	unsigned int flag_holder[5] = { 0 };
	
	set_flag(flag_holder, 3);
	set_flag(flag_holder, 16);
	set_flag(flag_holder, 31);
	set_flag(flag_holder, 87);
	display_flags(flag_holder, 5);
	printf("\n\n");
	unset_flag(flag_holder, 31);
	unset_flag(flag_holder, 3);
	set_flag(flag_holder, 99);
	set_flag(flag_holder, 100);
	display_flags(flag_holder, 5);
	system("pause");
	return 0;

}

void set_flag(unsigned int flag_holder[], int flag_position) {
	int arr;
	arr= flag_position / 32;
	flag_holder[arr] = flag_holder[arr] | (1 << flag_position);
}

void unset_flag(unsigned int flag_holder[], int flag_position) {
	*flag_holder = *flag_holder ^ (1 << flag_position);
	return *flag_holder;
}

int check_flag(unsigned int flag_holder[], int flag_position) {
	return abs((*flag_holder & (1 << flag_position)) >> flag_position);
}

void display_32_flags_as_array(unsigned int flag_holder) {
	for (int i = 0; i <= 31; i++) {
		printf("%d", check_flag(&flag_holder, i));
		if (i % 4 == 3) {
				printf(" ");
			}
	}
	printf("\n");
}

void display_flags(unsigned int flag_holder[], int size) {
	for (int i = 0; i < size; i++) {
		unsigned int a = flag_holder[i];
		display_32_flags_as_array(a);
	}
}
