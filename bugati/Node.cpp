#include "Node.h"
#include <iostream>
#include "Motorcycle.h"
#include "Car.h"
#include "Vehicle.h"
#include "bike.h"

LinkedList::LinkedList() : head(nullptr), tail(nullptr) {}

LinkedList::~LinkedList() {
    Node* current = head;
    while (current) {
        Node* temp = current;
        current = current->next;
        delete temp->data; 
        delete temp;
    }
}

void LinkedList::addVehicle(Vehicle* v) {
    Node* newNode = new Node(v);
    if (!head) {
        head = tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
}

void LinkedList::displayVehicles() const {
    Node* current = head;
    while (current) {
        current->data->ShowDetail();
        std::cout << "------------------------\n";
        current = current->next;
    }
}
Vehicle* LinkedList::findVehicle(int id) const {
    Node* current = head;
    while (current) {
        if (current->data->getid() == id) {
            return current->data;
        }
        current = current->next;
    }
    return nullptr; 
}

void LinkedList::sellVehicle(int id) {
    Vehicle* v = findVehicle(id);
    if (v) {
        if (dynamic_cast<Car*>(v)) {
            Car* car = dynamic_cast<Car*>(v);
            if (car->canBeSold()) {
                car->sell();
            }
            else {
                std::cout << "This car is not available for sale.\n";
            }
        }
        else if (dynamic_cast<Motorcycle*>(v)) {
            Motorcycle* motorcycle = dynamic_cast<Motorcycle*>(v);
            if (motorcycle->canBeSold()) {
                motorcycle->sell();
            }
            else {
                std::cout << "This motorcycle is not available for sale.\n";
            }
        }
        else {
            std::cout << "This vehicle cannot be sold.\n";
        }
    }
    else {
        std::cout << "Vehicle with ID " << id << " not found.\n";
    }
}
