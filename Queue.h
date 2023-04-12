//
// Created by Allen Lam on 6/1/21.
//

#ifndef UNO_QUEUE_H
#define UNO_QUEUE_H
#include "LinkedList.h"

class Queue
{
public:
    void push(const Card& item);
    void pop();
    Card top();
    bool empty();
    int size();
    friend std::ostream &operator<<(std::ostream out, const Queue &Queue);
private:
    LinkedList list;

};


#endif //UNO_QUEUE_H
