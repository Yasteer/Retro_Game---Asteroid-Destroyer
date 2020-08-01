#include "Asteroid.h"

Asteroid::Asteroid()
{

}

Asteroid::Asteroid(Size Dimensions, Position Location)
{
    Asteroid_Size = Dimensions;
    Asteroid_Location = Location;
}

Asteroid::~Asteroid()
{
    unsigned int Vector_Size = Mine_Field.size();
    for(unsigned int index = 0; index <= Vector_Size; index++)
    {
        delete Mine_Field[index];
        Mine_Field[index] = NULL;
    }
    Mine_Field.clear();
}

void Asteroid::Populate_Mine_Field()
{
    while(Mine_Field.size() < Recommended_Mine_Field_Size)
    {
        srand(time(0));// Assign a position based on this new seed.

        SetLifePoints( 20 + (rand() % 100));

        Asteroid_Size.SetHeight(10 + (rand() % 40)); // Random size between 1 and 40.
        Asteroid_Size.SetLength(10 + (rand() % 40)); // Reference: http://www.cplusplus.com/reference/cstdlib/rand/

        Asteroid_Location.SetX_Coordinate(50 + (rand() % 1920));
        Asteroid_Location.SetY_Coordinate(50 + (rand() % 700 ));

        // Ensure no unit is created out of bounds.
        if(this->GetAsteroid_Location().GetX_Coordinate() > 2000 || this->GetAsteroid_Location().GetY_Coordinate() > 1500)
        {
            Asteroid_Location.SetX_Coordinate(500);
            Asteroid_Location.SetY_Coordinate(500);
        }

        Asteroid* New_Asteroid = new Asteroid(Asteroid_Size, Asteroid_Location); // Dynamic allocation --> Move towards Smart Pointers in a future build
        Mine_Field.push_back(New_Asteroid);
    }
    return;
}

void Asteroid::Drift(std::vector<Asteroid*> Current_Field)
{
    int Toggle_Value = 1;
    srand(time(0)); // The seed paprameter needs to be different with each call to generate a new set of "unique" numbers.
    int Field_Size = Current_Field.size();
    for(int element = 0; element < Field_Size; element++)
    {
        int X_Drift = Current_Field[element]->GetAsteroid_Location().GetX_Coordinate() + Toggle_Value*(rand() % 2);
        int Y_Drift = Current_Field[element]->GetAsteroid_Location().GetY_Coordinate() + Toggle_Value*(rand() % 2);

        Asteroid_Location.SetX_Coordinate(X_Drift);
        Asteroid_Location.SetY_Coordinate(Y_Drift);

        Current_Field[element]->SetAsteroid_Location(Asteroid_Location);

        Toggle_Value *= -1;
    }
    return;
}

void Asteroid::Remove_Asteroid(unsigned int Asteroid_Number)
{
    Mine_Field.erase(Mine_Field.begin() + (Asteroid_Number));
    return;
}

bool Asteroid::CheckBounds(int WindowWidth, int WindowHeight)
{
    int Current_Field_Size = Mine_Field.size();
    for(int element = 0; element < Current_Field_Size; element++)
    {
        if((Mine_Field[element]->GetAsteroid_Location().GetX_Coordinate() < 0) || (Mine_Field[element]->GetAsteroid_Location().GetX_Coordinate() > WindowWidth))
        {
            Remove_Asteroid(element);
            return true;
        }
        if((Mine_Field[element]->GetAsteroid_Location().GetY_Coordinate() < 0) || (Mine_Field[element]->GetAsteroid_Location().GetY_Coordinate() > WindowHeight))
        {
            Remove_Asteroid(element);
            return true;
        }
    }
    return false;
}
