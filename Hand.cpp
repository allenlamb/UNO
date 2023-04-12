//
// Created by Allen Lam on 5/20/21.
//

#include "Hand.h"


int Hand::hSize() const
{
    return handList.size();
}

void Hand::addHand(Card x)
{
    handList.push_back(x);
}

void Hand::displayHand(sf::RenderTarget& window, int page) const
{
    Node*n = handList.index(page*5);
    sf::Vector2f x;
    x.y=760;
    x.x=300;
    for(int i=0;i<5;i++)
    {
        n->data.draw(window,x);
        if (n->next==nullptr) break;
        n=n->next;
        x.x+=380;
    }

}

Card Hand::send(int index)
{
    Node*n = handList.index(index);
    return n->data;

}

void Hand::removeCard(int index)
{
handList.remove(send(index));
}
