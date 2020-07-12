#ifndef AMMO_H
#define AMMO_H

#include "Position.h"
#include "Size.h"

class Ammo
{
    public:
        Ammo();
        virtual ~Ammo();

        enum Type_Of_Round {Bullets, Explosive_Round, Beam};

        Type_Of_Round GetType_Of_Round() { return Ammo_Type; }
        void SetType_Of_Round(Type_Of_Round val) { Ammo_Type = val; }
        int GetRemaining_Ammo() { return Remaining_Ammo; }
        void SetRemaining_Ammo(int val) { Remaining_Ammo = val; }

        Position getAmmoPosition();
        void setAmmoPosition(unsigned int x, unsigned int y);

    protected:

    private:
        Type_Of_Round Ammo_Type;
        int Remaining_Ammo;

        Position Origin;
        Size Ammo_Size;
};

#endif // AMMO_H
