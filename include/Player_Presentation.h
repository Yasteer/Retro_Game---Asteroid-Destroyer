#ifndef PLAYER_PRESENTATION_H
#define PLAYER_PRESENTATION_H

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Position.h"

class Player_Presentation
{
    public:
        Player_Presentation();
        virtual ~Player_Presentation();

        void draw(sf::RenderWindow& window); // Window passed by reference so that window can be changed.
        void update(float dt); // dt is Delta Time used for frame rate.
        void move_player(char newDirection);

        Position getPlayerPosition();

    protected:

    private:
        Player Player_Object;

        sf::Texture Player_Texture;
        sf::Sprite Player_Sprite;
};

#endif // PLAYER_PRESENTATION_H
