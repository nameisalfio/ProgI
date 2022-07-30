#include <iostream>
#include "dado.h"

using namespace std;

int main()
{
    Dado onesto(6);
    cout << "10 lanci del dado NON truccato\n";
    for(int i = 0; i < 10 ; i++)
    {
        cout << onesto.lancio() << endl;
    }
    cout << "-------------------------\n\n";


    Dado_truccato imbroglione(6, 4, dose_trucco::ALTA); //6 facce, la quattro e' truccata
    cout << "100 lanci del dado TRUCCATO; la faccia 4 e' quella truccata\n";
    int conta4=0;
    for(int i = 0; i < 100 ; i++)
    {
        cout << imbroglione.lancio() << endl;
        if (imbroglione.get_ultimoLancio() == 4) conta4++;
    }
    cout << "La faccia truccata e' uscita " << conta4 << "volte su 100 \n";
    return 0;
}
