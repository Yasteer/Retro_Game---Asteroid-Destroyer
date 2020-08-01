#ifndef WEAPON_PRESENTATION_H
#define WEAPON_PRESENTATION_H

#include <SFML/Graphics.hpp>
#include "Weapon.h"
#include "Position.h"
#include "Size.h"
class Weapon_Presentation
{
    public:
        Weapon_Presentation();
        virtual ~Weapon_Presentation();

        void draw(sf::RenderWindow& window);
        void update(float dt);

        void Fire_Weapon(Position Player_Position);
        Position GetWeaponOrigin();

        Position Get_Ammo_Origin();
        void Set_Ammo_Origin(Position Previous_Position);

        Position getAmmoPosition();
        void SetAmmoPosition(Position newPosition) {weapon_position = newPosition;};

        Size getAmmoSize();

        void setWeapon(int Hit_Count);

    protected:

    private:
        Weapon weapon;
        Position weapon_position;
        Position weapon_origin;

        sf::Texture Ammo_Texture;

        sf::Sprite Bullet_Sprite;
        sf::Sprite Bullet_EndLife_Sprite;

        sf::Texture Rocket_Texture;
        sf::Sprite Rocket_Sprite;
        sf::Sprite Rocket_EndLife_Sprite;

        sf::Texture Laser_Texture;
        sf::Sprite Laser_Sprite;
        sf::Sprite Laser_EndLife_Sprite;

        bool Terminate_Ammo_Sprite;
};

#endif // WEAPON_PRESENTATION_H
