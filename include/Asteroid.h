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

        Position GetAsteroid_Location() { return Asteroid_Location; }
        void SetAsteroid_Location(Position val) { Asteroid_Location = val; }
        Size GetAsteroid_Size() { return Asteroid_Size; }
        void SetAsteroid_Size(Size val) { Asteroid_Size = val; }

        void Populate_Mine_Field();
        void Remove_Asteroid();

        std::vector <Asteroid*> GetMine_Field() {
           unsigned int s = Mine_Field.size();
            for(unsigned int i = 0; i < s; i++)
            {
                std::cout << Mine_Field[i]->GetAsteroid_Location().GetX_Coordinate() << std::endl;
            }

            return Mine_Field; }

    protected:

    private:
        std::vector <Asteroid*> Mine_Field; // Vector of pointers to randomly generated asteroids. We need pointers because these vectors are going to get huge and copying them over isn't an option.
        Position Asteroid_Location;
        Size Asteroid_Size;
        int Position_Seed;
};

#endif // ASTEROID_H
