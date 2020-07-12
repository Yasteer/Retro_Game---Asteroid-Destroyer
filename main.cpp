// Will link to lib files dynamically. This will save space on the .exe file and prevent the user from having to recompile
// in the event that the libraries are updated from the 3rd party.

// Will use composition as opposed to inheritence. Inheritence is designed to reuse code but composition is better suited to
// acheiving polymorhism.

#include "Splash_Screen.h"
#include "Run_Game.h"

int main()
{
    Splash_Screen Begin;

    Run_Game New_Game;
    New_Game.Run();

    return 0;
}
