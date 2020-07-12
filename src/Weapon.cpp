#include "Weapon.h"

Weapon::Weapon()
{
    SetWeapon_Type(Gun); // Set defualt weapon to guns for the beginning of the game.
}

Weapon::~Weapon()
{
    //dtor
}

void Weapon::setAmmoLocation(unsigned int x, unsigned int y)
{
    Weapon_Ammo.setAmmoPosition(x,y);
    return;
}

Position Weapon::getAmmoLocation()
{
    return Weapon_Ammo.getAmmoPosition();
}

void Weapon::reduceAmmo()
{
    int Remaining_Ammo = Weapon_Ammo.GetRemaining_Ammo();
    Weapon_Ammo.SetRemaining_Ammo(Remaining_Ammo - 1);
    return;
}

int Weapon::getRemainingAmmo()
{
    return Weapon_Ammo.GetRemaining_Ammo();
}

