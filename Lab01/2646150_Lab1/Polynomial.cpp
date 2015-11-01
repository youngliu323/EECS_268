/**
@File Polynomial.cpp
Executes the different things
@author Young Liu
@date Sept. 18 2013
*/
#include "Polynomial.h"
#include <iostream>
#include "math.h"

Polynomial::Polynomial()
{
	degree = 0;

	//sets all the junk data to 0
	for (int j = 0; j <= MAX_DEGREE; j++)
	{
		coeff[j] = 0;
	}
}

double Polynomial::evaluate(double x) const
{
	double a=0;

	for (int j=0; j<=MAX_DEGREE; j++)
	{
		//ensures previous number gets added to new number
		a = a + (coeff[j] * pow (x,j));
	}

	return a;
}

Polynomial::Polynomial(int d, double i[])
{
	degree = d;

	for (int j = 0; j <= MAX_DEGREE; j++)
	{
		coeff[j] = 0;
	}

	for (int j = 0; j <= d; j++)
	{ //sets all the coeff to its respective value
		coeff[j] = i[j];
	}
}

Polynomial Polynomial::add(Polynomial p2) const
{
	double c[MAX_DEGREE + 1];
	int d;

	if (degree > p2.degree)
	{ //checks to see which one is bigger
		d = degree;
	}
	else
	{
		d = p2.degree;
	}

	for (int i = 0; i <= MAX_DEGREE; i++)
	{
		c[i] = coeff[i] + p2.coeff[i];
	}

	Polynomial p3(d, c);
	return p3;
}

//prints the polynomial
void Polynomial::print(std::ostream &os) const
{
	//loop runs the max number of times
	for (int j=0; j<MAX_DEGREE; j++) 
	{
		//ensures that 0's don't get printed
		if (j==0)
		{
		//prints out those who don't have a variable
			os << coeff[j];
		}
		if (coeff[j] != 0)
		{
			if (j>0)
			{ 
				os << "+";
				//prints out those who do have variables
				os << coeff[j] << "x^" << j;
			}
	
		}
	}os << std::endl;
}

Polynomial Polynomial::differentiate() const
{
	double temp[MAX_DEGREE + 1];

	for (int j=0; j <= degree; j++)
	{
		//does the power rule
		temp[j]=coeff[j+1]*(j+1);
	}
	//degree minus one so everything is shifted over
	return Polynomial(degree - 1, temp);
}


