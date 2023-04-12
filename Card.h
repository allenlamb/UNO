//
// Created by Allen Lam on 5/20/21.
//

#ifndef UNO_CARD_H
#define UNO_CARD_H


#include <SFML/Graphics.hpp>
#include "CardGraphics.h"

class Card
{
public:
    Card();
    Card(int col,int val);
    int num() const; //number value getter
    int col() const; //color getter
    void setCard(int num, int col); //setter
    void sCol(int x); //used only for the wild card
    void draw(sf::RenderTarget &window,sf::Vector2f pos);
    void drawCIP(sf::RenderTarget &window);
    void state(int x);
    bool operator ==(const Card& item) const;
    void operator =(const Card& item);
    CardGraphics graphic;
private:
    int _num{};
    int _col{};

};


#endif //UNO_CARD_H
