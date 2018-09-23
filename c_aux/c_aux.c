// c_aux.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "c_aux.h"
#include "c_aux_dlinked_list.h"
int main()
{
	DLinkedList dll = { 0 };
	POD p;
	dlinked_list_init(&dll);
	dlinked_list_push(&dll, ui32_to_POD(10));
	dlinked_list_push(&dll, ui32_to_POD(11));
	dlinked_list_push(&dll, ui32_to_POD(12));

	printf("Length = %d\n", dlinked_list_length(&dll));

	dlinked_list_pop(&dll, &p);
	printf("pop = %d\n", p.i32);
	dlinked_list_pop(&dll, &p);
	printf("pop = %d\n", p.i32);
	dlinked_list_pop(&dll, &p);
	printf("pop = %d\n", p.i32);
	dlinked_list_push(&dll, ui32_to_POD(999));
	printf("%d\n",dlinked_list_POD_at(&dll, 1));
	printf("Length = %d\n", dlinked_list_length(&dll));
	

    return 0;
}

