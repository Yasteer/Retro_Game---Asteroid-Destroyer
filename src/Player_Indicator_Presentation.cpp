#include "Player_Indicator_Presentation.h"

Player_Indicator_Presentation::Player_Indicator_Presentation()
{
    if(!Health_Texture.loadFromFile("In_Game_Images/Heart_Sprite.png"))
    { // Include In Debug File
        std::exit(-1);
    }
    Health_Sprite.setTexture(Health_Texture);
    Health_Sprite.setScale(0.5,0.5);

    if(!Mana_Texture.loadFromFile("In_Game_Images/Mana_Sprite_Sheet.png"))
    { // Include In Debug File
        std::exit(-1);
    }
    Mana_Sprite1.setTexture(Mana_Texture);
    Mana_Sprite2.setTexture(Mana_Texture);
    Mana_Sprite3.setTexture(Mana_Texture);
    Mana_Sprite4.setTexture(Mana_Texture);
    Mana_Sprite5.setTexture(Mana_Texture);
    Mana_Sprite6.setTexture(Mana_Texture);

    Mana_Sprite1.setTextureRect(sf::IntRect(140,80,100,70));
    Mana_Sprite2.setTextureRect(sf::IntRect(140,265,220,70));
    Mana_Sprite3.setTextureRect(sf::IntRect(140,448,335,70));
    Mana_Sprite4.setTextureRect(sf::IntRect(140,632,410,70));
    Mana_Sprite5.setTextureRect(sf::IntRect(140,817,483,70));
    Mana_Sprite6.setTextureRect(sf::IntRect(140,1002,558,70));

    Mana_Sprite1.setScale(0.25,0.25);
    Mana_Sprite2.setScale(0.25,0.25);
    Mana_Sprite3.setScale(0.25,0.25);
    Mana_Sprite4.setScale(0.25,0.25);
    Mana_Sprite5.setScale(0.25,0.25);
    Mana_Sprite6.setScale(0.25,0.25);

    Mana_Sprite1.setPosition(0,150);
    Mana_Sprite2.setPosition(0,150);
    Mana_Sprite3.setPosition(0,150);
    Mana_Sprite4.setPosition(0,150);
    Mana_Sprite5.setPosition(0,150);
    Mana_Sprite6.setPosition(0,150);
}

Player_Indicator_Presentation::~Player_Indicator_Presentation()
{
    //dtor
}

void Player_Indicator_Presentation::draw(sf::RenderWindow& window)
{
    if(Indicators.GetMana() < 100)
    {
        window.draw(Mana_Sprite1);
    }
    if(Indicators.GetMana() < 200)
    {
        window.draw(Mana_Sprite2);
    }
    if(Indicators.GetMana() < 300)
    {
        window.draw(Mana_Sprite3);
    }
    if(Indicators.GetMana() < 400)
    {
        window.draw(Mana_Sprite4);
    }
    if(Indicators.GetMana() < 500)
    {
        window.draw(Mana_Sprite5);
    }
    else
        window.draw(Mana_Sprite6);

    unsigned int Health_Sprites_Size = Health_Sprites.size();
    for(unsigned int Live_Number = 0; Live_Number < Health_Sprites_Size; Live_Number++)
    {
        window.draw(Health_Sprites.at(Live_Number));
    }

    return;
}

void Player_Indicator_Presentation::update(float dt)
{
    unsigned int Number_Of_Sprites = Health_Sprites.size();
    unsigned int Number_Of_Lives   = Indicators.GetLives().size();

    if(Number_Of_Sprites != Number_Of_Lives) // Perform update only if neccessary.
    {
        for(unsigned int element = 0; element < Number_Of_Lives; element++)
            {
                int Current_Position_X = Health_Sprite.getPosition().x;
                Health_Sprite.setPosition(Current_Position_X + 20, 0);
                Health_Sprites.push_back(Health_Sprite);
            }
    }
    return;
}

void Player_Indicator_Presentation::Reduce_Life()
{
    Indicators.DecreaseLives();
    return;
}

int Player_Indicator_Presentation::Get_Lives()
{
    int Number_Of_Lives = Indicators.GetLives().size();
    return Number_Of_Lives;
}
