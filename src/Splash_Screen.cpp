#include "Splash_Screen.h"

Splash_Screen::Splash_Screen():splashscreen(sf::VideoMode(1400, 1000), "Splashscreen")
{
    if (!begin.loadFromFile("In_Game_Images/Splash.png"));
    Begin.setTexture(begin);
    sf::Text text1, text2, text3, text4;
    sf::Font font;
    splashscreen.setVerticalSyncEnabled(true);

    if(!font.loadFromFile("In_Game_Images/ariblk.ttf")){ // Include In Debug File
        std::cout << "Program Halted." << std::endl;
        std::exit(-1);
    }

    text1.setFont(font);
    text2.setFont(font);
    text3.setFont(font);
    text4.setFont(font);

    text1.setString("Space Traveller By Yasteer Sewpersad");
    text1.setPosition(300.f,500.f);

    text2.setString("W, A, S & D Control Player Movement");
    text2.setPosition(300.f,600.f);

    text3.setString("Arrows Controls Player Weapons");
    text3.setPosition(300.f,700.f);

    text4.setString("Press Space Bar To Begin");
    text4.setPosition(300.f,800.f);

    text1.setCharacterSize(45);
    text2.setCharacterSize(30);
    text3.setCharacterSize(30);
    text4.setCharacterSize(30);

    while (splashscreen.isOpen()){
        sf::Event event;
        while (splashscreen.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                splashscreen.close();
            else if((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Space))
                splashscreen.close();
        }

        splashscreen.clear();
        splashscreen.draw(Begin);
        splashscreen.draw(text1);
        splashscreen.draw(text2);
        splashscreen.draw(text3);
        splashscreen.draw(text4);
        splashscreen.display();
    }
}

Splash_Screen::~Splash_Screen()
{
    //dtor
}
