class bagno {
	private:
		double n;
		double m;
		static int count ;
		
	public: 
	    bagno(double n, double m){
	    	this->n = n;
			this->m = m;
			count ++;
		}
		
		void calcola_superficie(){
			cout<<"La superficie del cesso e' :"<<n*m<<endl;
		}
		
		int num_bagno (){
			return count;
		}
};

int bagno::count = 0;