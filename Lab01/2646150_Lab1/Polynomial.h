/**
@File Executive.cpp
Has all the constructors and methods of poly
@author Young Liu
@date Sept. 18 2013
*/

#include <iostream>
#include <fstream>

const int MAX_DEGREE = 20; //sets the max number for degree

class Polynomial 
{
    private:
        double coeff[MAX_DEGREE + 1]; //ensures that does not run out of space
	int degree; 

    public:
	Polynomial(); //constructor
        Polynomial(int d, double i[]); //takes degree and coeff
        double evaluate(double x) const; //takes x to evaluate
        Polynomial add(Polynomial p2) const; //adds another poly
        void print(std::ostream &os) const; //prints
        Polynomial differentiate() const; //finds the first derivative
};
