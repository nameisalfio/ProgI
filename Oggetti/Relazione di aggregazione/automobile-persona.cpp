class Persona {
    string nome;
    string cognome;
    int eta;
    public:
        Persona(string n, string c, int e) : nome(n), cognome(c), eta(e) {}
};

class Automobile {
    string modello;
    Persona *proprietario;
    public:
        Automobile(string m, Persona *p) : modello(m), proprietario(p) {}
        void cambiaProprietario(Persona *p) {};
};

Persona p1("Mario", "Rossi", 23);
Persona p2("Giuseppe", "Verdi", 77);
Automobile a1("Ford Fiesta", &p1);
Automobile a2("Renault Captur", &p1);
a2.cambiaProprietario(&p2);

int main(){
	
}