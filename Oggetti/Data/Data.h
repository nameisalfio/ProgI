#ifndef DATA_H
#define DATA_H

class Data {
	private:
		int giorno;
		int mese;
		int anno;
	public:
		Data(int, int, int);
		void get_out();
		void set_mod(int, int , int);
		void val();
};

#endif