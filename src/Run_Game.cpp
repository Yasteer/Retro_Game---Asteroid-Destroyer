#include "Run_Game.h"

Run_Game::Run_Game():Game_Screen(sf::VideoMode(1920, 1080), "Game_Screen")
{

}

Run_Game::~Run_Game()
{

}

void Run_Game::Run()
{
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
                //default:

                }
            }
        }

        sf::Time time = clock.getElapsedTime();
        player.update(time.asMilliseconds());
        weapon.update(time.asMilliseconds());
        clock.restart().asMilliseconds();

        Game_Screen.clear();
        player.draw(Game_Screen);
        weapon.draw(Game_Screen);
        Game_Screen.display();
    }
}
