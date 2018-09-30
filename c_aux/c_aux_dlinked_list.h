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
void dlinked_list_swap_node_index(DLinkedList *l,unsigned int a, unsigned int b);

void dlinked_list_swap_node(DLinkedListNode *a, DLinkedListNode *b);
int dlinked_list_root(DLinkedList *c, POD *out);
int dlinked_list_remove_root(DLinkedList*c);

DLinkedListNode * dlinked_list_root_node(DLinkedList* c);
void dlinked_list_swap_data_index(DLinkedList *d, unsigned int ai, unsigned int bi);
int dlinked_list_cycle_check(DLinkedList *c);

void dlinked_list_init(DLinkedList *ll);

unsigned int dlinked_list_length(DLinkedList* c);


DLinkedListNode* dlinked_list_next(DLinkedListNode* node);
DLinkedListNode* dlinked_list_end(DLinkedList *ll);


void dlinked_list_push(DLinkedList* c, POD in);
DLinkedListNode* dlinked_list_node_at(DLinkedList *ll, unsigned int index);
POD dlinked_list_POD_at(DLinkedList *ll, unsigned int index);
POD* dlinked_list_PODP_at(DLinkedList *ll, unsigned int index);


int dlinked_list_pop(DLinkedList *c, POD *out);

void dlinked_list_insert_after(DLinkedListNode *node, POD p);

void dlinked_list_insert_at(DLinkedList *ll, unsigned int  index, POD p);