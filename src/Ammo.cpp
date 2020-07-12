#include "Ammo.h"

Ammo::Ammo()
{
    Ammo_Type = Bullets; // Default Ammo
    Remaining_Ammo = 100;
}

Ammo::~Ammo()
{
    //dtor
}

Position Ammo::getAmmoPosition()
{
    return Origin;
}

void Ammo::setAmmoPosition(unsigned int x, unsigned int y)
{
    Origin.SetX_Coordinate(x);
    Origin.SetY_Coordinate(y);
    return;
}
