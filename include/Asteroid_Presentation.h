#ifndef ASTEROID_PRESENTATION_H
#define ASTEROID_PRESENTATION_H

#include <SFML/Graphics.hpp>
#include "Asteroid.h"
#include <vector>
#include <ctime>
class Asteroid_Presentation
{
    public:
        Asteroid_Presentation();
        void Update(); // Update position and existence of individual asteroids.
        virtual ~Asteroid_Presentation();

        void draw(sf::RenderWindow& window);
        void update(float dt, int Width, int Height);
        void deleteAsteroid(unsigned int element);

        void mapSprites(std::vector <Asteroid*> Mine_Field);
        std::vector <Asteroid*> getField();

        void CheckBounds(int Width, int Height);

    protected:

    private:
        sf::Texture Asteroid1_Texture;
        sf::Sprite Asteroid1_Sprite;

        sf::Texture Asteroid2_Texture;
        sf::Sprite Asteroid2_Sprite;

        sf::Texture Asteroid3_Texture;
        sf::Sprite Asteroid3_Sprite;

        sf::Texture Asteroid4_Texture;
        sf::Sprite Asteroid4_Sprite;

        sf::Texture Asteroid5_Texture;
        sf::Sprite Asteroid5_Sprite;

        Asteroid Bodies;
        std::vector<sf::Sprite> Asteroid_Sprites;
        std::vector <Asteroid*> Asteroids;

        sf::Clock clock; // Variable used to calculate loop time
};

#endif // ASTEROID_PRESENTATION_H
