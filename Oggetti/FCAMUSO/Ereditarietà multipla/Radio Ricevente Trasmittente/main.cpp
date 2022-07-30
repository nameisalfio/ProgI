#include <iostream>
#include <fstream>

using namespace std;

//questa classe definisce una interfaccia per fornire un servizio
//di logging durante l'esecuzione
class  Debug {

public:
  Debug() : Debug("default_log.txt") {}
  Debug(const string& nome_file) : nome_file{nome_file}
  { }
  virtual ~Debug() {}

  virtual string get_file() {return nome_file;}
  virtual void read() = 0;
  virtual void write() = 0;


 private:
  string nome_file="";
};

class Trasmittente : public virtual Debug {
public:
  Trasmittente(string nome_file) : Debug(nome_file)
  {}
  ~Trasmittente() override {}

  void read() override {}

  void write() override
  {cout << "-- Registrato da Trasmittente\n";
   cout << "-- Usando il file " << Debug::get_file() <<endl;}

  string get_file() override {return Debug::get_file();}


};

class Ricevente : public virtual Debug {
public:
  Ricevente(string nome_file) : Debug(nome_file){}
  ~Ricevente() override {}

  void read() override {}
  void write() override
  {cout << "-- Registrato da Ricevente\n";
   cout << "-- Usando il file " << Debug::get_file() <<endl;
  }


  string get_file() override {return Debug::get_file();}


};

class Radio : public Trasmittente, public Ricevente {
public:

  Radio(string nome_file) : Debug(nome_file),
      Trasmittente("File_del_trasmittente.txt"), Ricevente("File del ricevente.txt")
  { }

  void read() override {}

  void write() override
  { Trasmittente::write();
    Ricevente::write();
    //cout << "Registrato da Radio\n";
  }


  string get_file() override {return Ricevente::get_file();}

};

int main()
{
    Radio r{"File Unico di Log.txt"};
    r.write();

    return 0;
}
