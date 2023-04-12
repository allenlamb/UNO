//
// Created by Allen Lam on 5/23/21.
//
#include "GAME.h"
GAME::GAME()
{
    dealing();
    sf::RenderWindow window(sf::VideoMode(2400, 1200), "My window");
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::MouseButtonReleased&&state==-1)
            {
                if (event.mouseButton.button == sf::Mouse::Left&&event.mouseButton.x>900&&event.mouseButton.x<1400&&event.mouseButton.y>900&&event.mouseButton.y<1100)
                {
                        state=1;
                }
            }
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyReleased&&state==1)
            {
                if (event.key.code == sf::Keyboard::Num1)
                {
                    if ((page*5)<currentSize())
                        playCard(5*page,window);
                }
                if (event.key.code == sf::Keyboard::Num2)
                {
                    if ((page*5+1)<currentSize())
                        playCard(5*page+1,window);
                }
                if (event.key.code == sf::Keyboard::Num3)
                {
                    if ((page*5+2)<currentSize())
                        playCard(5*page+2,window);
                }
                if (event.key.code == sf::Keyboard::Num4)
                {
                    if ((page*5+3)<currentSize())
                    playCard(5*page+3,window);
                }
                if (event.key.code == sf::Keyboard::Num5)
                {
                    if ((page*5+4)<currentSize())
                    playCard(5*page+4,window);
                }
                if (event.key.code == sf::Keyboard::Left)
                {
                    pageHandle(0);
                }
                if (event.key.code == sf::Keyboard::Right)
                {
                    pageHandle(1);
                }
            }
            if (event.type == sf::Event::KeyReleased&&state==0)
            {
                if (event.type == sf::Event::Closed)
                    window.close();
                if (event.key.code == sf::Keyboard::Q)
                {
                    wildHandle(0, window);
                }
                if (event.key.code == sf::Keyboard::W)
                {
                    wildHandle(1, window);
                }
                if (event.key.code == sf::Keyboard::E)
                {
                    wildHandle(2, window);
                }
                if (event.key.code == sf::Keyboard::R)
                {
                    wildHandle(3, window);
                }
            }
        }
        window.clear();
        if (state==-1)
        {
            Splash splish(window);
        }
        if (state==1)
        {
            displayTurn(window);
            displayH(window);
            activeCard.displayCIP(window);
        }
        if (state==0)
        {
            wildPrompt(window);
        }
        if (state==2)
        {
            EndScreen s(window);
        }
        if (state==3||state==4)
        {
            sf::Sprite sprite;
            sf::Texture texture;
            sprite.setPosition(720,600);
            if (state==3)
            {
                texture.loadFromFile("msg-player1-wins.png");
                sprite.setTexture(texture);
                window.draw(sprite);
            }
            if (state==4)
            {
                texture.loadFromFile("msg-player2-wins.png");
                sprite.setTexture(texture);
                window.draw(sprite);
            }
        }
            window.display();
    }
}

void GAME::dealing()
{
    std::cout << "Turn 1"<<std::endl;
    turn=true;
   for (int i=0;i<6;i++)
   {
      handP1.addHand(deck.deal());
      handP2.addHand(deck.deal());
   }
   activeCard.first(deck.deal());
    needCard();
    std::cout<<"Deck Size:"<<deck.dSize()<<std::endl;
}

void GAME::displayH(sf::RenderTarget& win)
{
    if (turn)
    {
        handP1.displayHand(win,page);
    }
    if (!turn)
    {
        handP2.displayHand(win,page);
    }
}

