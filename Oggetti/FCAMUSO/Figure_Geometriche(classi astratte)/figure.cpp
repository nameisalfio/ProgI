#include <string>
#include <iostream>
#include <vector>
#include <cmath>

class Figura
{
public:
    Figura() { }

    virtual double perimetro() = 0;
    virtual double area() = 0;

    virtual ~Figura() {}

private:
};

class Triangolo : public Figura
{
public:
  Triangolo() : Figura(), l1{1}, l2{1}, l3{1}
  { }

  Triangolo(int _l1, int _l2, int _l3)
    : Figura() ,  l1{_l1}, l2{_l2}, l3{_l3}
  {  }


  double perimetro() override
  {
    return l1+l2+l3;
  }

  double area() override
  {
    //formula di erone
    double sp = (l1+l2+l3) / 2; //semiperimetro
    return sqrt(sp * (sp-l1) * (sp-l2) * (sp-l3) );
  }

  ~Triangolo() {}

private:
  double l1=0, l2=0, l3=0;
};



class Cerchio : public Figura
{
public:
  Cerchio() : Cerchio(1) {}
  Cerchio(int raggio) :
    Figura(), raggio{raggio}
  { }

  double perimetro() override
  {
    return 2*3.14*raggio;
  }

  double area() override
  {
    return 3.14*raggio*raggio;
  }

private:
  double raggio=0;

};

class Character_device {
public:
virtual int open(int opt) = 0;
virtual int close(int opt) = 0;
virtual int read(char p, int n) = 0;
virtual int write(const char p, int n) = 0;
virtual int ioctl(int ...) = 0; //device I/O control
virtual ~Character_device() { } // virtual destructor
};



