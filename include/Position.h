#ifndef POSITION_H
#define POSITION_H

class Position
{
    public:
        Position();
        Position(unsigned int X, unsigned int Y);
        virtual ~Position();

        unsigned int GetX_Coordinate() const { return X_Coordinate; }
        void SetX_Coordinate(unsigned int val) { X_Coordinate = val; }
        unsigned int GetY_Coordinate() const { return Y_Coordinate; }
        void SetY_Coordinate(unsigned int val) { Y_Coordinate = val; }

    protected:

    private:
        unsigned int X_Coordinate;
        unsigned int Y_Coordinate;
};

#endif // POSITION_H
