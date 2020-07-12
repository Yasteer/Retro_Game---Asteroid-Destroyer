#ifndef SPLASH_SCREEN_H
#define SPLASH_SCREEN_H

#include "Asteroid.h"

#include <SFML/Graphics.hpp>
#include <iostream>
class Splash_Screen
{
    public:
        Splash_Screen();
        virtual ~Splash_Screen();
    protected:

    private:
        sf::RenderWindow splashscreen;
        sf::Texture begin;
        sf::Sprite Begin;

};

#endif // SPLASH_SCREEN_H
