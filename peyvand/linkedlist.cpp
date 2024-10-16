#include "linkedlist.h"
#include <cstddef>
#include <iostream>

LinkedList::Node::Node(int value) : data(value), previous(nullptr), next(nullptr){
    std::cout<<"Node created";
}
LinkedList::LinkedList():head(nullptr),tail(nullptr){
    std::cout<<"linked list created";
}
/*LinkedList::LinkedList(int size,int value):head(nullptr),tail(nullptr){

}*/
LinkedList::LinkedList(const LinkedList& other):head(nullptr),tail(nullptr){
    
}
void LinkedList::push_back(int value){
    Node* newNode = new Node(value);
    newNode->next = nullptr;
    if(tail == nullptr){
        head =newNode;
        tail = newNode;
    }
    else{
        tail->next=newNode;
        newNode->previous =tail;
        tail=newNode;
    }
    std::cout<<value<<" added to the end of the list"<<std::endl;
}
void LinkedList::push_front(int value){
    Node* newNode = new Node(value);
    newNode->previous =nullptr;
    if(head == nullptr){
        head=newNode;
        tail=newNode;
        
    }
}