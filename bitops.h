
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <assert.h>
#include <string.h>

#define kWORD_TYPE int 
#define kWORD_SIZE sizeof(kWORD_TYPE)
#define kBIT_BOUNDS (kWORD_SIZE<<3)
#define kCHECK_BIT_BOUNDS 1

#define kCLEAR_BIT_STR "clear"
#define kTOGGLE_BIT_STR "toggle"
#define kSET_BIT_STR	"set"
#define kTEST_BIT_STR "test"


#define kCLEAR_BIT_STR_SHORT "c"
#define kTOGGLE_BIT_STR_SHORT "t"
#define kSET_BIT_STR_SHORT	"s"
#define kTEST_BIT_STR_SHORT "?"


#define kNUM_BIT_OPS 4
#define kMAX_OP_STRINGS 5

typedef kWORD_TYPE binary;
typedef binary (*BitOpFunc)(binary, unsigned int);


typedef struct{
	char* op_strings[kMAX_OP_STRINGS];
	unsigned int num_ops;
	BitOpFunc func;
} BitOp;


BitOp g_binary_op_table[kNUM_BIT_OPS]= {0};


#ifndef kCHECK_BIT_BOUNDS
binary clear_bit( binary in, unsigned int n){
	return in & ~(0x1 << n);
	
}

binary toggle_bit( binary in, unsigned int n){
	return in ^ 0x1 << n;
}

binary set_bit( binary in, unsigned int n){
	return in | 0x1 << n;
}

binary test_bit( binary in, unsigned int n){	
	return in & (1 << x);
}
#else
	

binary clear_bit( binary in, unsigned int n){
	assert(n < kBIT_BOUNDS);
	return in & ~(0x1 << n);
	
}

binary toggle_bit( binary in, unsigned int n){
	assert(n < kBIT_BOUNDS);
	return in ^ 0x1 << n;
}

binary set_bit( binary in, unsigned int n){
	assert(n < kBIT_BOUNDS);
	return in | 0x1 << n;
}

binary test_bit( binary in, unsigned int n){
	assert(n < kBIT_BOUNDS);
	
	return in & (1 << n);
}  


#endif
void set_string_array(char** s_arr, unsigned int num,...){
	va_list args;
	assert( num <= kMAX_OP_STRINGS);
	
	
	va_start( args, num);
	
	for( int i=0; i < num; i++){
		s_arr[i] = va_arg(args, char*);
		
	}
	
	va_end(args);
	
	
}
void create_bit_op_table(void){
	
	BitOp *g_bot = g_binary_op_table;
	
	
	set_string_array(g_bot[0].op_strings ,2, kCLEAR_BIT_STR, kCLEAR_BIT_STR_SHORT);
	g_bot[0].num_ops = 2;
	g_bot[0].func = clear_bit;
	
	set_string_array(g_bot[1].op_strings ,2, kTOGGLE_BIT_STR, kTOGGLE_BIT_STR_SHORT);
	g_bot[1].num_ops = 2;
	g_bot[1].func = toggle_bit;
	
	set_string_array(g_bot[2].op_strings ,2, kSET_BIT_STR, kSET_BIT_STR_SHORT);
	g_bot[2].num_ops = 2;
	g_bot[2].func = set_bit;
	
	set_string_array(g_bot[3].op_strings,2, kTEST_BIT_STR, kTEST_BIT_STR_SHORT);
	g_bot[3].num_ops = 2;
	g_bot[3].func = test_bit;
	
	
}


int parse_bit_op(char *op, binary in, unsigned int n, binary *out){
	BitOp *g_bot = g_binary_op_table;

	for(int i=0; i < kNUM_BIT_OPS; i++){
		assert( g_bot[i].op_strings != NULL && "BitOpTable has empty entry");
		
		for(int j=0; j < kMAX_OP_STRINGS; j++){
			if( g_bot[i].op_strings[j] != NULL){
				
				if(strcmp( g_bot[i].op_strings[j], op) == 0){
					assert( g_bot[i].func != NULL && "BitOpTable function not set");
					*out = g_bot[i].func(in, n);
					return 1;
				}
				
				
			}
			
		}
		
		
		
	}
	
	//no match
	return 0;
	
	
}

void print_diff_bases(binary in){
	char bin_str[kBIT_BOUNDS+1]= {0};

		
		
		
	printf("%d\n", in);
	printf("0x%x\n", in);
	
	
	
	for( int i=kBIT_BOUNDS,j=0; i--> 0; j++ ){
		
		
		if( test_bit(in, i) ) bin_str[j] = '1';
		else bin_str[j] = '0';
		
		
		
	}

	printf("%s", bin_str);
	
}