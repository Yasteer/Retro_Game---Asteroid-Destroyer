#include "Player.h"

Player::Player() // Default Parameters For A Player
{
    Player_Size.SetHeight(10);
    Player_Size.SetLength(5);

    Location.SetX_Coordinate(900);
    Location.SetY_Coordinate(500);
}

Player::Player(Position XY, Weapon Guns)
{
    Player_Size.SetHeight(5);
    Player_Size.SetLength(10);
    Location = XY;
    Main_Artillery = Guns;
    // Player will not begin with any special abilities.
}

Player::~Player()
{

}

Position Player::getPosition()
{
    return Location;
}

void Player::setPosition(unsigned int x, unsigned int y)
{
    Location.SetX_Coordinate(x);
    Location.SetY_Coordinate(y);
    return;
}

Weapon Player::getWeapon()
{
    return Main_Artillery;
}

Size Player::getPlayerSize()
{
    return Player_Size;
}
