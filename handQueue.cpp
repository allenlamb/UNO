//
// Created by Allen Lam on 5/20/21.
//

#include "handQueue.h"

bool handQueue::needCard(Hand& x, CIP& cip)
{
    Queue hand;
    for (int i=0;i<x.hSize();i++)
    {
        hand.push(x.send(i));
        if (cip.valid(hand.top())||hand.top().col()==BLANK) return false;
        hand.pop();
    }
    return true;
}
