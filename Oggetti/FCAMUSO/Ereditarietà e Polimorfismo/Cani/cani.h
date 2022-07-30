#ifndef CANI_H_INCLUDED
#define CANI_H_INCLUDED
#include <string>

class Cani
{
public:
  Cani();

  Cani(std::string nome, int peso, int pericolosita);

  std::string verso();

  double valuta_rischio();

  bool operator>(Cani c);

private:
  std::string nome="";
  std::string razza="";
  int peso=0;
  int pericolosita=0;
};


class Cani_selvaggi : public Cani
{
public:
  Cani_selvaggi();

  Cani_selvaggi(std::string nome, int peso,
                int pericolosita, int num_segnalazioni);

  std::string verso(); //ridefinito ...

  double valuta_rischio(); //ridefinito

  bool operator>(Cani_selvaggi c); //ridefinito
  bool operator>(Cani c);

private:
  int num_segnalazioni=0;

};


#endif // CANI_H_INCLUDED
