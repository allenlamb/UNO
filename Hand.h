//
// Created by Allen Lam on 5/20/21.
//

#ifndef UNO_HAND_H
#define UNO_HAND_H
#include "Card.h"
#include "LinkedList.h"


class Hand{
public:
    void addHand(Card x);
    void displayHand(sf::RenderTarget& temp, int page) const; //remember to deleted render parameter
    int hSize() const;
    Card send(int index);
    void removeCard(int index);
private:
    LinkedList handList;
};

#endif //UNO_HAND_H
