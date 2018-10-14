#pragma once
#include "c_aux.h"
#include <stdlib.h>


typedef unsigned long long int_c;


int_c factorial(int_c n) {
	
	for (; n > 1; ) {
		n *= n--;

	}
	return n;
}
// Sit k people from n, order matters.... Permutation lock
int_c nPk(int_c n, int_c k) {

	for (; n >= (n-k); ) {
		n *= n--;

	}
	return n;
}
// Sit r people from n, order does not matter unlike a combination lock
int_c nCr(int_c n, int_c r) {

	for (; n >= (n - r); ) {
		n *= n--;

	}
	return n / factorial(r);

}

int b_trial(double p_true) {

	return( c_aux_randd(0.0, 1.0)< p_true);


}
