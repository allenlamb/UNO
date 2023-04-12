//
// Created by Allen Lam on 6/4/21.
//

#ifndef UNO_STACK_H
#define UNO_STACK_H
#include "LinkedList.h"
class Stack
{
public:
    void push(const Card& item);//adds an item
    void pop(); //removes a node at the end
    Card top(); //looks at the top node
    bool empty(); //know if it is empty
    int size();
    friend std::ostream& operator<<(std::ostream& out, const Stack& stack);
private:
    LinkedList list;

};
#endif //UNO_STACK_H
