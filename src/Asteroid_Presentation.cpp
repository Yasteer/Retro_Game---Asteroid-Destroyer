#include "Asteroid_Presentation.h"

Asteroid_Presentation::Asteroid_Presentation()
{
    if(!Asteroid1_Texture.loadFromFile("In_Game_Images/Asteroid_Sprite_Sheet.png"))
    { // Include In Debug File
        std::exit(-1);
    }
    Bodies.Populate_Mine_Field();
    Bodies.GetMine_Field();

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

    Asteroid5_Sprite.setPosition(600,600);

}

Asteroid_Presentation::~Asteroid_Presentation()
{

}

void Asteroid_Presentation::update(float dt)
{
    // Use the Clock to seed the random number generator. Probably looks more random than using loop time.


    Bodies.Drift(Bodies.GetMine_Field(), (int) dt); // Cast the Run Game loop time to an int and use thhis as the seed for the Drift function.
    return;
}

void Asteroid_Presentation::draw(sf::RenderWindow& window)
{
    mapSprites(Bodies.GetMine_Field());
    unsigned int Number_Of_Sprites = Asteroid_Sprites.size();
    for(unsigned int element = 0; element < Number_Of_Sprites; element++)
    {
        window.draw(Asteroid_Sprites[element]);
    }
    return;
}

void Asteroid_Presentation::mapSprites(std::vector <Asteroid*> Mine_Field)
{
    int Number_Of_Asteroids = Mine_Field.size();
    for(int element=0; element < Number_Of_Asteroids; element++)
    {
        int Asteroid_X_Coordinate = Mine_Field[element]->GetAsteroid_Location().GetX_Coordinate();
        int Asteroid_Y_Coordinate = Mine_Field[element]->GetAsteroid_Location().GetY_Coordinate();

        // Assign Sprites --> Would have liked to use a Switch statement but C++ requires that "case labels be constants" so no expressions for logic can be used.
        if(element > 0 && element < 5)
        {
            Asteroid_Sprites.push_back(Asteroid1_Sprite);
        }
        else if(element > 5 && element < 10)
        {
            Asteroid_Sprites.push_back(Asteroid2_Sprite);
        }
        else if(element > 10 && element < 15)
        {
            Asteroid_Sprites.push_back(Asteroid3_Sprite);
        }
        else if(element > 15 && element < 20)
        {
            Asteroid_Sprites.push_back(Asteroid4_Sprite);
        }
        else
            Asteroid_Sprites.push_back(Asteroid5_Sprite);


        Asteroid_Sprites[element].setPosition(Asteroid_X_Coordinate,Asteroid_Y_Coordinate);
    }
    return;
}
