#include "Weapon_Presentation.h"
#include <iostream>

Weapon_Presentation::Weapon_Presentation()
{
    if(!Ammo_Texture.loadFromFile("Ammo_Sprite_Sheet.png")) // Public domain sheet taken from http://m484games.ucoz.com/
    {
        // handle error.
    }
    Ammo_Sprite.setTexture(Ammo_Texture);
    Bullet_Sprite.setTexture(Ammo_Texture);
    Bullet_Sprite.setTextureRect(sf::IntRect(275,20,25,20)); // First pair --> Top Left of Rect. Second Pair --> Size of Rect.
    Bullet_Sprite.setRotation(270);
}

Weapon_Presentation::~Weapon_Presentation()
{

}

void Weapon_Presentation::draw(sf::RenderWindow& window)
{
    for(int step=0; step < 10; step++)
    {
        weapon.setAmmoLocation(weapon.getAmmoLocation().GetX_Coordinate(), weapon.getAmmoLocation().GetY_Coordinate() - 5);
        Bullet_Sprite.setPosition(weapon.getAmmoLocation().GetX_Coordinate() , weapon.getAmmoLocation().GetY_Coordinate());
        window.draw(Bullet_Sprite);
        std::cout<< Bullet_Sprite.getPosition().x << "    "<< Bullet_Sprite.getPosition().y << std::endl;
    }

    return;
}

void Weapon_Presentation::update(float dt)
{
    return;
}

void Weapon_Presentation::Fire_Weapon(Position Player_Position )
{
    weapon.reduceAmmo();
    Set_Ammo_Origin(Player_Position);
    std::cout << "Origin: " << Player_Position.GetX_Coordinate() << "   " << Player_Position.GetY_Coordinate() << std::endl;
    return;
}




void Weapon_Presentation::Set_Ammo_Origin(Position Previous_Position)
{
    weapon.setAmmoLocation(Previous_Position.GetX_Coordinate() + 42, Previous_Position.GetY_Coordinate() - 10); // Offset Ammo to fire just in front of the player sprite.
    return;
}


