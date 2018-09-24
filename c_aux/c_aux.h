#pragma once


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include <stdarg.h>  
#include <signal.h>
#include <stdint.h>

//#include "c_aux_dlinked_list.h"


/* MACRO  __FILENAME__
Macro to shorten __FILE__ from a full path to just it's name.
strchr(char *, char) returns a pointer the specified character's last occurance, by adding one 
we have a pointer to the file name.*/
#ifdef _WIN32
#define __DIR_SEP__  '\\'
#elif
#define __DIR_SEP__ '/'
#endif
#define __FILENAME__ (strrchr(__FILE__, __DIR_SEP__) ? strrchr(__FILE__, __DIR_SEP__) + 1 : __FILE__)



/* MACRO debug_brk
Will break into debugger when called debug_brk(), if not in debug mode it will abort.
*/
#ifdef _DEBUG
#ifdef _MSC_VER
#define debug_brk __debugbreak()
#elif defined(__i386__) || defined(__x86_64__)
#define debug_brk __builtin_trap()
#endif
#else
#define debug_brk exit(1);
#endif



/* MACRO _fatal(...)

Will write to stderr where it was called from and an error message. Will break into debugger or exit with 1.
Example:

_fatal("Some error expected %u", but got %u, expected, ouput);

*/
#define _fatal(x, ...) __fatal (__FILENAME__,__FUNCSIG__,__LINE__, x , __VA_ARGS__ )


/* MACRO _fassert(...)

fatal assert. Same as _fatal mixed with assert(). Exmaple:



_fassert( important > 200, "Important is 200 or lower (important = %d)", important);

*/
#define _fassert(c, x, ...) do{ if(!c) _fatal(x, __VA_ARGS__);}while(0)


/* MACRO _fnassert(...)
Call _fatal() if condition is met ( opposite of _fassert()) 

_fnassert(important <= 200, "Error important to low %d", important);
*/
#define _fnassert(c, x, ...) do{ if(!c) _fatal(x, __VA_ARGS__);}while(0)


/* MACRO _warn_msg(...)
Similar to _fatal() except it will not break to debugger or exit.
*/
#define _warn_msg(...) error_msg(__FILENAME__,__FUNCSIG__,__LINE__, __VA_ARGS__)

/* FUNCTION __fatal()
Helper for _fatal macro. */
inline void __fatal(const char*file, const char* func, int line, const char* err, ...) {

	va_list args;
	va_start(args, err);
	fprintf(stderr, "--------------Fatal Error---------------\nFILE: %s LINE: %d\n", file, line);
	fprintf(stderr, "FUNCTION: %s\nMESSAGE: ", func);
	vfprintf(stderr, err, args);
	fprintf(stderr, "\n");
	va_end(args);
	debug_brk;
}

/* fatal(const char* err, ...)
Displays message and breaks to debugger or exits.
*/
 inline void fatal(const char* err, ...) {
	va_list args;
	va_start(args, err);
	vfprintf(stderr, err, args);
	va_end(args);
	debug_brk;
}
/* void error_msg(const char* err, ...)
Writes warning message to stderr 
*/
inline void warn_msg(const char* err, ...) {
	va_list args;
	va_start(args, err);
	vfprintf(stderr, err, args);
	va_end(args);
}

/*  int str_to_ui(char *str, unsigned int *out, unsigned int radix)
Converts str to unsigned int and is stored in *out using given radix. 
Will return 1 on failure, 0 on success. Example:

unsigned int a;
const char* str = "123456";

if( str_to_ui(str, &a, 10) fatal("Failed to convert string to unsigned int\n");

*/
inline int str_to_ui(char *str, unsigned int *out, unsigned int radix)
{
	char *end;
	*out = strtoul(str, &end, radix);
	if (end == str) return 1;
	return 0;
}


/* Same as str_to_ui, but with signed integers */
inline int str_to_i(char *str, int *out, unsigned int radix)
{
	char *end;
	*out = strtol(str, &end, radix);
	if (end == str) return 1;
	return 0;
}

/* Same as str_to_ui, but with float. NB - doesn't need a radix */
inline int str_to_f(char *str, float *out)
{
	char *end;
	*out = strtof(str, &end);
	if (end == str) return 1;
	return 0;
}


/* Same as str_to_ui, but with double. NB - doesn't need a radix */
inline int str_to_d(char *str, double *out)
{
	char *end;
	*out = strtof(str, &end);
	if (end == str) return 1;
	return 0;
}


/* Bit testing functions
 *
 *
 *
 *
 */
#define binary unsigned int
#define kBIT_BOUNDS (sizeof(binary)<<3)

inline binary clear_bit(binary in, unsigned int n) {
	assert(n < kBIT_BOUNDS);
	return in & ~(0x1 << n);

}

inline binary toggle_bit(binary in, unsigned int n) {
	assert(n < kBIT_BOUNDS);
	return in ^ 0x1 << n;
}

inline binary set_bit(binary in, unsigned int n) {
	assert(n < kBIT_BOUNDS);
	return in | 0x1 << n;
}

inline binary test_bit(binary in, unsigned int n) {
	assert(n < kBIT_BOUNDS);

	return (in & (1 << n)) ? 1: 0;
}

inline int count_ones(binary in) {
	int c = 0;
	for (int i = kBIT_BOUNDS; i--> 0; ) in & (0x1 << i) ? c++ : 0;
	return c;
}
inline int count_zeroes(binary in) {
	int c = 0;
	for (int i = kBIT_BOUNDS; i--> 0; ) in & (0x1 << i) ? 0 : c++;
	return c;
}


inline void print_diff_bases(binary in) {
	char bin_str[kBIT_BOUNDS + 1] = { 0 };

	printf("%d\n", in);
	printf("0x%x\n", in);

	for (int i = kBIT_BOUNDS, j = 0; i--> 0; j++) {
		if (test_bit(in, i)) bin_str[j] = '1';
		else bin_str[j] = '0';
	}

	printf("%s\n", bin_str);
}

/*POD = Plain Old Data


*/
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

typedef struct {
	POD data;
	uint32_t id;
} VAR;


inline POD ptr_to_POD(void* ptr) { POD p; p.ptr = ptr; return p; }
inline POD i32_to_POD(int32_t n) { POD p; p.i32 = n; return p; };
inline POD ui32_to_POD(uint32_t n) { POD p; p.ui32 = n; return p; };
inline POD float_to_POD(float n) { POD p; p.f = n; return p; };
inline POD str_to_POD(char* str) { POD p; p.str = str; return p; };
