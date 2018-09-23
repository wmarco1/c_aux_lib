#pragma once
#include "stdafx.h"
#include "c_aux.h"
#include "c_aux_collections.h"


typedef struct DLinkedListNode DLinkedListNode;
struct DLinkedListNode {
	DLinkedListNode *prev, *next;
	POD data;
};

typedef struct DLinkedList DLinkedList;
struct DLinkedList {
	DLinkedListNode *root;
};





void dlinked_list_init(DLinkedList *ll);

unsigned int dlinked_list_length(DLinkedList* c);


DLinkedListNode* dlinked_list_next(DLinkedListNode* node);
DLinkedListNode* dlinked_list_end(DLinkedList *ll);


void dlinked_list_push(DLinkedList* c, POD in);
DLinkedListNode* dlinked_list_node_at(DLinkedList *ll, unsigned int index);
POD dlinked_list_POD_at(DLinkedList *ll, unsigned int index);
POD* dlinked_list_PODP_at(DLinkedList *ll, unsigned int index);


int dlinked_list_pop(DLinkedList *c, POD *out);
