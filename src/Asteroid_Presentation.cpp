#include "Asteroid_Presentation.h"

Asteroid_Presentation::Asteroid_Presentation()
{
    if(!Asteroid_Texture.loadFromFile("bin/Debug/In_Game_Images/Asteroid_Sprite_Sheet.png"))//, sf::IntRect(10, 10, 32, 32)
    { // Include In Debug File
        std::exit(-1);
    }
    Bodies.Populate_Mine_Field();
    Bodies.GetMine_Field();
}

Asteroid_Presentation::~Asteroid_Presentation()
{
    //dtor
}

void Asteroid_Presentation::Update()
{
    Asteroid_Sprite.setTexture(Asteroid_Texture);
    //for(int index = 0; index < Bodies.Position_Seed; index++)
    //{
        //
    //}
    //Asteroid_Sprite.setPosition(Asteroid_Location.GetX_Coordinate(), Asteroid_Location.GetY_Coordinate());
}
