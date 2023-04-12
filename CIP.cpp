//
// Created by Allen Lam on 5/21/21.
//
#include <iostream>
#include "CIP.h"
Card CIP::face()
{
    return _face;
}

void CIP::first(const Card &n)
{
    _face=n;
}

void CIP::displayCIP(sf::RenderWindow& win)
{
    _face.drawCIP(win);
}

bool CIP::valid(const Card &n)
{
    if(face().col()==n.col()||n.col()==BLANK||face().col()==BLANK||face().num()==n.num()) return true;

    else return false;

}