void GAME::playCard(int index,sf::RenderTarget& win)
{
    if (turn)
    {
        if (activeCard.valid(handP1.send(index)))
        {
            activeCard.first(handP1.send(index));
            if (handP1.send(index).num()==DRAW2)
            {
                if(deck.dSize()<=1) state=2;
                else
                {
                    handP2.addHand(deck.deal());
                    handP2.addHand(deck.deal());
                }
                std::cout<<"Deck Size:"<<deck.dSize()<<std::endl;
            }
            if (handP1.send(index).num()==SKIP)
            {
                page=0;
                needCard();
            }
            if (handP1.send(index).num()==WILD)
            {
               state=0;
               mess=WILD;
               storage=index;
            }
            if (handP1.send(index).num()==DRAW4)
            {
                if (deck.dSize()<=3) state=2;
                else for (int i=0;i<4;i++)
                {
                    handP2.addHand(deck.deal());
                }

                state=0;
                mess=DRAW4;
                storage=index;
                std::cout<<"Deck Size:"<<deck.dSize()<<std::endl;

            }
            if (state==1)
            {
               if (handP1.send(index).num()!= SKIP||handP1.send(index).num()!= WILD||handP1.send(index).num()!= DRAW4)
                   newTurn();
                handP1.removeCard(index);
            }
        }
    }
    else if(!turn)
    {
        if (activeCard.valid(handP2.send(index)))
        {
            activeCard.first(handP2.send(index));
            if (handP2.send(index).num() == DRAW2)
            {
                if(deck.dSize()<=1) state=2;
                else
                {
                    handP1.addHand(deck.deal());
                    handP1.addHand(deck.deal());
                }

                std::cout<<"Deck Size:"<<deck.dSize()<<std::endl;
            }
            if (handP2.send(index).num() == SKIP)
            {
                page=0;
                needCard();
            }
            if (handP2.send(index).num() == WILD)
            {
                state=0;
                mess=WILD;
                storage=index;
            }
            if (handP2.send(index).num() == DRAW4)
            {
                if (deck.dSize()<=3) state=2;
                else for (int i=0;i<4;i++)
                {
                    handP1.addHand(deck.deal());
                }
                state=0;
                mess=DRAW4;
                storage=index;
                std::cout<<"Deck Size:"<<deck.dSize()<<std::endl;
            }
            if(state==1)
            {
                if (handP2.send(index).num()!= SKIP||handP2.send(index).num()!= WILD||handP2.send(index).num()!= DRAW4) newTurn();
                handP2.removeCard(index);
            }
        }
    }
}

void GAME::pageHandle(int x)
{
    if (turn)
    {
        if (x==1)
        {
            if (page+1 < (double)handP1.hSize()/5)
            {
                page++;
            }
        }
        if(x==0)
        {
            if (page > 0)
            {
                page--;
            }
        }
    }
    if (!turn)
    {
        if (x==1)
        {
            if (page + 1< (double)handP2.hSize()/5)
                page++;
        }
        if(x==0)
        {
            if (page > 0)
            {
                page--;
            }
        }
    }


}


void GAME::wildPrompt(sf::RenderTarget& win) const
{
    sf::Text prompt;
    sf::Font font;
    font.loadFromFile("SanMarinoBeach-2OOLW.ttf");
    prompt.setString("Select a color with Q W E R");
    prompt.setFont(font);
    prompt.setCharacterSize(100);
    prompt.setPosition(214,600);
    Hand tempWild;
    Card Red(0,mess);
    Card Blue(1,mess);
    Card Green(2,mess);
    Card Yellow(3,mess);
    tempWild.addHand(Red);
    tempWild.addHand(Blue);
    tempWild.addHand(Green);
    tempWild.addHand(Yellow);
    win.draw(prompt);
    tempWild.displayHand(win,0);
}

int GAME::currentSize()
{
    if (turn) return handP1.hSize();
    if (!turn) return handP2.hSize();
}

void GAME::wildHandle(int index, sf::RenderTarget &win)
{
    if (turn)
    {
        Card temp(index,mess);
        activeCard.first(temp);
        handP1.removeCard(storage);
    }
    if (!turn)
    {
        Card temp(index,mess);
        activeCard.first(temp);
        handP2.removeCard(storage);
    }
    state=1;
    storage=0;
    mess=0;
    newTurn();
}

void GAME::newTurn()
{
    if (handP1.hSize()==0) state=3;
    if (handP2.hSize()==0) state=4;
    page=0;
    turn=!turn;
    if (turn) std::cout << "Turn:" << 1<<std::endl;
    if (!turn) std::cout << "Turn:" << 2<<std::endl;
    needCard();
    std::cout << "Deck Size: "<<deck.dSize() <<std::endl;
}

void GAME::needCard()
{
    if (turn)
    {
        while (check.needCard(handP1, activeCard))
        {
            if(deck.dSize()==0)state=2;
            else
            {
                std::cout << "Player: 1 draw card since no valid cards" << std::endl;
                handP1.addHand(deck.deal());
                std::cout << "Deck Size:" << deck.dSize() << std::endl;
            }
        }
    }
    else if (!turn)
    {
        while (check.needCard(handP2, activeCard))
        {
            if(deck.dSize()==0)state=2;
            else
            {
                std::cout << "Player: 2 draw card since no valid cards"<<std::endl;
                handP2.addHand(deck.deal());
                std::cout<<"Deck Size:"<<deck.dSize()<<std::endl;
            }

        }
    }
}

void GAME::displayTurn(sf::RenderTarget& win)
{
    sf::Text text;
    sf::Font font;
    if (turn) text.setString("PLAYER 1");
    if (!turn) text.setString("PLAYER 2");
    text.setCharacterSize(90);
    font.loadFromFile("SanMarinoBeach-2OOLW.ttf");
    text.setFont(font);
    text.setPosition(0,0);
    win.draw(text);
}