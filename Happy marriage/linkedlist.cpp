#include "linkedlist.h"
#include <iostream>
#include <climits>
LinkedList::Node::Node(int value) : data(value), previous(nullptr), next(nullptr){
    std::cout<<"Node created";
}
LinkedList::LinkedList():head(nullptr),tail(nullptr){
    std::cout<<"linked list created";
}
LinkedList::LinkedList(int size,int value):head(nullptr),tail(nullptr){
    for(int i=0;i<size;i++){
        push_back(value);
    }
    std::cout<<"Linked list created withe size "<<size<<" and value "<<value<<"."<<std::endl;
}
LinkedList::LinkedList(const LinkedList& other):head(nullptr),tail(nullptr){
    Node* current = other.head;
    while(current != nullptr){
        push_back(current->data);
        current=current->next;
    }
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
    else{
        head->previous=newNode;
        newNode->next= head;
        head=newNode;
    }
}
int LinkedList::pop_back() {
    if (tail == nullptr) {
        return -1; 
    }
    int value = tail->data;  
    if (tail == head) {
        delete tail;  
        tail = nullptr;
        head = nullptr;
    } else {
        Node* temp = tail;  
        tail = tail->previous;  
        tail->next = nullptr;  
        delete temp;  
    }
    return value;  
}
int LinkedList::pop_front() {
    if (head == nullptr) {
        return -1;  
    }
    int value = head->data;  
    if (head == tail) { 
        delete head;  
        head = nullptr;
        tail = nullptr;
    } else {  
        Node* temp = head;  
        head = head->next;  
        head->previous = nullptr;  
        delete temp; 
    }
    return value;  
}

bool LinkedList::is_empty()const{
    if(head==nullptr){
        return false;
    }
    else{
        return true;
    }
}
int LinkedList::get_size()const{
    if(head==nullptr){
        return -1;
    }
    int count=0;
    Node* temp=head;
    while(temp!=nullptr){
        temp=temp->next;
        count++;
    }
    return count;
}
int LinkedList::at(int index)const{
    if(index<0){
        std::cout<<"Index out of range"<<std::endl;
        return INT_MIN;
    }
    int size=get_size();
    if(size==-1){
        std::cout<<"List is empty!"<<std::endl;
        return INT_MIN;
    }
    else if(index>=size){
        std::cout<<"Index is out of range!"<<std::endl;
        return INT_MIN;
    }
    Node* temp=head;
    for(int i=0;i<index;i++){
        temp=temp->next;
    }
    return temp->data;
}
LinkedList::~LinkedList(){
    while(head!=nullptr){
        pop_front();
    }
    head=nullptr;
    tail=nullptr;
    std::cout<<"list deletd!"<<std::endl;
}
