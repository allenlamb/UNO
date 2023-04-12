//
// Created by Allen Lam on 5/20/21.
//

#include "Deck.h"
#include <iostream>
Deck::Deck()
{
    Card* ptr= new Card[52];
    deckInit(ptr);
    shuffle(ptr);
    deckStack(ptr);
    delete [] ptr;

}
void Deck::deckInit(Card* ptr)
{

    int countCol=0, countNum=0;
    for (int i=0; i<48;i++) //creates all the color cards
    {
        ptr[i].setCard(countNum++,countCol);
        if (countNum==12)
        {
            countNum=0;
            countCol++;
        }
    }
    ptr[48].setCard(WILD,BLANK); //creates the last 4 special cards
    ptr[49].setCard(WILD, BLANK);
    ptr[50].setCard(DRAW4,BLANK);
    ptr[51].setCard(DRAW4,BLANK);
}
void Deck::shuffle(Card* ptr)
{
    srand(time(nullptr)); //Fisher Yates shuffle method
    for (int i=51;i!=0;i--)
    {
        int j=rand()%i;
        Card temp;
        temp.setCard(ptr[i].num(),ptr[i].col());
        ptr[i].setCard(ptr[j].num(),ptr[j].col());
        ptr[j].setCard(temp.num(),temp.col());
    }
}


Card Deck::deal()
{
    Card temp;
    temp.setCard(stack.top().num(),stack.top().col());
    stack.pop();
    return temp;
}

void Deck::deckStack(Card *ptr)
{
    for (int i=0;i<52;i++)
    {
        Card temp;
        temp.setCard((ptr+i)->num(),(ptr+i)->col());
        stack.push(temp);
    }
}

int Deck::dSize()
{
    return stack.size();
}
