#include "Weapon.h"
#include <iostream>
Weapon::Weapon()
{
    SetWeapon_Type(Gun); // Set defualt weapon to guns for the beginning of the game.
    //SetWeapon_Type(RPG);
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

void Weapon::SetWeapon_Type(Weapon_Type val)
{
    Artillery = val;
    SetAmmo_Type();
    return;
}

void Weapon::SetAmmo_Type()
{
    int Weapon_Selection = GetWeapon_Type();
    switch (Weapon_Selection)
    {
    case 0: // Gun
        Weapon_Ammo.SetType_Of_Round(Weapon_Ammo.Bullets);
        break;
    case 1: // RPG
        Weapon_Ammo.SetType_Of_Round(Weapon_Ammo.Explosive_Round);
        break;
    case 2: // Laser
        Weapon_Ammo.SetType_Of_Round(Weapon_Ammo.Beam);
        break;
    }
    return;
}
