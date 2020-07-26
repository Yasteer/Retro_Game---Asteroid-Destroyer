#include "Player_Indicators.h"
#include <iostream>

Player_Indicators::Player_Indicators()
{
    Mana  = 650;

    // Give player 3 lives at the beginning of the game.
    Lives.push_back(true);
    Lives.push_back(true);
    Lives.push_back(true);
}

Player_Indicators::~Player_Indicators()
{
    //dtor
}

void Player_Indicators::DecreaseLives()
{
    if(Lives.size() > 0)
    {
        Lives.pop_back();
    }
    return;
}

void Player_Indicators::IncreaseLives()
{
    if(Lives.size() <= 10)
    {
        Lives.push_back(true);
    }
    return;
}

void Player_Indicators::DecreaseMana(const Upgrade& Upgrade_Type)
{
    switch (Upgrade_Type.GetSpecial_Effect())
    {
    case 0: // Shields
        Mana -= 10;
        break;
    case 1: // Size Decrease
        Mana -= 4;
        break;
    case 2: // Speed Up
        Mana -= 2;
        break;
    case 3: // Armada Summon
        Mana -= 25;
        break;
    }

    return;
}
