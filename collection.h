#pragma once


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
typedef union{
	
	intmax_t iMAX;
	uintmax_t uiMAX;
	
	int64_t i64;
	uint64_t ui64;
	
	int32_t i32;
	uint32_t ui32;
	
	int16_t i16;
	uint16_t ui16;
	
	int8_t i8;
	uint8_t ui8;
	
	void* ptr;
	char* str;
	double d;
	float f;
	
} POD;

POD i32_to_POD(int32_t n){ POD p; p.i32 = n; return p;};
POD ui32_to_POD(uint32_t n){ POD p; p.ui32 = n; return p;}; 
POD float_to_POD(float n){ POD p; p.f = n; return p;}; 
POD str_to_POD(char* str){ POD p; p.str = str; return p;};
 
typedef struct Collection Collection;
struct Collection{
	void* store;
	void(*push)(Collection *c,POD in);
	POD(*pop)(Collection *c);
	int(*insert_at)(Collection *c, POD in, unsigned int index);
	POD(*at)(Collection *c, unsigned int index);
	POD(*remove)(Collection *c,unsigned int index);
	int(*find)(Collection *c,POD in);
	unsigned int(*length)(Collection *c);
	unsigned int(*used_memory)(Collection *C); 
	void*(*root)(Collection *c);
	POD (*next)(Collection *c, void** node);
	POD (*prev)(Collection *c, void** node);
};

typedef struct DLinkedListNode DLinkedListNode;
struct DLinkedListNode{
	DLinkedListNode *prev, *next;
	POD data;
};

typedef struct SLinkedListNode SLinkedListNode;
struct SLinkedListNode{
	SLinkedListNode *prev, *next;
	POD data;
};


int dlinked_list_get_root(Collection *c,DLinkedListNode* node){
	node = (DLinkedListNode*)c->store;
	return 0;
	
}
int dlinked_list_next(Collection *c,void* node){
	node = ((DLinkedListNode*)node)->next;
	if( node == NULL) return 0;
	else return 1;
}

int dlinked_list_size(Collection *c,unsigned int *size_out){
	int n=0;
	DLinkedListNode *cursor = (DLinkedListNode*)c->store;
	if(cursor == NULL){
		*size_out = 0;
		return 0;
	}
	n++;
	do{
		if(cursor->next == NULL) break;
		else {
			cursor = cursor->next;
			n++;
		}
	
	}while(1);
	
	*size_out = n;
	return 0;
	
}
int dlinked_list_push(Collection *c,POD in){
	
	DLinkedListNode *cursor = (DLinkedListNode*) c->store;
	
	
	if(cursor == NULL){
		
		c->store = calloc(1, sizeof(DLinkedListNode));
		assert(c->store != NULL);
		((DLinkedListNode*)c->store)->data = in;
		((DLinkedListNode*)c->store)->prev = NULL;
		((DLinkedListNode*)c->store)->next = NULL;
		return 0;
		
	}
	
	
	do{
		
		if(cursor->next == NULL) break;
		else cursor = cursor->next;
	}while(1);
	
	
	cursor->next = (DLinkedListNode*)calloc(1,sizeof(DLinkedListNode));
	assert(cursor->next != NULL);
	
	cursor->next->prev = cursor;
	cursor->next->data = in;
	return 0;
}

int dlinked_list_pop(Collection *c, POD *out){
	
	DLinkedListNode *cursor = (DLinkedListNode*) c->store;
	if(cursor == NULL){
		out == NULL;
		return 1;
	}
	
	do{
		if(cursor->next == NULL) break;
		else cursor = cursor->next;
	
	}while(1);
	
	
	if( cursor->prev == NULL){
		c->store = NULL;
	}else{
		cursor->prev->next = NULL;
		
	}
	cursor->prev = NULL;
	
	*out = cursor->data;
	free(cursor);
	return 0;
}




