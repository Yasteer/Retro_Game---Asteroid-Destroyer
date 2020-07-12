#include "Position.h"

Position::Position()
{
    X_Coordinate = 0; // Defualt Position.
    Y_Coordinate = 0;
}

Position::Position(unsigned int X, unsigned int Y)
{
    X_Coordinate = X;
    Y_Coordinate = Y;
}

Position::~Position()
{
    //dtor
}
