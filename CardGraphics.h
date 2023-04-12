//
// Created by Allen Lam on 5/20/21.
//

#ifndef UNO_CARDGRAPHICS_H
#define UNO_CARDGRAPHICS_H
#include "SFML/Graphics.hpp"
#include "enums.h"
class CardGraphics //ADD A CIRCLE
{
public:
     virtual void draw(sf::RenderTarget& window);
     void initializeGraphics(int sNum, int sCol);
     void setpos(sf::Vector2f x);
     void setsize(sf::Vector2f y);
     int gCol();
     int gVal();
private:
    int _col;
    int _val;
    sf::Vector2f _pos;
    sf::RectangleShape base();
    sf::CircleShape circle();
    sf::Color findCol() const;
    std::string findNum() const;
    sf::Text num(const sf::Font& font);
    sf::Vector2f size{300,400};
};


#endif //UNO_CARDGRAPHICS_H
