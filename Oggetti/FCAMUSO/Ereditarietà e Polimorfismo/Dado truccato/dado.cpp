#include <cstdlib>
#include <ctime>
#include <iostream> //per debug
#include "dado.h"

//Dado -------------------------------------------------------------
Dado::Dado(int _numFacce)
  : numFacce{_numFacce}, ultimoLancio{-1}
{
    srand(time(0));
}

Dado::Dado() : Dado(6) {}  //delega

int Dado::get_ultimoLancio()
{ return ultimoLancio; }

int Dado::lancio()
{
    ultimoLancio = rand()%numFacce + 1;
    return ultimoLancio;
}
//fine Dado ---------------------------------------------------------

//Dado_truccato -----------------------------------------------------

Dado_truccato::Dado_truccato() : Dado_truccato(6, 0, dose_trucco::BASSA)
{}

Dado_truccato::Dado_truccato(int numFacce, int faccia_truccata, dose_trucco quanto_trucco)
    : Dado(numFacce), faccia_truccata{faccia_truccata} ,quanto_trucco{quanto_trucco}
{}

int Dado_truccato::lancio()
{

  int n = Dado::lancio() + quanto_trucco;

  if (n>numFacce)
    { ultimoLancio=faccia_truccata; }
  else
    { ultimoLancio=n; }

  return ultimoLancio;
}

//fine Dado_truccato--------------------------------------------------
