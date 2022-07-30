/* Scrivere un metodo che prenda in input un parametro formale matrice M 
di dimensioni n × m di puntatori a stringhe, e che restituisca true se esiste
almeno una colonna in M che abbia un egual numero di stringhe palindrome di una
delle righe di M. */

#include <iostream>
#include <string>
#define n 2
#define m 2

using namespace std;

/*bool func (string***M){
	int col=0;
	int raw=0;
	bool palc = true;
	bool palr = true;
	
	for(int j=0; j<m; j++){
//		col = 0;
		for(int i=0; i<n; i++){
			if(M[i][j]){
				for(int x=0, y=(*M[i][j]).length()-1; x<y; x++, y--){
					if((*M[i][j])[x] != (*M[i][j])[y])
						palc = false;
				}
					if(palc)
						col++;
			}
		}
		for(int h=0; h<n; h++){
//			raw = 0;
			for(int k=0; k<m; k++){
				if(M[h][k]){
					for(int p=0, q=(*M[h][k]).length()-1; p<q; p++, q--){
						if((*M[h][k])[p] != (*M[h][k])[q])
							palr = false;
				    }
				    	if(palr)
				    		raw++;
				}
			}
			cout<<"Righe : "<<raw<<endl;
			cout<<"Colonne : "<<col<<endl;
			if(col == raw){
				return true;
			}
			else{
				col = 0;
				raw = 0;
			}
		}
	}

	return false;
}*/

bool func (string***M){
    string y;
    bool r=true;
    bool c=true;
    int contar=0, contac=0;
	for(int i=0 ; i< n ; i++){
        contar=0;
        for(int j=0 ; j<n ; j++){
            r=true;
            for(int x=0, y=(*M[i][j]).length()-1; x<y; x++, y--){
					if((*M[i][j])[x] != (*M[i][j])[y])  r=false;
            }
            if(r==true) contar++;
        }
        if(contar){
            for(int k=0 ; k< n ; k++){
                contac=0;
                for(int z=0 ; z<n ; z++){
                    c=true;
                    for(int x=0, y=(*M[z][k]).length()-1; x<y; x++, y--){
					if((*M[z][k])[x] != (*M[z][k])[y])  c=false;
                    }
                if(c==true) 
					contac++;
                }
                cout<<"Colonne : "<<contac<<endl;
                cout<<"Righe : "<<contar<<endl;
                if(contar == contac) 
					return true;
            
                 }
        }
    }
    return false;
}

int main(){
	string** *M = new string** [n];
	for(int i=0; i<n; i++){
		
		M[i] = new string* [m];
		for(int j=0; j<m; j++){
			
			M[i][j] = new string;
			cout<<"Inserisci una stringa : "<<endl;
			cin>>*M[i][j];
		}
	}
	
	bool esito = func (M);
	
	if(esito==true){
		cout<<"\nEsiste almeno una colonna che soddisfa il requisito "<<endl;
	}else{
		cout<<"\nNon esiste nemmeno una colonna che soddisfa il requisito "<<endl;
	}
	
}