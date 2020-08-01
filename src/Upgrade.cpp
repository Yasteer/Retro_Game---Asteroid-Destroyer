#include "Upgrade.h"

Upgrade::Upgrade()
{
    SetSpecial_Effect(Shields);
}

Upgrade::~Upgrade()
{
    //dtor
}

void Upgrade::UseUpgrade()
{
    switch (GetSpecial_Effect())
    {
        case None:
            break;
        case Shields:
            break;
        case Size_Decrease:
            break;
        case Speed_Up:
            break;
        case Armada:
            break;
    }

    return;
}
