#include "Ammo.h"
#include <iostream>
Ammo::Ammo()
{
    Ammo_Type = Bullets; // Default Ammo
    Remaining_Ammo = 100;
    Ammo_End_Of_Life = false;
}

Ammo::~Ammo()
{
    //dtor
}

bool Ammo::moveAmmo()
{
    if(Ammo_Type == Bullets)
    {
        int Current_Y_Position = Ammo_Location.GetY_Coordinate();
        Ammo_Location.SetY_Coordinate(Current_Y_Position - 5);
        if(Ammo_Location.GetY_Coordinate() < Ammo_Origin.GetY_Coordinate() - 400)
        {
            Ammo_End_Of_Life = true;
            Ammo_Location.SetX_Coordinate(65536); // Move the bullet somewhere towards the bottom right of the screen.
            Ammo_Location.SetY_Coordinate(65536); // Out of sight from the player and hopefully far enough not to interfere with any other sprites.
        }
    }
    if(Ammo_Type == Explosive_Round)
    {

    }
    else if(Ammo_Type == Beam)
    {

    }
    return Ammo_End_Of_Life;
}
