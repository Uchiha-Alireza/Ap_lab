#include "applyJob.h"
#include <iostream>
int check_null(int* ptr) {
	if (ptr == NULL) {
		return 1;
	}
	return 2;
}
void check(int* ptr, int& ref) {
	int B=check_null(ptr);
	if (B==1) {
		std::cout << "pointer is NULL"<<std::endl;
        return;
	}
	std::cout << "first input is a pointer and the second input is a reference."<<std::endl;
	if (*ptr == ref) {
		std::cout << "Pointer and reference refer to the same value." << std::endl;
	}
	if (*ptr == ref && ptr == &ref) {
		std::cout << "Pointer and reference both refer to the same variable and the same value."<<std::endl;
        return;
	}
	if (*ptr == ref && ptr != &ref) {
		std::cout << "Pointer and reference both refer to the same value and different variables."<<std::endl;
        return;
    }
	if (*ptr != ref && ptr != &ref) {
		std::cout << "Pointer and reference neither have the same value nor refer to the same variables."<<std::endl;
        return;
	}
}