//
// Created by Allen Lam on 5/21/21.
//

#ifndef UNO_CIP_H
#define UNO_CIP_H
#include "Card.h"
class CIP //stands for Card In Play
{
public:
    bool valid(const Card& n);
    void first(const Card& n);
    Card face();
    void displayCIP(sf::RenderWindow& win);
private:
    Card _face;
    bool turn; //delete later

};

#endif //UNO_CIP_H
