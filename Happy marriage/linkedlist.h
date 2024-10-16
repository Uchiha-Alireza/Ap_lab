#ifndef LINKEDLIST_H
#define LINKEDLIST_H
class LinkedList{
    private:
    struct Node{
    int data;
    Node* previous;
    Node* next;
    Node(int value);
    };
    Node* head;
    Node* tail;
    public:
    LinkedList();
    LinkedList(int size,int value);
    LinkedList(const LinkedList& other);
    ~LinkedList();
    void push_back(int value);
    void push_front(int value);
    int pop_back();
    int pop_front();
    bool is_empty()const;
    int get_size()const;
    int at(int index)const;
};
#endif 
