
#pragma once
#include "stdafx.h"
#include "c_aux.h"
#include "c_aux_dlinked_list.h"


void dlinked_list_init(DLinkedList *ll) {

	ll->root = NULL;


}


unsigned int dlinked_list_length(DLinkedList* c) {

	DLinkedListNode* cursor = c->root;
	unsigned int count=0;
	if (cursor == NULL) return 0;

	while (cursor != NULL) {
		count++;
		cursor = cursor->next;
	}
	return count;

}

DLinkedListNode * dlinked_list_root_node(DLinkedList* c) {


	return c->root;
}

int dlinked_list_root(DLinkedList *c, POD *out) {

	if (c->root != NULL) {

		*out = c->root->data;
		return 1;
	}
	return 0;

}
int dlinked_list_remove_root(DLinkedList*c) {
	if (c->root != NULL) {
		if (c->root->next != NULL) {
			DLinkedListNode *n = c->root->next;
			n->prev = NULL;
			free(c->root);
			c->root = n;
		}
		else {
			free(c->root);

			c->root = NULL;

		}
		return 1;
	}

	return 0;
}

DLinkedListNode* dlinked_list_next(DLinkedListNode* node) {
	_fassert(node != NULL, "Argument NULL");
	return node->next;

}

DLinkedListNode* dlinked_list_end(DLinkedList *ll) {
	DLinkedListNode* node;
	if (ll->root == NULL) return NULL;
	node = ll->root;
	do {
		if (node->next == NULL) break;
		else node = node->next;
	} while (1);
}


void dlinked_list_push(DLinkedList* c, POD in) {

	DLinkedListNode *node = dlinked_list_end(c);


	if (node == NULL) {
		c->root = calloc(1, sizeof(DLinkedListNode));
		c->root->data = in;
		c->root->prev = NULL;
		c->root->next = NULL;
		return;
	}


	node->next = (DLinkedListNode*)calloc(1, sizeof(DLinkedListNode));
	

	node->next->prev = node;
	node->next->data = in;
	node->next->next = NULL;
}
 
int dlinked_list_pop(DLinkedList *c, POD *out) {

	DLinkedListNode *end = dlinked_list_end(c);
	//_fassert(end != NULL, "Cannot pop anymore from linked list");
	if (end == NULL)return 0;
	if (end->prev != NULL) end->prev->next = NULL;
	else c->root = NULL;
	*out = end->data;
	free(end);
	return 1;
}

int dlinked_list_pop_us(DLinkedList *c, POD *out) {

	DLinkedListNode *end = dlinked_list_end(c);
	if (end == NULL) return 1;
	if (end->prev != NULL) end->prev->next = NULL;
	else c->root = NULL;
	*out = end->data;
	free(end);
	return 1;
}


DLinkedListNode* dlinked_list_node_at(DLinkedList *ll, unsigned int index) {
	DLinkedListNode *node = ll->root;
	
	if (node == NULL) _fatal("Empty Linked List");

	for (int i = 0; i < index; i++){

		if (node->next == NULL) _fatal("Index out of bounds");

		node = node->next;

	}


return node;

}


POD dlinked_list_POD_at(DLinkedList *ll, unsigned int index) {

	return dlinked_list_node_at(ll, index)->data;

}
POD* dlinked_list_PODP_at(DLinkedList *ll, unsigned int index) {

	return &dlinked_list_node_at(ll, index)->data;

}




void dlinked_list_insert_after(DLinkedListNode *node, POD p) {

	DLinkedListNode *dln = (DLinkedListNode*)calloc(1, sizeof(DLinkedListNode));

	_fassert(node !=NULL, "NULL ARG");

	dln->prev = node;
	dln->next = node->next;
	node->next = dln;
	dln->data = p;

}

void dlinked_list_insert_at(DLinkedList *ll,unsigned int  index, POD p) {

	DLinkedListNode *dln = (DLinkedListNode*)calloc(1, sizeof(DLinkedListNode));
	DLinkedListNode *node = dlinked_list_node_at(ll, index);

	dln->next = node;
	dln->prev = node->prev;
	node->prev = dln;
	if(dln->prev != NULL)dln->prev->next = dln;
	else ll->root = dln;
	dln->data = p;

}

void dlinked_list_swap_node(DLinkedList *d,DLinkedListNode *a, DLinkedListNode *b) {
	DLinkedListNode nr;
	DLinkedListNode *t;
	

	if (a == b)return;


	nr.prev = NULL;
	nr.next = d->root;
	d->root->prev = &nr;
	d->root = &nr;


	if (a->prev == b || a->next == b) {
		if (a->prev == b) {

			t = a;
			a = b;
			b = t;

		}
		if (a->prev) a->prev->next = b;

		if (b->next) b->next->prev = a;




		t = a->prev;
		a->prev = b;
		b->prev = t;

		t = a->next;
		a->next = b->next;
		b->next = a;

	}
	else {

		if (a->prev) a->prev->next = b;
		if (b->next) b->next->prev = a;
		if (b->prev) b->prev->next = a;
		if (a->next) a->next->prev = b;



		t = a->prev;
		a->prev = b->prev;
		b->prev = t;

		t = a->next;
		a->next = b->next;
		b->next = t;


	}





	d->root = nr.next;
	d->root->prev = NULL;



}


void dlinked_list_swap_data_index(DLinkedList *d, unsigned int ai, unsigned int bi) {

	DLinkedListNode* a = dlinked_list_node_at(d, ai);
	DLinkedListNode* b = dlinked_list_node_at(d, bi);

	POD p;
	p = a->data;
	a->data = b->data;
	b->data = p;
}
void dlinked_list_swap_node_index(DLinkedList *d, unsigned int ai, unsigned int bi) {
	DLinkedListNode nr;
	DLinkedListNode *t;
	DLinkedListNode* a = dlinked_list_node_at(d,ai);
	DLinkedListNode* b = dlinked_list_node_at(d,bi);

	if (ai == bi)return;

	
	nr.prev = NULL;
	nr.next = d->root;
	d->root->prev = &nr;
	d->root = &nr;


	if (a->prev == b || a->next == b) {
		if (a->prev == b) {

			t = a;
			a = b;
			b = t;

		}
		if (a->prev) a->prev->next = b;
		
		if (b->next) b->next->prev = a;
		



		t = a->prev;
		a->prev = b;
		b->prev = t;

		t = a->next;
		a->next = b->next;
		b->next = a;

	}
	else {

		if (a->prev) a->prev->next = b;
		if (b->next) b->next->prev = a;
		if (b->prev) b->prev->next = a;
		if (a->next) a->next->prev = b;



		t = a->prev;
		a->prev = b->prev;
		b->prev = t;

		t = a->next;
		a->next = b->next;
		b->next = t;


	}
	




	d->root = nr.next;
	d->root->prev = NULL;

}


int dlinked_list_cycle_check(DLinkedList *c) {







}
