#ifndef ASTEROID_PRESENTATION_H
#define ASTEROID_PRESENTATION_H

#include <SFML/Graphics.hpp>
#include "Asteroid.h"
class Asteroid_Presentation
{
    public:
        Asteroid_Presentation();
        void Update(); // Update position and existence of individual asteroids.
        virtual ~Asteroid_Presentation();

    protected:

    private:
        sf::Texture Asteroid_Texture;
        sf::Sprite Asteroid_Sprite;

        Asteroid Bodies;
};

#endif // ASTEROID_PRESENTATION_H
