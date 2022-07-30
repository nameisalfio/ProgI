#include <iostream>
#include "cani.h"

using namespace std;

int main()
{
    Cani il_mio_boby{"boby", 2, 0};
    cout << "boby: " << il_mio_boby.verso() << endl;

    Cani il_bullo{"bullyo", 31, 5};
    cout << "vicino: " << il_bullo.verso() << endl;

    if (il_bullo > il_mio_boby)
    {
      cout << "Il mio tesoruccio le prende!! MA... \n";
    }

    Cani_selvaggi amico_di_boby{"la muerte che cammina", 2, 18, 176};
    cout << "amico di boby: " << amico_di_boby.verso() << endl;

    if (amico_di_boby > il_bullo)
    {
      cout << "Il mio tesoruccio e' salvo :) \n";
    }

    Cani_selvaggi cs2{"",2, 18,200};
    if (cs2 > amico_di_boby) cout << "new champion!\n";

    return 0;
}
