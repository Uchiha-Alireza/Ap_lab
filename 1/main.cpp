#include "applyjob.h"
#include <iostream>

int main(){
	int S=87;
	int* s = &S;
	int& rs = S;
	check(s, rs);
	return 0;
}

