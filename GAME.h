//
// Created by Allen Lam on 5/23/21.
//

#ifndef UNO_GAME_H
#define UNO_GAME_H
#include "SFMl/Graphics.hpp"
#include "Deck.h"
#include "Hand.h"
#include "CIP.h"
#include "handQueue.h"
#include "Splash.h"
#include "EndScreen.h"
class GAME // this will be the main hub for all the objects to interact; keeps int main() neat
{
public:
    GAME();
private:
    void wildPrompt(sf::RenderTarget& win) const;
    void newTurn();
    void dealing();
    void displayH(sf::RenderTarget& win);
    void playCard(int index,sf::RenderTarget& win);
    void wildHandle(int index, sf::RenderTarget& win);
    void pageHandle(int x);
    int currentSize();
    void needCard();
    void displayTurn(sf::RenderTarget& win);
    Deck deck;
    Hand handP1;
    Hand handP2;
    CIP activeCard;
    handQueue check;
    bool turn;
    int page=0;
    int state=-1;
    int mess;
    int storage;
};


#endif //UNO_GAME_H
