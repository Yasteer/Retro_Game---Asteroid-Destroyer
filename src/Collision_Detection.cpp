#include "Collision_Detection.h"
#include <iostream>
Collision_Detection::Collision_Detection()
{

}

Collision_Detection::~Collision_Detection()
{

}

bool Collision_Detection::Collision_Detected (const Position& Object_A, const Size& Size_A, const Position& Object_B, const Size& Size_B)
{
    unsigned int Distance_Between_Objects = sqrt(pow(Object_A.GetX_Coordinate()- Object_B.GetX_Coordinate(),2)+pow(Object_A.GetY_Coordinate() - Object_B.GetY_Coordinate(),2)); // Distance Formula should always produce a positive number.
    int Combined_Size_In_Vertical_Direction   = Size_A.GetHeight() + Size_B.GetHeight();
    int Combined_Size_In_Horizontal_Direction = Size_A.GetLength() + Size_B.GetLength();

    if((Distance_Between_Objects < Combined_Size_In_Vertical_Direction) || (Distance_Between_Objects < Combined_Size_In_Horizontal_Direction))
    {
        Collision_Status = true;
    }
    else
        Collision_Status = false;
    //std::cout<< Collision_Status <<std::endl;
    return Collision_Status;
}
