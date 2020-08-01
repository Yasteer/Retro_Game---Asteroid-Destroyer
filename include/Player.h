#ifndef PLAYER_H
#define PLAYER_H

#include "Position.h"
#include "Weapon.h"
#include "Upgrade.h"
#include "Size.h"
class Player
{
    public:
        Player();
        Player(Position XY, Weapon Guns);
        virtual ~Player();

        Position getPosition();
        void setPosition(unsigned int x, unsigned int y);
        Size getPlayerSize();

    protected:

    private:
        Position Location;
        Weapon Main_Artillery;
        Upgrade Special_Ability;
        Size Player_Size;
};

#endif // PLAYER_H
