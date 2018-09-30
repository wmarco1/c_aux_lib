#pragma once

#include "c_aux.h"
#include "c_aux_dlinked_list.h"



typedef struct Deque Deque;
struct Deque{
	DLinkedList que;
	unsigned int size;

};

void deque_init(Deque* d);

void deque_push(Deque* d, POD in);
int deque_pop(Deque *d, POD *out);
int deque_peek_end(Deque* d, POD *out);
int deque_peek_front(Deque* d, POD *out);
int deque_dequeue(Deque* d, POD *out);

int deque_peek_end_ptr(Deque* d, POD **out);
int deque_peek_front_ptr(Deque* d, POD **out);
