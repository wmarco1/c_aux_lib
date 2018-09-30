#pragma once
#include "c_aux.h"
#include "c_aux_dlinked_list.h"

int c_aux_ui32_cmp(POD *a, POD *b);
c_aux_bubble_sort_dl(DLinkedList *l, int(*cfunc)(POD *a, POD *b));

int c_aux_ui_cmp(uint32_t *a, uint32_t *b);
c_aux_slection_sort_arr(void* arr, int len, int osize, int(*cfunc)(void *a, void *b));
c_aux_insertion_sort_arr(void* arr, int len, int osize, int(*cfunc)(void *a, void *b));
c_aux_bubble_sort_arr(void* arr, int len, int osize, int(*cfunc)(void *a, void *b));
