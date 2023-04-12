//
// Created by allen on 4/28/2021.
//

#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H
#include "Node.h"
#include <iostream>
class LinkedList
{
private:
    int _size=0;
    Node *head = nullptr;
    Node *tail = nullptr;
    void insertBefore(const Card& x,Node *node);
    void insertAfter(const Card& x, Node *node);
    Node *search(const Card& item);

public:
    Node * index(int x) const;
    void insertBefore(const Card& item, const Card& before);
    void insertAfter(const Card& item, const Card& after);
    void remove(const Card& item);
    void push_back(const Card& item);
    void push_front(const Card& item);
    int size() const;
    bool empty() const;
    friend std::ostream& operator<<(std::ostream& out,LinkedList x);
    Card back();
    Card front();
};
#endif //LINKEDLIST_LINKEDLIST_H
