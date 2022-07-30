#include "cani.h"

//Cani ----------------------------------------------------------
Cani::Cani() : Cani("randagio",0, 1) {}

Cani::Cani(std::string nome, int peso, int pericolosita)
    : nome{nome}, peso{peso}, pericolosita{pericolosita},
      razza{"sconosciuta"}
      {}

std::string Cani::verso()
{
  if (pericolosita>1)
    return "Bau! Bau!\n";
  else
    return "Bau...\n";
}

double Cani::valuta_rischio() {return peso/2+pericolosita;}

bool Cani::operator>(Cani c)
{return valuta_rischio() > c.valuta_rischio();}

//fine Cani ---------------------------------------------------------





//Cani_selvaggi ------------------------------------------------------
Cani_selvaggi::Cani_selvaggi() : Cani_selvaggi("randagio", 0, 2, 1)
{}

Cani_selvaggi::Cani_selvaggi(std::string nome, int peso,
                int pericolosita, int num_segnalazioni)
                : Cani(nome,peso, pericolosita),
                  num_segnalazioni{num_segnalazioni}
{}

std::string Cani_selvaggi::verso() //ridefinito ...
{
  std::string il_verso="";
  for(int i=0; i<num_segnalazioni; i++)
  {
    il_verso +="Groarr! ";
    //interessante alternativa: il_verso += Cani::Verso();
  }
  return il_verso;
}

double Cani_selvaggi::valuta_rischio() //ridefinito
{
  return Cani::valuta_rischio() + 10*num_segnalazioni;
}

bool Cani_selvaggi::operator>(Cani_selvaggi c) //ridefinito
{
  return valuta_rischio() > c.valuta_rischio();
}

bool Cani_selvaggi::operator>(Cani c)
{
  return valuta_rischio() > c.valuta_rischio();
}


//fine Cani_selvaggi ------------------------------------------------------
