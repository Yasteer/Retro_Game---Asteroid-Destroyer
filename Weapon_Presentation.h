#ifndef WEAPON_PRESENTATION_H
#define WEAPON_PRESENTATION_H

#include <SFML/Graphics.hpp>
#include "Weapon.h"
#include "Position.h"
class Weapon_Presentation
{
    public:
        Weapon_Presentation();
        virtual ~Weapon_Presentation();

        void draw(sf::RenderWindow& window);
        void update(float dt);

        void Fire_Weapon(Position Player_Position);
        void Set_Ammo_Origin(Position Previous_Position);

    protected:

    private:
        Weapon weapon;

        sf::Texture Ammo_Texture;
        sf::Sprite Ammo_Sprite;
        sf::Sprite Bullet_Sprite;
        sf::Sprite Rocket_Sprite;
        sf::Sprite Laser_Sprite;
};

#endif // WEAPON_PRESENTATION_H
