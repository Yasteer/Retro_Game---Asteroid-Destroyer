#include "Player_Presentation.h"
#include <iostream>
Player_Presentation::Player_Presentation()
{
    if(!Player_Texture.loadFromFile("In_Game_Images/Player.png"))
    {
        // handle error
    }

    Player_Sprite.setTexture(Player_Texture);
    Player_Sprite.setScale(0.15,0.15);
}

Player_Presentation::~Player_Presentation()
{

}

void Player_Presentation::draw(sf::RenderWindow& window)
{
    window.draw(Player_Sprite);
    return;
}

void Player_Presentation::update(float dt)
{
    Player_Sprite.setPosition(Player_Object.getPosition().GetX_Coordinate(), Player_Object.getPosition().GetY_Coordinate());
    return;
}

void Player_Presentation::reset()
{
    Player_Object.setPosition(500, 500);
    return;
}

void Player_Presentation::move_player(char newDirection)
{
    switch(newDirection)
    {
    case 'W':
        Player_Object.setPosition(Player_Object.getPosition().GetX_Coordinate() , Player_Object.getPosition().GetY_Coordinate() - 50);
        break;
    case 'A':
        Player_Object.setPosition(Player_Object.getPosition().GetX_Coordinate() - 50 , Player_Object.getPosition().GetY_Coordinate());
        break;
    case 'S':
        Player_Object.setPosition(Player_Object.getPosition().GetX_Coordinate() , Player_Object.getPosition().GetY_Coordinate() + 50);
        break;
    case 'D':
        Player_Object.setPosition(Player_Object.getPosition().GetX_Coordinate() + 50 , Player_Object.getPosition().GetY_Coordinate());
        break;
    }
}

Position Player_Presentation::getPlayerPosition()
{
    return Player_Object.getPosition();
}

Size Player_Presentation::getPlayerSize()
{
    return Player_Object.getPlayerSize();
}
