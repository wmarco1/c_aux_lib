#pragma once


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>



	typedef struct Collection Collection;
	struct Collection {
		void* store;
		void(*push)(Collection *c, POD in);
		int(*pop)(Collection *c, POD *out);
		int(*insert_at)(Collection *c, POD in, unsigned int index);
		POD(*at)(Collection *c, unsigned int index);
		POD(*swap)(Collection *c, unsigned int a, unsigned int b);
		POD(*remove)(Collection *c, unsigned int index);
		int(*find)(Collection *c, POD in);
		unsigned int(*length)(Collection *c);
		unsigned int(*used_memory)(Collection *C);
		void*(*root)(Collection *c);
		POD(*next)(Collection *c, void** node);
		POD(*prev)(Collection *c, void** node);
	};

	