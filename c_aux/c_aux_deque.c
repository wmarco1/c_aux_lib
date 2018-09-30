


#include "stdafx.h"
#include "c_aux_deque.h"


void deque_init(Deque * d) {

	dlinked_list_init(&d->que);

}
void deque_push(Deque* d, POD in) {

	dlinked_list_push(&d->que, in);


}
int deque_pop(Deque *d, POD *out) {

	return dlinked_list_pop(&d->que, out);


}



int deque_peek_end(Deque* d, POD *out) {

	_fassert(out != NULL, "NULL ARG");

	DLinkedListNode* node =  dlinked_list_end(&d->que, out);

	if (node == NULL)return 0;

	*out = node->data;

}



int deque_peek_front(Deque* d, POD *out) {
	

	DLinkedListNode* node = dlinked_list_root(&d->que, out);

	if (node == NULL)return 0;

	*out = node->data;



}
int deque_dequeue(Deque* d, POD *out) {

	if (dlinked_list_root(&d->que, out)) {

		//dlinked_list_root_node(&d->que);
		dlinked_list_remove_root(&d->que);
		return 1;
	}
	return 0;

}

int deque_peek_end_ptr(Deque* d, POD **out) {
	_fassert(out != NULL, "NULL ARG");

	DLinkedListNode* node = dlinked_list_end(&d->que, out);

	if (node == NULL)return 0;

	*out = &node->data;


}
int deque_peek_front_ptr(Deque* d, POD **out) {
	_fassert(out != NULL, "NULL ARG");

	DLinkedListNode* node = dlinked_list_root(&d->que, out);

	if (node == NULL)return 0;

	*out = &node->data;

}