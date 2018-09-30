#include "stdafx.h"
#include "c_aux.h"
#include "c_aux_sort.h"
#include "c_aux_dlinked_list.h"
#include <stdint.h>

int c_aux_ui32_cmp(POD *a, POD *b) {

	if (a->ui32 > b->ui32) return 1;
	else if (a->ui32 == b->ui32) return 0;
	else return -1;

}
int c_aux_ui_cmp(uint32_t *a, uint32_t *b) {
	if (*a > *b) return 1;
	else if (*a == *b) return 0;
	else return -1;
}

c_aux_bubble_sort_dl(DLinkedList *l, int (*cfunc)(POD *a, POD *b )) {

	unsigned int len = dlinked_list_length(l);

	char has_swapped = 0;

	for (int i = 0; i < len-1 ; i++) {


		has_swapped = 0;


		for (int j = 0; j < len-i-1; j++) {
			DLinkedListNode *a = dlinked_list_node_at(l,j);
			DLinkedListNode *b = dlinked_list_node_at(l,j+1);

			if (cfunc(&a->data, &b->data) > 0) {
				dlinked_list_swap_data_index(l, j, j + 1);
				has_swapped = 1;

			}
			


		}
		if (!has_swapped) break;


	}



}
void* c_aux_addr(void * arr, unsigned int i, unsigned	int len, unsigned long size) {

	int8_t *carr = arr;

	_fassert(i < len, "Bounds...");

	return carr + i * size;


}
c_aux_insertion_sort_arr(void* arr, int len, int osize, int(*cfunc)(void *a, void *b)) {
	int8_t * carr = arr;
	int8_t *p = malloc(osize);

	for (int unsorted_index  = 1; unsorted_index < len; unsorted_index++) {
		int8_t *unsorted = carr + osize * unsorted_index;

		for (int i = 0; i < unsorted_index; i++) {
			int8_t *arri = carr + osize * i;
			// arr[i] > arr[unsorted]? insert unsorted at index i
			if (cfunc(arri, unsorted) > 0) {
				//copy unsorted
				memcpy(p, unsorted, osize);
				//shift i -> unsorted by one element
				// arr[unsorted - 1 - i]
				c_aux_shift_mem(arri, (unsorted_index-1-i)*osize, osize);
				//copy unsorted to sorted partition
				memcpy(arri, p, osize);
			}

		}

	}
	

}

c_aux_slection_sort_arr(void* arr, int len, int osize, int(*cfunc)(void *a, void *b)) {
	char * carr = arr;
	unsigned int index = 0;

	for (int i = 0; i < len-1; i++) {
		unsigned int smallestIndex = i;

		//Find smallest value for rest of array
		for (int j = i; j < len; j++) {
			
			//arr[smallest] index is bigger than arr[j]
			if (cfunc(carr + osize * smallestIndex, carr + osize * j) > 0) {

				smallestIndex = j;


			}
			
			

		}
		//swap smallest index with i
		c_aux_swap_mem(carr + osize * smallestIndex, carr + osize * i, osize);

	}



}

//Gerice bubble sort, takes an array of len length with size
c_aux_bubble_sort_arr(void* arr,int len, int osize, int(*cfunc)(void *a, void *b)) {

	int8_t * carr = arr;
	char has_swapped = 0;
	for (int i = 0; i < len - 1; i++) {


		has_swapped = 0;


		for (int j = 0; j < len - i - 1; j++) {
			

			if (cfunc(carr +osize*j, carr + osize * (j+1)) > 0) {
				
				char* arrj = carr + osize * j;
				char* arrj1 = carr + osize * (j + 1);

				c_aux_swap_mem(arrj, arrj1,osize);


				has_swapped = 1;

			}



		}
		if (!has_swapped) break;


	}







}
