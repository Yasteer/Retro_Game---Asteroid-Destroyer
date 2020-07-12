#ifndef RUN_GAME_H
#define RUN_GAME_H

#include "Player_Presentation.h"
#include "Weapon_Presentation.h"
#include "Asteroid_Presentation.h"

#include<SFML/Graphics.hpp>
class Run_Game
{
    public:
        Run_Game();
        virtual ~Run_Game();

        void Run();

    protected:

    private:
        Player_Presentation player;
        Weapon_Presentation weapon;
        Asteroid_Presentation asteroids;

        sf::RenderWindow Game_Screen;
};

#endif // RUN_GAME_H
