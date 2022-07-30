#include "Contatore.h"

Contatore::Contatore()
{
	valore=0;
}

void Contatore::incrementa()
{
	cout<<valore++<<endl;
}

void Contatore::decrementa()
{
	cout<<valore--<<endl;
}