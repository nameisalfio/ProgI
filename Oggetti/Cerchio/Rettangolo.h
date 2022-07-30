class rettangolo {
	private:
		float base;
		float altezza;
	public:
		rettangolo(float b, float h){
			base = b;
			altezza = h;
		}
		
		double area(){
			return base*altezza;
		}
		
		double perimetro(){
			return 2*(base+altezza);
		}
};