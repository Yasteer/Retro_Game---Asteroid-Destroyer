#include "Weapon.h"

Weapon::Weapon()
{
    SetWeapon_Type(Gun); // Set defualt weapon to guns for the beginning of the game.
}

Weapon::~Weapon()
{
    //dtor
}

void Weapon::ReduceAmmo()
{
    unsigned int Current_Ammo = Weapon_Ammo.GetRemaining_Ammo();
    Weapon_Ammo.SetRemaining_Ammo(Current_Ammo - 1);
    return;
}

void Weapon::Move_Ammo()
{
    Weapon_Ammo.moveAmmo();
    GetTerminationStatus();
    return;
}
