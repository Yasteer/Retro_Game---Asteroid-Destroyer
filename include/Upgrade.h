#ifndef UPGRADE_H
#define UPGRADE_H

#include <string>
class Upgrade
{
    public:
        Upgrade();
        virtual ~Upgrade();

        enum Special_Effect {Shields, Size_Decrease, Speed_Up, Armada}; // Under the hood, C++ converts enums to int types.

        Special_Effect GetSpecial_Effect() const { return Boost; }
        void SetSpecial_Effect(Special_Effect val) { Boost = val; }

    protected:

    private:
        Special_Effect Boost;
};

#endif // UPGRADE_H
