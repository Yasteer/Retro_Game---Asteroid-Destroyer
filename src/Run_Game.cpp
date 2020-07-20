#include "Run_Game.h"
#include <iostream>
Run_Game::Run_Game():Game_Screen(sf::VideoMode(1500, 900), "Game_Screen")
{

}

Run_Game::~Run_Game()
{

}

void Run_Game::Run()
{
    Game_Screen.setFramerateLimit(60); // Industry Standard.
    sf::Clock clock; // Variable used to calculate loop time (for frame rate).
    while (Game_Screen.isOpen())
    {
        sf::Event event;
        while (Game_Screen.pollEvent(event))
        {
            if(event.type == sf::Event::KeyPressed)
            {
                switch(event.key.code)
                {
                case sf::Keyboard::Escape:
                    Game_Screen.close();
                    break;
                case sf::Keyboard::W:
                    player.move_player('W');
                    break;
                case sf::Keyboard::A:
                    player.move_player('A');
                    break;
                case sf::Keyboard::S:
                    player.move_player('S');
                    break;
                case sf::Keyboard::D:
                    player.move_player('D');
                    break;
                case sf::Keyboard::Up:
                    weapon.Fire_Weapon(player.getPlayerPosition());
                    break;
                default:
                    break;
                }
            }
        }

        // Check For Any Collisions:
        unsigned int Asteroid_Field_Size = asteroids.getField().size();
        for(unsigned int element=0; element<Asteroid_Field_Size; element++)
        {
            // Player & Asteroid:
            if(test.Collision_Detected(player.getPlayerPosition(),player.getPlayerSize(),asteroids.getField().at(element)->GetAsteroid_Location(),asteroids.getField().at(element)->GetAsteroid_Size()) == true)
            {
                Game_Screen.close();
                std::cout<< "You dieded";
            }
            // Ammo & Asteroid:
            if(test.Collision_Detected(weapon.getAmmoPosition(),weapon.getAmmoSize(),asteroids.getField().at(element)->GetAsteroid_Location(),asteroids.getField().at(element)->GetAsteroid_Size()) == true)
            {
                //asteroids.deleteAsteroid(element);
                std::cout << "Asteroid Hit By Bullet" <<std::endl;
                //std::cout<< weapon.getAmmoPosition().GetX_Coordinate() << " " << weapon.getAmmoPosition().GetY_Coordinate() <<std::endl;
            }

        }

        sf::Time time = clock.getElapsedTime();
        player.update(time.asMilliseconds());
        weapon.update(time.asMilliseconds());
        asteroids.update(time.asMilliseconds());
        clock.restart().asMilliseconds();

        Game_Screen.clear();
        player.draw(Game_Screen);
        weapon.draw(Game_Screen);
        asteroids.draw(Game_Screen);
        Game_Screen.display();
    }
}
