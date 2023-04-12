//
// Created by Allen Lam on 5/20/21.
//

#include "Card.h"
#include <iostream>
Card::Card(int col, int val)
{
    setCard(val,col);
}

int Card::num() const
{
    return _num;
}

int Card::col() const
{
    return _col;
}

void Card::setCard(int num,int col)
{
    _num=num;
    _col=col;
    graphic.initializeGraphics(num,col);
}

/*void Card::drawCIP(sf::RenderTarget &window)
{
sf::Vector2f cent(250,500);
    graphic.draw(window);
}*/

void Card::draw(sf::RenderTarget &window,sf::Vector2f pos)
{

    graphic.setpos(pos);
    graphic.draw(window);

}


bool Card::operator==(const Card& item) const
{
    return(num()==item.num()&&col()==item.col());
}

void Card::sCol(int x)
{
    if(num()==WILD)
    {
        _col=x;
    }
}

Card::Card()
{
    setCard(0,0);
}

void Card::operator=(const Card &item)
{
    setCard(item.num(),item.col());
}

void Card::drawCIP(sf::RenderTarget &window)
{
    graphic.setpos(sf::Vector2f {1700,40});
    graphic.setsize(sf::Vector2f{400,532});
    graphic.draw(window);
}



