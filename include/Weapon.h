#ifndef WEAPON_H
#define WEAPON_H

#include "Ammo.h"
class Weapon
{
    public:
        Weapon();
        virtual ~Weapon();

        enum Weapon_Type {Gun, RPG, Laser};

        Weapon_Type GetWeapon_Type() { return Artillery; }
        void SetWeapon_Type(Weapon_Type val) { Artillery = val; }
        int GetFire_Rate() { return Fire_Rate; }
        void SetFire_Rate(int val) { Fire_Rate = val; }
        Ammo GetAmmo_Type() { return Weapon_Ammo; }
        void SetAmmo_Type(Ammo val) { Weapon_Ammo = val; }
        Position getAmmoLocation();
        void setAmmoLocation(unsigned int x, unsigned int y);
        void reduceAmmo();
        int getRemainingAmmo();

    protected:

    private:
        Weapon_Type Artillery;
        int Fire_Rate;
        Ammo Weapon_Ammo;
};

#endif // WEAPON_H
