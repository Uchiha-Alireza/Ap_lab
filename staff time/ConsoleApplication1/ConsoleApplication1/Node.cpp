#include "Node.h"
Node::Node(Gun _gun):data(_gun),next(nullptr),prev(nullptr){}
Node* Node::getNext()const {
	return next;
}
void Node::setNext(Node* _next) {
	next = _next;
}
Node* Node::getPrev()const {
	return prev;
}
void Node::setPrev(Node* _prev) {
	prev = _prev;
}
bool Node::getNameGun(std::string _string) {
	Gun tmp = getData();
	if (tmp.GetName() == _string) {
		return true;
	}
	else {
		return false;
	}
}
Gun& Node::getData(){
	return data;
}