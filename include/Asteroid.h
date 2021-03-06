#ifndef ASTEROID_H
#define ASTEROID_H

#include "Position.h"
#include "Size.h"
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <iostream>
#include <memory>
class Asteroid
{
    public:
        Asteroid();
        Asteroid(Size Dimensions, Position Location);
        virtual ~Asteroid();

        Position GetAsteroid_Location() const { return Asteroid_Location; }
        void SetAsteroid_Location(Position val) { Asteroid_Location = val; }
        Size GetAsteroid_Size() { return Asteroid_Size; }
        void SetAsteroid_Size(Size val) { Asteroid_Size = val; }
        int GetLifePoints() const { return Life_Points; }
        void SetLifePoints(int val) { Life_Points = val; }

        void Populate_Mine_Field();
        void Drift(std::vector <Asteroid*> Current_Field); // Function causes asteroids to move about arbitrarily within the game.
        void Remove_Asteroid(unsigned int Asteroid_Number);

        std::vector <Asteroid*> GetMine_Field() { return Mine_Field; }
        unsigned int GetRecommendedMineFieldSize() const { return Recommended_Mine_Field_Size; }

        bool CheckBounds(int WindowWidth, int WindowHeight);
        void ReduceLifePoints(int Damage_Stat);

    protected:

    private:
        std::vector <Asteroid*> Mine_Field; // Vector of pointers to randomly generated asteroids. We need pointers because these vectors are going to get huge and copying them over isn't an option.
        Position Asteroid_Location;
        Size Asteroid_Size;
        unsigned int Recommended_Mine_Field_Size = 2;
        int Life_Points;
};

#endif // ASTEROID_H
