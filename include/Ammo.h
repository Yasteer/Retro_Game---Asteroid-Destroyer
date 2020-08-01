#ifndef AMMO_H
#define AMMO_H

#include "Position.h"
#include "Size.h"
#include <iostream>
class Ammo
{
    public:
        Ammo();
        virtual ~Ammo();

        enum Type_Of_Round {Bullets, Explosive_Round, Beam};

        Type_Of_Round GetType_Of_Round() const { return Ammo_Type; }
        void SetType_Of_Round(Type_Of_Round val) { Ammo_Type = val; }
        int GetRemaining_Ammo() const { return Remaining_Ammo; }
        void SetRemaining_Ammo(int val) { Remaining_Ammo = val; }

        Position getAmmoOrigin()   const {return Ammo_Origin;};
        void setAmmoOrigin(Position New_Origin) { Ammo_Origin = New_Origin; }
        Position getAmmoPosition() const {return Ammo_Location;};
        void setAmmoPosition(Position New_Position) { Ammo_Location = New_Position; }

        bool moveAmmo();

        Size getAmmoSize() const {return Ammo_Size;}
        bool GetAmmoStatus() const {return Ammo_End_Of_Life;}

    protected:

    private:
        Type_Of_Round Ammo_Type;
        int Remaining_Ammo;

        Position Ammo_Origin;
        Position Ammo_Location;
        Size Ammo_Size;

        bool Ammo_End_Of_Life;
};

#endif // AMMO_H
