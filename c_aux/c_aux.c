// c_aux.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "c_aux.h"
#include "c_aux_dlinked_list.h"
#include "c_aux_deque.h"
#include "c_aux_sort.h"
#include <stdint.h>
void dll_sanity_check(DLinkedList*dll) {



}


int main()
{
	DLinkedList dll = { 0 };
	Deque d = { 0 };
	POD p;
	dlinked_list_init(&dll);
	dlinked_list_push(&dll, ui32_to_POD(6));
	dlinked_list_push(&dll, ui32_to_POD(5));
	dlinked_list_push(&dll, ui32_to_POD(4));  
	dlinked_list_push(&dll, ui32_to_POD(3));
	dlinked_list_push(&dll, ui32_to_POD(2));
	dlinked_list_push(&dll, ui32_to_POD(1));
	dlinked_list_push(&dll, ui32_to_POD(0));

	DLinkedListNode *n = dll.root;
	uint32_t arr[10];


	for (int i = 10; i-- > 0; ) {
		arr[i] = i;

	}
	arr[4] = 99;

	//c_aux_bubble_sort_arr(arr, 10, sizeof(uint32_t), c_aux_ui_cmp);
	//c_aux_slection_sort_arr(arr, 10, sizeof(uint32_t), c_aux_ui_cmp);


	arr[1] = 100;
	arr[4] = 99;
	c_aux_insertion_sort_arr(arr, 10, sizeof(uint32_t), c_aux_ui_cmp);

	for (int i = 0; i < 10; i++)printf("%u\n", arr[i]);
	
    return 0;
}

