#include <iostream>

using namespace std;

class Persona
{
public:
  Persona() : Persona{"", 0} {}

  Persona(string nome, int eta) : nome{nome}, eta{eta}
  {cout << "costruttore Persona\n";}

  ~Persona() {cout << "distruttore Persona\n";}


  string get_nome() {return nome;}
  int get_eta() {return eta;}


private:
  string nome=""; int eta=0;

};

class Impiegato
{
public:
  Impiegato() : Impiegato{"", 0} {}

  Impiegato(string datore_lavoro, int stipendio) :
      datore_lavoro{datore_lavoro}, stipendio{stipendio}
  {cout << "costruttore Impiegato\n";}

  ~Impiegato() {cout << "costruttore Impiegato\n";}

  string get_datore_lavoro() {return datore_lavoro;}
  int get_stipendio() {return stipendio;}


private:

  string datore_lavoro="";
  int stipendio=0;

};

class Insegnante : public Persona, public Impiegato
{
public:
  Insegnante() : Insegnante("",0,"",0,"") {}
  Insegnante(string nome, int eta,
             string datore_lavoro, int stipendio,
             string ordine_scuola) :
             Persona(nome, eta), Impiegato(datore_lavoro, stipendio),
             ordine_scuola{ordine_scuola}
  {
    cout << "costruttore Insegnante\n";
  }

  ~Insegnante()
  {
    cout << "distruttore Insegnante\n";
  }

private:
  string ordine_scuola="superiori";
};

int main()
{
    Insegnante fcamuso("FCamuso", 21, "MegaPresideGalattica", 9000, "");
    cout << "Eta': " << fcamuso.get_eta() << endl;
    cout << "Stipendio: " << fcamuso.get_stipendio() << endl;
    cout << "Il boss: " << fcamuso.get_datore_lavoro() << endl;


    return 0;
}
