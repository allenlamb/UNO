//
// Created by Allen Lam on 5/20/21.
//

#include "CardGraphics.h"
#include <iostream>
sf::RectangleShape CardGraphics::base()
{
    sf::RectangleShape _base;
    _base.setSize(size);
    _base.setPosition(_pos);
    _base.setOutlineColor(sf::Color::White);
    _base.setOutlineThickness(20);
    _base.setFillColor(findCol());
    return _base;
}
sf::CircleShape CardGraphics::circle()
{
    sf::CircleShape temp;
    temp.setRadius(size.x/1.8);
    temp.setFillColor(sf::Color::White);
    temp.setPosition(_pos.x-22,_pos.y+30);
    return temp;
}
sf::Text CardGraphics::num(const sf::Font& font)
{
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(size.x/1.4);
    if(_val==DRAW2||_val==DRAW4) _pos.x-=55;
    if(_val==WILD) _pos.x-=40;
    if(_val==ONE) _pos.x+=20;
    text.setPosition(_pos.x+80,_pos.y+60);
    text.setFillColor(sf::Color::Black);
    text.setString(findNum());
    return text;
}

sf::Color CardGraphics::findCol() const
{
    switch (_col)
    {
        case RED:
            return sf::Color::Red;
        case BLUE:
            return sf::Color::Blue;
        case GREEN:
            return sf::Color::Green;
        case YELLOW:
            return sf::Color::Yellow;
        case BLANK:
            return sf::Color::Black;
    }
    return sf::Color::White;
}

void CardGraphics::draw(sf::RenderTarget &window)
{
    sf::Font font;
    font.loadFromFile("SanMarinoBeach-2OOLW.ttf");
    window.draw(base());
    window.draw(circle());
    window.draw(num(font));
}

void CardGraphics::setpos(sf::Vector2f x)
{
_pos=x;
}

std::string CardGraphics::findNum() const
{
    switch (_val)
    {
        case ZERO:
            return "0";
        case ONE:
            return "1";
        case TWO:
            return "2";
        case THREE:
            return "3";
        case FOUR:
            return "4";
        case FIVE:
            return "5";
        case SIX:
            return "6";
        case SEVEN:
            return "7";
        case EIGHT:
            return "8";
        case NINE:
            return "9";
        case SKIP:
            return "X";
        case WILD:
            return "W";
        case DRAW2:
            return "2+";
        case DRAW4:
            return "4+";
    }
}

void CardGraphics::initializeGraphics(int sNum, int sCol)
{
    _col=sCol;
    _val=sNum;
}

void CardGraphics::setsize(sf::Vector2f y)
{
    size.x=y.x;
    size.y=y.y;
}

int CardGraphics::gCol()
{
    return _col;
}

int CardGraphics::gVal()
{
    return _val;
}





