#include <string>
#include <iostream>
#include <vector>

class Figura
{
public:
    Figura(std::string colore_tratto,
         std::string colore_fill="bianco",
         int spessore_tratto=1,
         bool filled=false) :

         colore_tratto{colore_tratto},
         colore_fill{colore_fill},
         spessore_tratto{spessore_tratto},
         filled{filled}

  { }

  Figura() : Figura("nero")
  {}

  virtual ~Figura() {std::cout << "Distruttore classe madre NO DELETE\n";}

  virtual double perimetro() {std::cout<< "virtual...\n"; return 10;}

private:
  std::string colore_tratto="";
  std::string colore_fill="";
  bool filled = false;
  int spessore_tratto=0;
};

class Triangolo : public Figura
{
public:
  Triangolo() : Figura(), l1{1}, l2{1}, l3{1}
  { }

  Triangolo(int _l1, int _l2, int _l3)
    : Figura("rosso", "", 1, false),  l1{_l1}, l2{_l2}, l3{_l3}
  {
    v = new double[1000000];
  }

  ~Triangolo() {std::cout << "Distruttore classe figlia DELETE\n"; delete[]v;}

  //private:  private non bloccherebbe il late binding
  double perimetro() override
  {
    std::cout << "Triangolo\n";

    Figura::perimetro();
    return l1+l2+l3;
  }

private:
  int l1=0, l2=0, l3=0;
  double *v;
};



class Rettangolo : public Figura
{
public:
  Rettangolo() : Rettangolo(1,1) {}
  Rettangolo(int lato1, int lato2) :
    Figura("nero"), lato1{lato1}, lato2{lato2}
  { }

  double perimetro() override //final -> quadrato non potrebbe a sua volta fare override
  {
    std::cout << "Rettangolo\n";
    return (lato1+lato2)*2;
  }

protected:
  int lato1=0, lato2=0;

};

class Rettangolo_aureo : public Rettangolo
{
  using Rettangolo::Rettangolo;
};

class Quadrato : public Rettangolo
{

public:
  Quadrato() : Rettangolo() {}
  Quadrato(int lato) : Rettangolo(lato, lato)
  { }

  //nella classe figlia si puo' ridefinire un metodo
  //gia' presente nella classe madre

  double perimetro() override
  {
    std::cout << "Quadrato\n";
    return lato1 * 4; //migliori prestazioni! (lato1+lato2)*2;
  }

private:

};

class Cerchio : public Figura
{
public:
  Cerchio() : Cerchio(1) {}
  Cerchio(int raggio) :
    Figura("nero"), raggio{raggio}
  { }

  double perimetro() override
  {
    std::cout << "Cerchio\n";
    return 2*3.14*raggio;
  }

protected:
  int raggio=0;

};





