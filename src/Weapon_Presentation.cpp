#include "Weapon_Presentation.h"
#include <iostream>

Weapon_Presentation::Weapon_Presentation()
{
    if(!Ammo_Texture.loadFromFile("In_Game_Images/Ammo_Sprite_Sheet.png")) // Public domain sheet taken from http://m484games.ucoz.com/
    {
        // handle error.
    }
    Ammo_Sprite.setTexture(Ammo_Texture);
    Bullet_Sprite.setTexture(Ammo_Texture);
    Bullet_Sprite.setTextureRect(sf::IntRect(275,20,25,20)); // First pair --> Top Left of Rect. Second Pair --> Size of Rect.
    Bullet_Sprite.setRotation(270);
    Bullet_EndLife_Sprite.setTextureRect(sf::IntRect(137,27, 15,15));

    Terminate_Ammo_Sprite = false;
}

Weapon_Presentation::~Weapon_Presentation()
{

}

void Weapon_Presentation::draw(sf::RenderWindow& window)
{
    if(Terminate_Ammo_Sprite == true)
    {
        Bullet_Sprite.setPosition(weapon.GetAmmoPosition().GetX_Coordinate() , weapon.GetAmmoPosition().GetY_Coordinate());
        window.draw(Bullet_EndLife_Sprite);
    }
    Bullet_Sprite.setPosition(weapon.GetAmmoPosition().GetX_Coordinate() , weapon.GetAmmoPosition().GetY_Coordinate());
    window.draw(Bullet_Sprite);
    //std::cout<< Bullet_Sprite.getPosition().x << "    "<< Bullet_Sprite.getPosition().y << std::endl;
    return;
}

void Weapon_Presentation::update(float dt)
{
    weapon.Move_Ammo();
    weapon.SetAmmoLocation(weapon.GetAmmoPosition());
    if(weapon.GetTerminationStatus() == true)
    {
        Terminate_Ammo_Sprite = true;
        std::cout<< "DIE"<<std::endl;
    }
    return;
}

void Weapon_Presentation::Fire_Weapon(Position Player_Position )
{
    weapon.ReduceAmmo();
    weapon.SetAmmoOrigin(Player_Position);
    //std::cout << "Origin: " << Player_Position.GetX_Coordinate() << "   " << Player_Position.GetY_Coordinate() << std::endl;
    return;
}

Position Weapon_Presentation::getAmmoPosition()
{
    return weapon.GetAmmoPosition();
}

Size Weapon_Presentation::getAmmoSize()
{
    return weapon.GetAmmoSize();
}

void Weapon_Presentation::Set_Ammo_Origin(Position Player_Position)
{
    weapon_origin = Player_Position;
    return;
}

Position Weapon_Presentation::Get_Ammo_Origin()
{
    return weapon_origin;
}

Position Weapon_Presentation::GetWeaponOrigin()
{
    return weapon_position;
}

