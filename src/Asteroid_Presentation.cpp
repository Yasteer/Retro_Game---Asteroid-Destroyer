#include "Asteroid_Presentation.h"
#include <iostream>

Asteroid_Presentation::Asteroid_Presentation()
{
    if(!Asteroid1_Texture.loadFromFile("In_Game_Images/Asteroid_Sprite_Sheet.png"))
    { // Include In Debug File
        std::exit(-1);
    }

    Asteroid1_Sprite.setTexture(Asteroid1_Texture);
    Asteroid2_Sprite.setTexture(Asteroid1_Texture);
    Asteroid3_Sprite.setTexture(Asteroid1_Texture);
    Asteroid4_Sprite.setTexture(Asteroid1_Texture);
    Asteroid5_Sprite.setTexture(Asteroid1_Texture);

    Asteroid1_Sprite.setTextureRect(sf::IntRect(565,80,130,115));
    Asteroid2_Sprite.setTextureRect(sf::IntRect(325,315,130,115));
    Asteroid3_Sprite.setTextureRect(sf::IntRect(805,315,130,125));
    Asteroid4_Sprite.setTextureRect(sf::IntRect(60,315,130,115));
    Asteroid5_Sprite.setTextureRect(sf::IntRect(1055,315,130,128));

}

Asteroid_Presentation::~Asteroid_Presentation()
{

}

void Asteroid_Presentation::update(float dt, int Width, int Height)
{
    int Delay = 5*1000; // 5 Second Delay.

    sf::Time Current_Time = clock.getElapsedTime();
    if(Current_Time.asMilliseconds() >= Delay)
    {
        Bodies.Populate_Mine_Field(); // Function will not create any more asteroids than the recomended limit.
        clock.restart().asMilliseconds();
    }

    Bodies.Drift(Bodies.GetMine_Field());

    CheckBounds(Width, Height);

    return;
}

void Asteroid_Presentation::draw(sf::RenderWindow& window)
{
    mapSprites(Bodies.GetMine_Field());

    unsigned int Number_Of_Sprites   = Asteroid_Sprites.size();
    unsigned int Number_Of_Asteroids = Bodies.GetMine_Field().size();
    if(Number_Of_Sprites != Number_Of_Asteroids)
    {
        for(unsigned int element = 0; element < Number_Of_Asteroids; element++)
            {
                window.draw(Asteroid_Sprites.at(element));
            }
    }

    //std::cout<< Number_Of_Sprites << std::endl;
    return;
}

void Asteroid_Presentation::mapSprites(std::vector <Asteroid*> Mine_Field)
{
    unsigned int Number_Of_Sprites   = Asteroid_Sprites.size();
    unsigned int Number_Of_Asteroids = Mine_Field.size();
    for(unsigned int element=0; element < Number_Of_Asteroids; element++)
    {
        int Asteroid_X_Coordinate = Mine_Field[element]->GetAsteroid_Location().GetX_Coordinate();
        int Asteroid_Y_Coordinate = Mine_Field[element]->GetAsteroid_Location().GetY_Coordinate();

        //unsigned int Asteroid_Length = Mine_Field[element]->GetAsteroid_Size().GetLength();
        //unsigned int Asteroid_Height = Mine_Field[element]->GetAsteroid_Size().GetHeight();

        //if(1 == 1)
        //while(Number_Of_Sprites != Number_Of_Asteroids){}
        {
            if(element > 0 && element < 5)
                {
                    //Asteroid1_Sprite.setScale(Asteroid_Length/Asteroid1_Sprite.getTexture()->getSize().x,Asteroid_Height/Asteroid1_Sprite.getTexture()->getSize().y);
                    //Asteroid1_Sprite.setPosition(Asteroid_X_Coordinate,Asteroid_Y_Coordinate);
                    Asteroid_Sprites.push_back(Asteroid1_Sprite);
                }
            else if(element > 5 && element < 10)
                {
                    //Asteroid2_Sprite.setScale(Asteroid_Length/Asteroid2_Sprite.getTexture()->getSize().x,Asteroid_Height/Asteroid2_Sprite.getTexture()->getSize().y);
                    //Asteroid2_Sprite.setPosition(Asteroid_X_Coordinate,Asteroid_Y_Coordinate);
                    Asteroid_Sprites.push_back(Asteroid2_Sprite);
                }
            else if(element > 10 && element < 15)
                {
                    //Asteroid3_Sprite.setScale(Asteroid_Length/Asteroid3_Sprite.getTexture()->getSize().x,Asteroid_Height/Asteroid3_Sprite.getTexture()->getSize().y);
                    //Asteroid3_Sprite.setPosition(Asteroid_X_Coordinate,Asteroid_Y_Coordinate);
                    Asteroid_Sprites.push_back(Asteroid3_Sprite);
                }
            else if(element > 15 && element < 20)
                {
                    //Asteroid4_Sprite.setScale(Asteroid_Length/Asteroid4_Sprite.getTexture()->getSize().x,Asteroid_Height/Asteroid4_Sprite.getTexture()->getSize().y);
                    //Asteroid4_Sprite.setPosition(Asteroid_X_Coordinate,Asteroid_Y_Coordinate);
                    Asteroid_Sprites.push_back(Asteroid4_Sprite);
                }
            else
                {
                    //Asteroid5_Sprite.setScale(Asteroid_Length/Asteroid5_Sprite.getTexture()->getSize().x,Asteroid_Height/Asteroid5_Sprite.getTexture()->getSize().y);
                    //Asteroid5_Sprite.setPosition(Asteroid_X_Coordinate,Asteroid_Y_Coordinate);
                    Asteroid_Sprites.push_back(Asteroid5_Sprite);
                }
        }
        Asteroid_Sprites[element].setPosition(Asteroid_X_Coordinate,Asteroid_Y_Coordinate);
        //std::cout<< Asteroid_X_Coordinate << "    " << Asteroid_Y_Coordinate << std::endl;
    }
    return;
}

std::vector <Asteroid*> Asteroid_Presentation::getField()
{
    return Bodies.GetMine_Field();
}

void Asteroid_Presentation::deleteAsteroid(unsigned int element)
{
    Bodies.Remove_Asteroid(element);
    return;
}

void Asteroid_Presentation::CheckBounds(int Width, int Height)
{
    Bodies.CheckBounds(Width, Height);
    return;
}
