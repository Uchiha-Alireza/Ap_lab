#include "List.h"
#include <iostream>

int main() {
    List myList;
    myList.Add(84);
    myList.Add(85);
    myList.Add(86);
    myList.Add(87);
    std::cout << "Printing list in reverse order: ";
    myList.PrintList();
    std::cout << std::endl;
    return 0;
}
