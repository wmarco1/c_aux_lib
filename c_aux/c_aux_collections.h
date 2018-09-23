#pragma once


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>


	typedef union {

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

	inline POD i32_to_POD(int32_t n) { POD p; p.i32 = n; return p; };
	inline POD ui32_to_POD(uint32_t n) { POD p; p.ui32 = n; return p; };
	inline POD float_to_POD(float n) { POD p; p.f = n; return p; };
	inline POD str_to_POD(char* str) { POD p; p.str = str; return p; };

	typedef struct Collection Collection;
	struct Collection {
		void* store;
		void(*push)(Collection *c, POD in);
		int(*pop)(Collection *c, POD *out);
		int(*insert_at)(Collection *c, POD in, unsigned int index);
		POD(*at)(Collection *c, unsigned int index);
		POD(*remove)(Collection *c, unsigned int index);
		int(*find)(Collection *c, POD in);
		unsigned int(*length)(Collection *c);
		unsigned int(*used_memory)(Collection *C);
		void*(*root)(Collection *c);
		POD(*next)(Collection *c, void** node);
		POD(*prev)(Collection *c, void** node);
	};

	