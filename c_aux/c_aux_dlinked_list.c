
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
	_fassert(end != NULL, "Cannot pop anymore from linked list");
	if (end->prev != NULL) end->prev->next = NULL;
	else c->root = NULL;
	*out = end->data;
	free(end);
	return 0;
}

int dlinked_list_pop_us(DLinkedList *c, POD *out) {

	DLinkedListNode *end = dlinked_list_end(c);
	if (end == NULL) return 1;
	if (end->prev != NULL) end->prev->next = NULL;
	else c->root = NULL;
	*out = end->data;
	free(end);
	return 0;
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




void dlinked_list_insertAfter(DLinkedListNode *node, POD p) {

	DLinkedListNode *dln = (DLinkedListNode*)calloc(1, sizeof(DLinkedListNode));



}


