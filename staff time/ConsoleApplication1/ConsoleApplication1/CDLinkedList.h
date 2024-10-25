#pragma once
#include "Gun.h"
#include "Node.h"
class LinkedList {
private:
    Node* head;
    Node* tail;
   static int size;
public:
    LinkedList();
    ~LinkedList();
    void addGun(const Gun&);
    void DeActiveGun(const std::string&);
    void ActiveGun(const std::string&);
    void removeGun(const std::string&);
    void displayGuns()const;
    static int getSize();
    bool CompareNodes(Node* , Node*);
    void IncrementNode(Node*);
    bool IsGreaterThan(Node* , Node*);
    bool IsLessThan(Node*, Node*);
    bool IsGreaterOrEqual(Node*, Node*);
    bool IsLessOrEqual(Node*, Node*);
    void DoubleAmmo(Node*);
    void HalveAmmo(Node*);
    Node* getNodeAt(int);
    Node* findGunByName(const std::string& name);
};