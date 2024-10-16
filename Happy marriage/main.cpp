#include "linkedlist.h"
#include <iostream>

int main() {
    LinkedList list1;
    std::cout << "\nEmpty list created\n";
    list1.push_back(10);
    list1.push_back(20);
    list1.push_back(30);    
    list1.push_front(5);
    list1.push_front(0);
    std::cout << "Size of list1: " << list1.get_size() << std::endl;
    std::cout << "Element at index 0: " << list1.at(0) << std::endl;
    std::cout << "Element at index 2: " << list1.at(2) << std::endl;
    std::cout << "Pop back: " << list1.pop_back() << std::endl;
    std::cout << "Pop front: " << list1.pop_front() << std::endl;
    if (list1.is_empty()) {
        std::cout << "List is empty\n";
    } else {
        std::cout << "List is not empty\n";
    }
    LinkedList list2(5, 100);
    std::cout << "List2 created with size 5 and value 100" << std::endl;
    std::cout << "Size of list2: " << list2.get_size() << std::endl;
    LinkedList list3 = list2;
    std::cout << "List3 (copy of list2) created." << std::endl;
    for (int i = 0; i < list3.get_size(); i++) {
        std::cout << "Element at index " << i << ": " << list3.at(i) << std::endl;
    }
    return 0;  
}
