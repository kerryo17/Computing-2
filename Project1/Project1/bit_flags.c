/*
Author: Kerry O'Neill
Date: 2/17/18
Effort: 3 hours
Interface proposal : Another function to the interface would be to add and remove data, and also check the capacity of the struct.
*/

#include <stdio.h>
#include <stdlib.h>
#include "bit_flags.h"

	struct bit_flags{
	int size;
	int capacity;
	unsigned int* data;
}; typedef struct bit_flags Bit_Flags;


		BIT_FLAGS bit_flags_init_number_of_bits(int number_of_bits){
			Bit_Flags* space = (BIT_FLAGS)malloc(number_of_bits);
			if (space != NULL){
				space->size = 0;
				space->capacity = number_of_bits;
				space->data = malloc(number_of_bits * space->capacity);
			}
			else if (space == NULL){
				free(space);
				space = NULL;
			}
			return space;
		}


		Status bit_flags_set_flag(BIT_FLAGS hBit_flags, int flag_position){
			unsigned int new = 1;
			unsigned int check;

			Bit_Flags* space = hBit_flags;
			if (flag_position > (space->capacity)){
				hBit_flags = realloc(hBit_flags, (flag_position - space->capacity));
				if (hBit_flags == NULL){
					return FAILURE;
				}
				space = hBit_flags;
			}
			if (flag_position > (space->size)){
				space->size = flag_position;
			}

			check = *space->data;

			new = new << (flag_position);

			check = check & new;
			if (check == 0){
				*space->data = *space->data + new;
			}

			return SUCCESS;
		}


		Status bit_flags_unset_flag(BIT_FLAGS hBit_flags, int flag_position){
			unsigned int new = 1;
			unsigned int check;

			Bit_Flags* space = hBit_flags;
			if (flag_position > (space->capacity)){
				hBit_flags = realloc(hBit_flags, (flag_position - space->capacity));
				if (hBit_flags == NULL){
					return FAILURE;
				}
				space = hBit_flags;
			}
			if (flag_position > (space->size)){
				space->size = flag_position;
			}

			check = *space->data;

			new = new << (flag_position);

			check = check & new;
			check = check >> flag_position;

			if (check == 1){
				*space->data = *space->data - new;
			}

			return SUCCESS;
		}


		int bit_flags_check_flag(BIT_FLAGS hBit_flags, int flag_position){
			unsigned int new = 1;
			unsigned int check;



			Bit_Flags* space = hBit_flags;
			if (flag_position > space->size){
				return -1;
			}


			check = *space->data;


			check = (check >> flag_position) & new;

			if (check == 1){
				return 1;
			}
			else{
				return 0;
			}
		}


		int bit_flags_get_size(BIT_FLAGS hBit_flags){
			Bit_Flags* end = hBit_flags;
			return (end->size);
		}


		int bit_flags_get_capacity(BIT_FLAGS hBit_flags){
			Bit_Flags* end = hBit_flags;
			return (end->capacity);
		}


		void bit_flags_destroy(BIT_FLAGS* phBit_flags){
			Bit_Flags* space = (Bit_Flags*)phBit_flags;
			free(space->data);
			free(space);
			phBit_flags = NULL;
			return;
		}

