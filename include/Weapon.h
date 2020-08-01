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
        void SetWeapon_Type(Weapon_Type val);

        int GetFire_Rate() { return Fire_Rate; }
        void SetFire_Rate(int val) { Fire_Rate = val; }

        Ammo GetAmmo_Type() { return Weapon_Ammo; }
        void SetAmmo_Type();

        Size GetAmmoSize() { return Weapon_Ammo.getAmmoSize(); }

        Position GetAmmoOrigin () const { return Weapon_Ammo.getAmmoOrigin();}
        void SetAmmoOrigin (Position Origin) {Weapon_Ammo.setAmmoOrigin(Origin); Weapon_Ammo.setAmmoPosition(Origin);}

        Position GetAmmoPosition () const { return Weapon_Ammo.getAmmoPosition(); }
        void SetAmmoLocation(Position New_Location) {Weapon_Ammo.setAmmoPosition(New_Location);}

        void ReduceAmmo();
        int  GetRemainingAmmo() const { return Weapon_Ammo.GetRemaining_Ammo();}

        void Move_Ammo();
        bool GetTerminationStatus() const { return AmmoStatus;}
        void SetTerminationStatus(bool Status) {Weapon_Ammo.GetAmmoStatus();}

    protected:

    private:
        Weapon_Type Artillery;
        unsigned int Fire_Rate;
        Ammo Weapon_Ammo;
        bool AmmoStatus;
};

#endif // WEAPON_H
