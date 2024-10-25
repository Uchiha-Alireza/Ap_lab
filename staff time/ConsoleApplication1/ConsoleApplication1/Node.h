#pragma once
#include "Gun.h"
class Node {
private:
	Gun data;
	Node* next;
	Node* prev;
public:
	Node(Gun);
	Node* getNext()const;
	void setNext(Node*);
	Node* getPrev()const;
	void setPrev(Node*);
	bool getNameGun(std::string);
	Gun& getData();
};