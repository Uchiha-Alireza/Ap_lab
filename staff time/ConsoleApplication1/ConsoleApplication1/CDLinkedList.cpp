#include "CDLinkedList.h"
LinkedList::LinkedList():head(nullptr),tail(nullptr){}
int LinkedList::size = 0;
LinkedList::~LinkedList() {
	Node* current = head;
	while (current != nullptr) {
		Node* nextNode = current->getNext();
		delete current;
		current = nextNode;
	}
}
void LinkedList::addGun(const Gun& _gun) {
	Node* newNode = new Node(_gun);
	if (head == nullptr) {
		head = newNode;
		tail = newNode;
		newNode->setNext(head); 
		newNode->setPrev(head); 
	}
	else {
		tail->setNext(newNode);
		newNode->setPrev(tail);
		newNode->setNext(head);
		head->setPrev(newNode);
		tail = newNode;
	}
	size++;
	return;
}
void LinkedList::DeActiveGun(const std::string& _nameGun) {
	Node* current = head;
	if (current != nullptr) {
		do {
			if (current->getData().GetName() == _nameGun) {
				current->getData().setisDeactive(false);
				return;
			}
			current = current->getNext();
		} while (current!=nullptr);
	}
}
void LinkedList::ActiveGun(const std::string& _nameGun) {
	Node* current = head;
	if (current != nullptr) {
		do {
			if (current->getData().GetName() == _nameGun) {
				current->getData().setisDeactive(true);
				return;
			}
			current = current->getNext();
		} while (current != nullptr);
	}
}
void LinkedList::removeGun(const std::string& gunName) {
	Node* current = head;
	if (current != nullptr) {
		do {
			if (current->getData().GetName() == gunName) {
				if (current == head && current == tail) { 
					delete current;
					head = nullptr;
					tail = nullptr;
				}
				else {
					if (current == head) {
						head = current->getNext();
					}
					if (current == tail) {
						tail = current->getPrev();
					}
					if (current->getPrev() != nullptr) {
						current->getPrev()->setNext(current->getNext());
					}
					if (current->getNext() != nullptr) {
						current->getNext()->setPrev(current->getPrev());
					}
					delete current;
				}
				size--;
				return;
			}
			current = current->getNext();
		} while (current != head);
	}
}
void LinkedList::displayGuns() const {
	Node* current = head;
	if (current != nullptr) {
		do {
			std::cout << current->getData().GetName() << std::endl;
			current = current->getNext();
		} while (current != head);
	}
}
int LinkedList::getSize(){
	return size;
}
bool LinkedList::CompareNodes(Node* node1, Node* node2) {
	if (node1 == nullptr || node2 == nullptr) {
		std::cerr << "One of the nodes is null." << std::endl;
		return false;
	}
	Gun gun1 = node1->getData(); 
	Gun gun2 = node2->getData(); 
	if (gun1 == gun2) {
		std::cout << "The two guns are identical." << std::endl;
		return true;
	}
	else if (gun1 < gun2) {
		std::cout << "Gun1 has less ammo than Gun2." << std::endl;
		return false;
	}
	else if (gun1 > gun2) {
		std::cout << "Gun1 has more ammo than Gun2." << std::endl;
		return false;
	}
	else {
		std::cout << "The guns are different." << std::endl;
		return false;
	}
}
void LinkedList::IncrementNode(Node* node) {
	if (node == nullptr) {
		std::cerr << "Node is null." << std::endl;
		return;
	}
	Gun& gunData = node->getData();
	gunData++;
}
bool LinkedList::IsGreaterThan(Node* node1, Node* node2) {
	if (node1 == nullptr || node2 == nullptr) {
		return false;
	}
	return node1->getData() > node2->getData();
}
bool LinkedList::IsLessThan(Node* node1, Node* node2) {
	if (node1 == nullptr || node2 == nullptr) {
		return false;
	}
	return node1->getData() < node2->getData();
}
bool LinkedList::IsGreaterOrEqual(Node* node1, Node* node2) {
	if (node1 == nullptr || node2 == nullptr) {
		return false;
	}
	return node1->getData() >= node2->getData();
}
bool LinkedList::IsLessOrEqual(Node* node1, Node* node2) {
	if (node1 == nullptr || node2 == nullptr) {
		return false;
	}
	return node1->getData() <= node2->getData();
}
void LinkedList::DoubleAmmo(Node* node) {
	if (node != nullptr) {
		node->getData().SetAmmo(node->getData().GetAmmo() * 2);
	}
}

void LinkedList::HalveAmmo(Node* node) {
	if (node != nullptr) {
		int currentAmmo = node->getData().GetAmmo();
		node->getData().SetAmmo(currentAmmo / 2);
	}
}

Node* LinkedList::getNodeAt(int position) {
	if (position < 0 || position >= size) {
		std::cerr << "Invalid position.\n";
		return nullptr;
	}

	Node* current = head;
	for (int i = 0; i < position; ++i) {
		current = current->getNext();
	}
	return current;
}
Node* LinkedList::findGunByName(const std::string& name) {
	if (head == nullptr) {
		return nullptr;
	}
	Node* current = head;
	do {
		if (current->getData().GetName() == name) {
			return current; 
		}
		current = current->getNext();
	} while (current != head);

	return nullptr; 
}
