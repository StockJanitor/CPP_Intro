#ifndef CALCULATORH
#define CALCULATORH

class Calculator {
	public:	
	   // TODO: Declare default constructor
        Calculator();
	   // TODO: Declare member functions - 
	   //       Add(), Subtract(), Multiply(), Divide(), Clear(), GetValue()
        void Add(double a);
        void Subtract(double a);
        void Multiply(double a);
        void Divide(double a);
        void Clear();
        double GetValue();
        void Power(double a);
        void SquareRoot();
	
	private:
	   // TODO: Declare private data member - value
       double a;


};

#endif