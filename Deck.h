//
// Created by Allen Lam on 5/20/21.
//

#ifndef UNO_DECK_H
#define UNO_DECK_H
#include <ctime>
#include "Card.h"
#include "Stack.h"

class Deck
{
public:
    Deck();
    int dSize();
    Card deal();
private:
    Stack stack;
    static void deckInit(Card* ptr); //Initializes a deck of 52 UNO cards using dynamic allocation
    static void shuffle(Card* ptr); //deck will then be shuffled
    void deckStack(Card* ptr); //deck will then be changed into a Stack data type
};
#endif //UNO_DECK_H
