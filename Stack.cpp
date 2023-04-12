//
// Created by Allen Lam on 5/23/21.
//

#include "Stack.h"
void Stack::push(const Card& item)
{
    list.push_back(item);
}

void Stack::pop()
{
    list.remove(list.back());
}

Card Stack::top()
{
    return list.back();
}

bool Stack::empty()
{
    return list.empty();
}

int Stack::size()
{
    return list.size();
}

std::ostream &operator<<(std::ostream &out, const Stack &stack)
{
    Stack temp = stack;
    int x=stack.list.size();
    for(int i=0;i<x;i++)
    {
        out<<i <<". "<< temp.top().num()<<" "<<temp.top().col()<<std::endl;
        temp.pop();
    }

    return out;
}


