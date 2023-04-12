//
// Created by Allen Lam on 6/8/21.
//

#include "EndScreen.h"

EndScreen::EndScreen(sf::RenderTarget &window)
{
    sf::Text text;
    text.setString("DRAW, NO MORE CARDS IN DECK");
    text.setCharacterSize(100);
    text.setPosition(410,500);
    sf::Font font;
    font.loadFromFile("SHRIMP.ttf");
    text.setFont(font);
    window.draw(text);
}
