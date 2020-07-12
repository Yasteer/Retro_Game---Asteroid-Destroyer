#include "Asteroid.h"
#include <iostream>
Asteroid::Asteroid()
{
    // Default Contructor.
}

Asteroid::Asteroid(Size Dimensions, Position Location)
{
    Asteroid_Size = Dimensions;
    Asteroid_Location = Location;
}

Asteroid::~Asteroid()
{
    unsigned int Vector_Size = Mine_Field.size();
    for(unsigned int index = 0; index < Vector_Size; index++)
    {
        delete Mine_Field[index];
        Mine_Field[index] = NULL;
    }
}

void Asteroid::Populate_Mine_Field()
{
    while(Mine_Field.size() < 25)
    {
        Position_Seed++;// Generate a new seed.
        srand(Position_Seed);// Assign a position based on this new seed.

        Asteroid_Size.SetHeight(rand() % 100 + 10); // Random number between 10 and 100.
        Asteroid_Size.SetLength(rand() % 100 + 10); // Reference: http://www.cplusplus.com/reference/cstdlib/rand/

        Asteroid_Location.SetX_Coordinate(rand() % 1920 + 0);
        Asteroid_Location.SetY_Coordinate(rand() % 700 + 0);

        Asteroid* New_Asteroid = new Asteroid(Asteroid_Size, Asteroid_Location); // Dynamic allocation --> Move towards Smart Pointers in a future build
        Mine_Field.push_back(New_Asteroid);

    }

}

void Asteroid::Drift(std::vector<Asteroid*> Current_Field, int seed)
{
    srand(seed);
    int Field_Size = Current_Field.size();
    for(int element = 0; element < Field_Size; element++)
    {
        int X_Drift = Current_Field[element]->GetAsteroid_Location().GetX_Coordinate() + (rand() % 1 - 1);
        int Y_Drift = Current_Field[element]->GetAsteroid_Location().GetY_Coordinate() + (rand() % 1 - 1);

        Asteroid_Location.SetX_Coordinate(X_Drift);
        Asteroid_Location.SetY_Coordinate(Y_Drift);

        Current_Field[element]->SetAsteroid_Location(Asteroid_Location);
    }
    return;
}
