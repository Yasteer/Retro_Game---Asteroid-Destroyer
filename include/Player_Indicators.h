#ifndef PLAYER_INDICATORS_H
#define PLAYER_INDICATORS_H

#include "Upgrade.h"
#include <iostream>
#include <vector>
class Player_Indicators
{
    public:
        Player_Indicators();
        virtual ~Player_Indicators();

        std::vector <bool> GetLives() const { return Lives; } // Vector is of a primitive type so returning a copy is okay.
        void DecreaseLives();
        void IncreaseLives();

        unsigned int GetMana() const { return Mana; }
        void DecreaseMana(const Upgrade& Upgrade_Type);
        void IncreaseMana();

    protected:

    private:
        std::vector <bool> Lives;
        unsigned int Mana;

        Upgrade Player_Upgrade;
};

#endif // PLAYER_INDICATORS_H
