#ifndef DADO_H_INCLUDED
#define DADO_H_INCLUDED

#include <ctime>
#include <cstdlib>

class Dado{
  public:
    Dado (int _numFacce);
    Dado ();

    int get_ultimoLancio();
    int lancio();

  protected: //per concedere accesso (solo) alla classe figlia Dado_truccato
    int ultimoLancio;
    int numFacce;

};

enum dose_trucco {BASSA=1, MEDIA, ALTA};

class Dado_truccato : public Dado
//attenzione: se non si mette public il tipo di derivazione di default e' private
//al che i metodi che sono pubblici nella classe base diventano privati
//nella figlia e non richiamabili su oggetti di classe figlia
{
  //eredita TUTTO lo stato interno da Dado
  // ... MA ... puo' usare solo le parti pubbliche o protected

  public:
    Dado_truccato();

    Dado_truccato(int numFacce, int faccia_truccata, dose_trucco quanto_trucco);
    int lancio(); //ridefiniamo la tecnica di lancio

  private:
    int faccia_truccata = 0;
    dose_trucco quanto_trucco = dose_trucco::BASSA;
};


#endif // DADO_H_INCLUDED
