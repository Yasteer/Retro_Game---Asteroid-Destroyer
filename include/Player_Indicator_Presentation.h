#ifndef PLAYER_INDICATOR_PRESENTATION_H
#define PLAYER_INDICATOR_PRESENTATION_H

#include <SFML/Graphics.hpp>
#include "Player_Indicators.h"
#include <vector>
class Player_Indicator_Presentation
{
    public:
        Player_Indicator_Presentation();
        virtual ~Player_Indicator_Presentation();

        void draw(sf::RenderWindow& window);
        void update(float dt);

        void Reduce_Life();
        int  Get_Lives();

    protected:

    private:
        Player_Indicators Indicators;

        sf::Texture Health_Texture;
        sf::Sprite Health_Sprite;
        std::vector <sf::Sprite> Health_Sprites;

        sf::Texture Mana_Texture;
        sf::Sprite  Mana_Sprite1;
        sf::Sprite  Mana_Sprite2;
        sf::Sprite  Mana_Sprite3;
        sf::Sprite  Mana_Sprite4;
        sf::Sprite  Mana_Sprite5;
        sf::Sprite  Mana_Sprite6;

};

#endif // PLAYER_INDICATOR_PRESENTATION_H
