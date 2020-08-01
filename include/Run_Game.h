#ifndef RUN_GAME_H
#define RUN_GAME_H

#include "Player_Presentation.h"
#include "Player_Indicator_Presentation.h"
#include "Weapon_Presentation.h"
#include "Asteroid_Presentation.h"
#include "Collision_Detection.h"

#define WIDTH 1400
#define HEIGHT 750

#include<SFML/Graphics.hpp>
class Run_Game
{
    public:
        Run_Game();
        virtual ~Run_Game();

        void Run();
        int GetWindowHeight()const {return HEIGHT;};
        int GetWindowWidth() const {return WIDTH; };

    protected:

    private:
        Player_Presentation player;
        Player_Indicator_Presentation indicators;
        Weapon_Presentation weapon;
        Asteroid_Presentation asteroids;

        Collision_Detection test;

        sf::RenderWindow Game_Screen;
        unsigned int Height;
        unsigned int Width;

        int Hit_Count;
};

#endif // RUN_GAME_H
