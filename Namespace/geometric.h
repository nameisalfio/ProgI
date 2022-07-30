namespace geometric {

    class Rectangle {
        double base;
        double height;
        public:
            Rectangle(double b, double h) :base(b), height(h) {}
            double area() {return base*height;}
    };
    
    class Square {
        double side;
        public:
            Square(double s) : side(s) {}
            double area() {return side*side;}
    };
    
    class Circle {
        double r;
        public:
            Circle(double _r): r(_r) {}
            double area() {return 3.14*r*r;}
    };

    int x=2;
}