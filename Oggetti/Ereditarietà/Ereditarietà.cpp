#include<iostream>
#include<string>
using namespace std;

class persona{
	
	protected:
		string nome;
		
	public:
		persona(string nome){
			this->nome = nome;
		}
		
		string get_nome()const{
			return nome;
		}
};

class studente : public persona{
	private:
		string tipo;
		
	public:
		studente(string nome, string tipo) : persona(nome){
			this->tipo = tipo;
	    }
		string get_tipo()const{
			return tipo;
		}
		//Overriding
		string get_nome(){
			cout<<"Overriding"<<endl;
			return nome;
		}
};

int main(){
	
    studente s("Alfio", "Universitario");
    cout<<s.get_tipo()<<endl;
    cout<<s.get_nome()<<endl;
    cout<<s.persona::get_nome()<<endl;
}