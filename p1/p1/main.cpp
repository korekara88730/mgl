
#include "Winform.h"
#include <stdlib.h>
#include <time.h>

int main()
{
    srand((unsigned)time(NULL));
    Winform winform;
    if(!winform.setup(400,300,"mgl-1"))
    {
        return -1;
    }
    winform.mainLoop();
    winform.cleanup();
    return 0;
}
