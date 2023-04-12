//
// Created by Allen Lam on 6/1/21.
//

#include "Queue.h"

void Queue::push(const Card& item)
{
    list.push_back(item);
}

void Queue::pop()
{
    list.remove(list.front());
}

Card Queue::top()
{
    return list.front();
}

bool Queue::empty()
{
    return list.empty();
}

int Queue::size()
{
    return list.size();
}
