#include "List.h"
#include <iostream>
List::List() :head(nullptr) {}
void List::Add(int _value) {
	Node* newNode = new Node(_value);
	if (head == nullptr) {
		head = newNode;
		return;
	}
	else {
		Node* tmp = head;
		while (tmp->next != nullptr) {
			tmp = tmp->next;
		}
		tmp->next = newNode;
	}
}
void List::PrintList() {
	if (head == nullptr) {
		return;
	}
	Node* current = head;
	head = head->next;
	PrintList();
	std::cout << current->value << " ";
}
