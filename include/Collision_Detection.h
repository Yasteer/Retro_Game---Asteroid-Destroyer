#ifndef COLLISION_DETECTION_H
#define COLLISION_DETECTION_H

#include "math.h"
#include "Size.h"
#include "Position.h"
class Collision_Detection
{
    public:
        Collision_Detection();
        virtual ~Collision_Detection();

        bool Collision_Detected (const Position& Object_A, const Size& Size_A, const Position& Object_B, const Size& Size_B); // Pass by const reference to prevent copies and un-intended property changes.

    protected:

    private:
        bool Collision_Status;
};

#endif // COLLISION_DETECTION_H
