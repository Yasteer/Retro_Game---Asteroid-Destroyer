#include "Weapon_Presentation.h"
#include <iostream>

Weapon_Presentation::Weapon_Presentation()
{
    if(!Ammo_Texture.loadFromFile("In_Game_Images/Ammo_Sprite_Sheet.png")) // Public domain sheet taken from http://m484games.ucoz.com/
    {
        // handle error.
    }

    Bullet_Sprite.setTexture(Ammo_Texture);
    Bullet_Sprite.setTextureRect(sf::IntRect(275,20,25,20)); // First pair --> Top Left of Rect. Second Pair --> Size of Rect.
    Bullet_Sprite.setRotation(270);
    Bullet_EndLife_Sprite.setTextureRect(sf::IntRect(137,27, 15,15));

    Rocket_Sprite.setTexture(Ammo_Texture);
    Rocket_Sprite.setTextureRect(sf::IntRect(262,195,10,15));

    Laser_Sprite.setTexture(Ammo_Texture);
    Laser_Sprite.setTextureRect(sf::IntRect(489,85,15,50));

    Terminate_Ammo_Sprite = false;
}

Weapon_Presentation::~Weapon_Presentation()
{

}

void Weapon_Presentation::draw(sf::RenderWindow& window)
{
    if(weapon.GetWeapon_Type() == weapon.Gun)
    {
        if(Terminate_Ammo_Sprite == true)
        {
            Bullet_Sprite.setPosition(weapon.GetAmmoPosition().GetX_Coordinate() , weapon.GetAmmoPosition().GetY_Coordinate());
            window.draw(Bullet_EndLife_Sprite);
        }
        Bullet_Sprite.setPosition(weapon.GetAmmoPosition().GetX_Coordinate() , weapon.GetAmmoPosition().GetY_Coordinate());
        window.draw(Bullet_Sprite);
    }
    else if(weapon.GetWeapon_Type() == weapon.RPG)
    {
        if(Terminate_Ammo_Sprite == true)
        {
            Rocket_Sprite.setPosition(weapon.GetAmmoPosition().GetX_Coordinate() , weapon.GetAmmoPosition().GetY_Coordinate());
            window.draw(Rocket_EndLife_Sprite);
        }
        Rocket_Sprite.setPosition(weapon.GetAmmoPosition().GetX_Coordinate() , weapon.GetAmmoPosition().GetY_Coordinate());
        window.draw(Rocket_Sprite);
    }
    else
        Laser_Sprite.setPosition(weapon.GetAmmoPosition().GetX_Coordinate() , weapon.GetAmmoPosition().GetY_Coordinate());
        window.draw(Laser_Sprite);
    return;
}

void Weapon_Presentation::update(float dt)
{
    weapon.Move_Ammo();
    weapon.SetAmmoLocation(weapon.GetAmmoPosition());
    if(weapon.GetTerminationStatus() == true)
    {
        Terminate_Ammo_Sprite = true;
    }
    return;
}

void Weapon_Presentation::Fire_Weapon(Position Player_Position )
{
    weapon.ReduceAmmo();
    weapon.SetAmmoOrigin(Player_Position);
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

void Weapon_Presentation::setWeapon(int Hit_Count)
{
    if(Hit_Count >= 2 && Hit_Count < 15)
    {
        weapon.SetWeapon_Type(weapon.RPG);
    }
    else if(Hit_Count > 15)
    {
        weapon.SetWeapon_Type(weapon.Laser);
    }
    return;
}
