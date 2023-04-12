//
// Created by Allen Lam on 5/23/21.
//

#include "Splash.h"

Splash::Splash(sf::RenderTarget &win)
{
    sf::Sprite logo;
    sf::Texture texture;
    sf::Text Name;
    sf::Text Instructions;
    sf::Font font;
    sf::Sprite start;
    sf::Texture textureS;
    Instructions.setString("Num 1-5 to select card Left and Right to view more cards");
    Instructions.setFont(font);
    Instructions.setCharacterSize(80);
    Instructions.setPosition(20,1100);
    textureS.loadFromFile("PngItem_1579149.png");
    start.setTexture(textureS);
    start.setScale(sf::Vector2f(.4,.4));
    start.setPosition(890,900);
    Name.setString("Allen Lam CRN:31195 CS 003A Spring 2021 ");
    font.loadFromFile("SHRIMP.ttf");
    Name.setFont(font);
    Name.setCharacterSize(100);
    Name.setPosition(200,40);
    texture.loadFromFile("1280px-UNO_Logo.svg.png");
    logo.setTexture(texture);
    logo.setScale(sf::Vector2f(.6f, .6f));
    logo.setPosition(sf::Vector2f(740,195));
    win.draw(Instructions);
    win.draw(logo);
    win.draw(start);
    win.draw(Name);
}
