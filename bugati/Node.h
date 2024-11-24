#pragma once
#include "Vehicle.h"

class Node {
public:
    Vehicle* data;
    Node* next;

    Node(Vehicle* _data) : data(_data), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;
    Node* tail;
public:
    LinkedList();
    ~LinkedList();
    void addVehicle(Vehicle* v);
    void displayVehicles() const;
    Vehicle* findVehicle(int id) const;
    void sellVehicle(int id);
};
