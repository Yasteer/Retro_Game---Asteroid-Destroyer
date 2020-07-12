#ifndef UPGRADE_H
#define UPGRADE_H

#include <string>
class Upgrade
{
    public:
        Upgrade();
        virtual ~Upgrade();

        enum Special_Effect {Shields, Size_Decrease, Speed_Up};

        Special_Effect GetSpecial_Effect() { return Boost; }
        void SetSpecial_Effect(Special_Effect val) { Boost = val; }

    protected:

    private:
        Special_Effect Boost;
};

#endif // UPGRADE_H
